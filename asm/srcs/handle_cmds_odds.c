/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds_odds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:36:04 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 17:02:57 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int		handle_ldi(t_line *list, char **str, t_file *file, int i)
{
	if (str[i + 1][0] == 'r')
		handle_reg(list, str[i + 1], file);
	else
		handle_ind(list, str[i + 1], file);
	if (str[i + 2][0] == 'r')
		handle_reg(list, str[i + 2], file);
	else
		handle_ind(list, str[i + 2], file);
	byte_size(list, str[i + 3], file);
	return (1);
}

int		handle_sti(t_line *list, char **str, t_file *file, int i)
{
	byte_size(list, str[i + 1], file);
	if (str[i + 2][0] == 'r')
		handle_reg(list, str[i + 2], file);
	else
		handle_ind(list, str[i + 2], file);
	if (str[i + 3][0] == 'r')
		handle_reg(list, str[i + 3], file);
	else
		handle_ind(list, str[i + 3], file);
	return (1);
}

int		handle_lbl(t_line *list, char *str, t_file *file)
{
	int		len;

	len = len_list(list->line_final);
	if (str[0] == DIRECT_CHAR)
		str = str + 1;
	if (str[0] == LABEL_CHAR)
		str = str + 1;
	init_cmd(list, 255, file->counter - len, str);
	file->counter++;
	init_cmd(list, 255, file->counter - len, str);
	file->counter++;
	return (1);
}

int		hndl_frk_zjp(t_line *list, char **str, t_file *file, int i)
{
	handle_ind(list, str[i + 1], file);
	return (1);
}
