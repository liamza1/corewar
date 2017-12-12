/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 01:16:09 by hmthimun          #+#    #+#             */
/*   Updated: 2017/09/29 14:16:24 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		put_hex(unsigned char c)
{
	size_t h1;
	size_t h2;

	h1 = c / 16;
	h2 = c - (h1 * 16);
	write(1, &"0123456789abcdef"[h1], 1);
	write(1, &"0123456789abcdef"[h2], 1);
}

void			hexdump(unsigned char *data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		put_hex(data[i]);
		i++;
		if (i % 32 == 0)
			ft_putstr(" \n");
		else
			ft_putchar(' ');
	}
}
