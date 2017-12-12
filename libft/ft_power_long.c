/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_long.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:05:22 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:10:58 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_power_long(long nb, long pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (0);
	return (nb * ft_power(nb, pow - 1));
}
