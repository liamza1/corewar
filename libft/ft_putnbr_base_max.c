/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_max.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:06:22 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:06:23 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_base_bis(uintmax_t nbr, char *base, size_t base_len)
{
	if (nbr >= base_len)
	{
		ft_putnbr_base_bis(nbr / base_len, base, base_len);
		ft_putnbr_base_bis(nbr % base_len, base, base_len);
	}
	else
		ft_putchar(base[nbr]);
}

void			ft_putnbr_base_max(uintmax_t nbr, char *base)
{
	ft_putnbr_base_bis(nbr, base, ft_strlen(base));
}
