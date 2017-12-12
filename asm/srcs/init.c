/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:36:13 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 17:05:20 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		init_file(t_file *file, char *str)
{
	file->lines = NULL;
	file->label = NULL;
	file->filename = ft_strdup(str);
	file->new_file = NULL;
	file->fd_file = open(str, O_RDONLY);
	file->counter = 0;
	if (file->fd_file == -1)
	{
		ft_putendl("Error on OPEN");
		exit(1);
	}
}

void		init_line(t_file *file, char *line)
{
	t_line	*data;
	t_line	*tmp;

	data = ft_memalloc(sizeof(t_line));
	data->line = ft_strdup(line);
	data->cmd = NULL;
	data->line_final = NULL;
	data->next = NULL;
	tmp = file->lines;
	if (file->lines == NULL)
	{
		data->prev = NULL;
		file->lines = data;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		data->prev = tmp;
		tmp->next = data;
	}
}

void		init_label(t_file *file, char *label)
{
	t_label	*data;
	t_label	*tmp;

	tmp = file->label;
	data = ft_memalloc(sizeof(t_label));
	data->next = NULL;
	data->label = ft_strdup(label);
	data->label[ft_strlen(data->label) - 1] = 0;
	data->counter = file->counter;
	if (file->label == NULL)
	{
		file->label = data;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = data;
	}
}

void		init_str(char *str, int size)
{
	int		i;

	i = 0;
	while (str && i < size)
	{
		str[i] = 0;
		i++;
	}
}

void		init_header(t_header *head)
{
	head->magic = COREWAR_EXEC_MAGIC;
	init_str(head->prog_name, PROG_NAME_LENGTH + 1);
	init_str(head->comment, COMMENT_LENGTH + 1);
	head->prog_size = -1;
}
