/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:35:02 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 16:49:29 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	add_info(t_file *file, t_line *list, int opt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (opt == 0)
	{
		while (list->line[i] && list->line[i] != 34)
			i++;
		i++;
		while (list->line[i] && list->line[i] != 34)
			file->header->prog_name[j++] = list->line[i++];
	}
	else
	{
		while (list->line[i] && list->line[i] != 34)
			i++;
		i++;
		while (list->line[i] && list->line[i] != 34)
			file->header->comment[j++] = list->line[i++];
	}
}

static void	complete_header(t_file *file)
{
	t_line	*list;

	list = file->lines;
	while (list)
	{
		if (beg_match(list->line, NAME_CMD_STRING))
		{
			if (ft_strlen(list->line) <= PROG_NAME_LENGTH)
				add_info(file, list, 0);
			else
				ft_putstr("asm-error: Name too long\n");
		}
		if (beg_match(list->line, COMMENT_CMD_STRING))
		{
			if (ft_strlen(list->line) <= COMMENT_LENGTH)
				add_info(file, list, 1);
			else
				ft_putstr("asm-error: Comment too long\n");
		}
		list = list->next;
	}
}

void		write_header(t_file *file, int fd)
{
	complete_header(file);
	file->header->prog_size = file->counter;
	file->header->prog_size = convert_int(file->header->prog_size);
	file->header->magic = convert_int(file->header->magic);
	if (write(fd, file->header, sizeof(t_header)) == -1)
		ft_putstr("asm-error: Impossible to write header\n");
}
