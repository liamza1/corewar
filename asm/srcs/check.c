/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lstreak <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/29 11:34:37 by lstreak           #+#    #+#             */
/*   Updated: 2017/09/29 16:47:52 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

int			is_label(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len > 0)
	{
		if (str[len - 1] == LABEL_CHAR)
			return (1);
	}
	return (0);
}

int			is_index_func(char *str)
{
	if (ft_match(str, "zjmp") == 1)
		return (4);
	if (ft_match(str, "fork") == 1)
		return (4);
	if (ft_match(str, "lfork") == 1)
		return (4);
	if (ft_match(str, "lldi") == 1)
		return (3);
	if (ft_match(str, "sti") == 1)
		return (2);
	if (ft_match(str, "ldi") == 1)
		return (3);
	return (0);
}

static int	is_labels_char(char c, char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

void		verif_lbl_char(char *str)
{
	int		i;
	char	*str1;
	char	*str2;

	i = 0;
	str1 = ft_strdup(LABEL_CHARS);
	str2 = ft_strdup(str);
	str2[ft_strlen(str2) - 1] = 0;
	while (str2[i])
	{
		if (is_labels_char(str2[i], str1) == 0)
			ft_putstr("asm-error: invalid character in label\n");
		i++;
	}
	ft_strdel(&str1);
	ft_strdel(&str2);
}
