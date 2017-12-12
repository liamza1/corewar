/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:09:11 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:09:13 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strwlen(wchar_t *s)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] <= 0x7F)
			count += 1;
		else if (s[i] <= 0x7FF)
			count += 2;
		else if (s[i] <= 0xFFFF)
			count += 3;
		else
			count += 4;
		i++;
	}
	return (count);
}
