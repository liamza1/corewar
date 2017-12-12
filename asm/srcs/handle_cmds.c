/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:35:57 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 17:00:10 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int					detect_label_in_str(char *str)
{
	if (str[0] == LABEL_CHAR)
		return (1);
	if ((str[0] == DIRECT_CHAR) && (str[1] == LABEL_CHAR))
		return (1);
	return (0);
}

void				putchar_int(t_line *list, int nb, int size, t_file *file)
{
	int				i;
	int				j;
	unsigned char	*str;

	i = 0;
	j = size - 1;
	str = (unsigned char *)&nb;
	while (i < size)
	{
		init_cmd(list, str[j], -2, "");
		file->counter++;
		i++;
		j--;
	}
}

int					handle_reg(t_line *list, char *str, t_file *file)
{
	int				nb;

	nb = 0;
	if (detect_label_in_str(str) == 1)
		return (handle_lbl(list, str, file));
	if (ft_strlen(str) > 1)
		nb = ft_getnbr(str + 1);
	putchar_int(list, nb, 1, file);
	return (1);
}

int					handle_dir(t_line *list, char *str, t_file *file)
{
	int				nb;

	nb = 0;
	if (detect_label_in_str(str) == 1)
		return (handle_lbl(list, str, file));
	if (ft_strlen(str) > 1)
		nb = ft_getnbr(str + 1);
	putchar_int(list, nb, DIR_SIZE, file);
	return (1);
}

int					handle_ind(t_line *list, char *str, t_file *file)
{
	int				nb;

	if (detect_label_in_str(str) == 1)
		return (handle_lbl(list, str, file));
	if (str[0] == DIRECT_CHAR || str[0] == 'r')
		nb = ft_getnbr(str + 1);
	else
		nb = ft_getnbr(str);
	if (nb >= IDX_MOD)
		ft_putstr("asm-error: indirection is too high\n");
	putchar_int(list, nb, IND_SIZE, file);
	return (1);
}
