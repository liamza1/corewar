/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binaries.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:34:27 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 16:45:37 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					bin_to_int(char *str)
{
	unsigned long	i;
	int				p;
	int				res;

	res = 0;
	i = 0;
	p = ft_strlen(str) - 1;
	while (i <= ft_strlen(str) - 1)
	{
		if (str[i] == '1')
		{
			res = res + ft_pow(2, p);
		}
		p--;
		i++;
	}
	return (res);
}

static void			put_bin(char *bin, char *puts)
{
	int				size;

	size = ft_strlen(bin);
	if (size + 1 <= 7)
	{
		bin[size] = puts[0];
		bin[size + 1] = puts[1];
	}
}

static void			put_desc(t_file *file, t_line *list, char *bin)
{
	int				code;

	code = bin_to_int(bin);
	init_cmd(list, code, -2, "");
	file->counter += 1;
}

void				des_param(t_file *file, t_line *list, int line, t_op *ope)
{
	int				i;
	char			bin[9];

	init_str(bin, 9);
	verify_params(list, line, ope);
	if (ope->code != 1 && ope->code != 9 && ope->code != 12 && ope->code != 15)
	{
		i = 1;
		if (list && list->cmd && list->cmd[0] && is_label(list->cmd[0]))
			i++;
		while (list && list->cmd && list->cmd[i])
		{
			if (list->cmd[i][0] == DIRECT_CHAR)
				put_bin(bin, "10");
			else if (list->cmd[i][0] == 'r')
				put_bin(bin, "01");
			else
				put_bin(bin, "11");
			i++;
		}
		i = ft_strlen(bin);
		while (i <= 7)
			bin[i++] = '0';
		put_desc(file, list, bin);
	}
}
