/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:35:51 by lstreak           #+#    #+#             */
/*   Updated: 2017/10/01 17:43:22 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

void		init_cmd(t_line *list, int nb, int lbl, char *str)
{
	t_cmd	*link;
	t_cmd	*tmp;

	tmp = list->line_final;
	link = ft_memalloc(sizeof(t_cmd));
	link->next = NULL;
	link->nb = nb;
	link->label_counter = lbl;
	link->label = ft_strdup(str);
	if (list->line_final == NULL)
	{
		list->line_final = link;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = link;
	}
}

t_op		*opcode(t_file *file, t_line *list, int i)
{
	t_op	*tab;
	char	*cmd;

	if (list->cmd[0])
	{
		if (is_label(list->cmd[0]) == 0)
			cmd = list->cmd[0];
		else if (list->cmd[1] && is_label(list->cmd[1]) == 0)
			cmd = list->cmd[1];
		else
			return (NULL);
		tab = find_struct(cmd);
		if (tab != NULL)
		{
			init_cmd(list, tab->code, -2, "");
			file->counter++;
			return (tab);
		}
		else
			asm_error("opcode", i);
	}
	else
		asm_error("opcode", i);
	return (NULL);
}

int			len_list(t_cmd *list)
{
	t_cmd	*tmp;
	int		i;

	i = 0;
	tmp = list;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int			handle_label(t_line *list, char *str, t_file *file)
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
