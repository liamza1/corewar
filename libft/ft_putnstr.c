/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:07:01 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:10:58 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, size_t n)
{
	if (!s)
		write(1, "(null)", 6);
	else
	{
		while (*s && n-- > 0)
			write(1, s++, 1);
	}
}