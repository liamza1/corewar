/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_label.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:35:28 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 17:44:46 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

static	void		fill_label_list(t_cmd *list, int nb)
{
	int				i;
	unsigned char	*str;

	i = 1;
	str = (unsigned char *)&nb;
	if (list)
		list->nb = (unsigned char)str[i];
	i--;
	if (list->next)
	{
		list->next->nb = (unsigned char)str[i];
		list->next->label_counter = -2;
	}
}

static void			comp_label(t_file *file, t_cmd *byte)
{
	t_label			*lbl;
	int				nb;

	nb = 0;
	lbl = file->label;
	while (lbl)
	{
		if ((lbl) && (lbl->label) && byte && (byte->label))
		{
			if (ft_match(lbl->label, byte->label))
			{
				nb = (lbl->counter) - (byte->label_counter);
				fill_label_list(byte, nb);
				return ;
			}
		}
		lbl = lbl->next;
	}
	ft_putstr("asm-error: Invalid label (");
	ft_putendl(byte->label);
}

int					byte_size(t_line *list, char *str, t_file *file)
{
	if (str[0] == 'r')
		return (handle_reg(list, str, file));
	else if (str[0] == DIRECT_CHAR)
	{
		if (str[1] == LABEL_CHAR)
			return (handle_lbl(list, str, file));
		else
			return (handle_dir(list, str, file));
	}
	else if (str[0] == LABEL_CHAR)
		return (handle_lbl(list, str, file));
	else if (((str[0] >= '0') && (str[0] <= '9')) || (str[0] == '-'))
		return (handle_ind(list, str, file));
	return (0);
}

int					fill_nb_in_list(t_line *list, t_file *file)
{
	int				a;
	int				i;

	i = 0;
	a = 1;
	if (is_label(list->cmd[0]) == 1)
		i++;
	while ((list) && (list->cmd) && (list->cmd[a]))
	{
		if (is_index_func(list->cmd[i]) == 2)
			return (handle_sti(list, list->cmd, file, i));
		else if (is_index_func(list->cmd[i]) == 3)
			return (handle_ldi(list, list->cmd, file, i));
		else if (is_index_func(list->cmd[i]) == 4)
			return (hndl_frk_zjp(list, list->cmd, file, i));
		else if (is_index_func(list->cmd[i]) == 1)
			return (handle_ind(list, list->cmd[a], file));
		else if (is_index_func(list->cmd[i]) == 0)
			byte_size(list, list->cmd[a], file);
		a++;
		i++;
	}
	return (0);
}

void				fill_label(t_file *file)
{
	t_line			*line;
	t_cmd			*byte;

	line = file->lines;
	while (line)
	{
		byte = line->line_final;
		while (byte)
		{
			if (byte->label_counter != -2)
				comp_label(file, byte);
			byte = byte->next;
		}
		line = line->next;
	}
}
