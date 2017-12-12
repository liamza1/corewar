/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:05:13 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:05:15 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_nbrlen(long nb, long base)
{
	long	length;

	length = 1;
	while (ft_power_long(base, length) <= nb)
		length++;
	return (length);
}
