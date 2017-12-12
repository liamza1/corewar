/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:36:22 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 18:29:26 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int				is_to_parse(t_line *list)
{
	if (list && list->line[0] == COMMENT_CHAR)
		return (0);
	if (list && beg_match(list->line, NAME_CMD_STRING) == 1)
		return (0);
	if (list && beg_match(list->line, COMMENT_CMD_STRING) == 1)
		return (0);
	return (1);
}

void			verify_params_type(t_line *list, int line, t_op *ope)
{
	t_args_type	current;
	t_args_type	result;
	int			i;
	int			j;

	i = 1;
	j = 0;
	if (list && list->cmd && list->cmd[0] && is_label(list->cmd[0]))
		i++;
	while (list && list->cmd && list->cmd[i] && ope->type[j])
	{
		if (list->cmd[i][0] == DIRECT_CHAR)
			current = T_DIR;
		else if (list->cmd[i][0] == 'r')
			current = T_REG;
		else
			current = T_IND;
		result = current & ope->type[j];
		if (result == 0)
			asm_error("argument (Bad number)", line);
		j++;
		i++;
	}
}

void			verify_params(t_line *list, int line, t_op *ope)
{
	int			i;
	int			j;

	j = 0;
	i = -1;
	if (is_label(list->cmd[0]) == 1)
		i -= 1;
	while (list->cmd[j])
		j++;
	i = i + j;
	if (i != ope->nbr_args)
		asm_error("argument (Bad number)", line);
	verify_params_type(list, line, ope);
}

void			parse(t_file *file)
{
	int			i;
	t_line		*list;
	t_op		*ope;

	i = 1;
	list = file->lines;
	while (list)
	{
		if (is_to_parse(list) == 1)
		{
			list->cmd = put_cmd_in_list(list->line);
			generate_fixed_label(file, list);
			ope = opcode(file, list, i);
			if (ope != NULL)
			{
				des_param(file, list, i, ope);
				fill_nb_in_list(list, file);
			}
		}
		list = list->next;
		i++;
	}
	fill_label(file);
}
