/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 10:51:15 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:04:55 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	chr;

	i = 0;
	src = (unsigned char*)s;
	chr = (unsigned char)c;
	while (i < n)
	{
		if (src[i] == chr)
		{
			return (src + i);
		}
		i++;
	}
	return (NULL);
}
