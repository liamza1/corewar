/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:35:42 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 16:54:55 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static void	free_char_dbl(char **str)
{
	int		i;

	i = 0;
	while (str && str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	ft_strdel(str);
}

static void	free_lbl(t_label *begin)
{
	t_label	*tmp;

	while (begin)
	{
		ft_strdel(&begin->label);
		tmp = begin;
		begin = begin->next;
		free(tmp);
	}
}

static void	free_lines(t_line *list)
{
	t_line	*tmp;
	t_cmd	*intl;
	t_cmd	*tmp2;

	while (list)
	{
		free_char_dbl(list->cmd);
		intl = list->line_final;
		ft_strdel(&list->line);
		free(list->cmd);
		while (intl)
		{
			tmp2 = intl;
			ft_strdel(&intl->label);
			intl = intl->next;
			free(tmp2);
		}
		tmp = list;
		list = list->next;
		free(tmp);
	}
}

void		free_all(t_file *file)
{
	free_lbl(file->label);
	ft_strdel(&file->filename);
	ft_strdel(&file->new_file);
	free(file->header);
	free_lines(file->lines);
	free(file);
}
