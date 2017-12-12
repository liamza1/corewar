/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zaz <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by zaz               #+#    #+#             */
/*   Updated: 2017/10/01 17:42:48 by lstreak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <asm.h>

t_op		g_op_tab[] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive"},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load"},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store"},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition"},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction"},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3"},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3"},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3"},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero"},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index"},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index"},
	{"fork", 1, {T_DIR}, 12, 800, "fork"},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load"},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index"},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork"},
	{"aff", 1, {T_REG}, 16, 2, "aff"},
	{0, 0, {0}, 0, 0, 0}
};

int			beg_match(char *str1, char *str2)
{
	int		i;

	i = 0;
	while (str1[i] && str2[i])
	{
		if (str1[i] != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int			convert_int(int i)
{
	char	tmp;
	char	*s;

	s = (char *)&i;
	tmp = s[3];
	s[3] = s[0];
	s[0] = tmp;
	tmp = s[2];
	s[2] = s[1];
	s[1] = tmp;
	return (i);
}

int			ft_getnbr(char *str)
{
	int		pos;
	int		signe;
	int		nbr;

	pos = 0;
	signe = 1;
	while (str[pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
	{
		if (str[pos] == '-')
			signe = signe * -1;
		pos++;
	}
	str = str + pos;
	pos = 0;
	nbr = 0;
	while (str[pos] >= '0' && str[pos] <= '9')
	{
		nbr = nbr * 10;
		nbr = nbr - (str[pos] - 48);
		pos++;
	}
	return (nbr * signe * -1);
}

void		asm_error(char *type, int line)
{
	ft_putstr("asm-error: Invalid ");
	ft_putstr(type);
	ft_putstr(" on line ");
	ft_putnbr(line);
	ft_putstr(".\n");
	exit(EXIT_FAILURE);
}
