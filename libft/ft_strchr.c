/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 14:10:29 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:07:47 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] && s[i] != (char)c)
			i++;
		if (s[i] == (char)c)
			return ((char *)&s[i]);
	}
	return (NULL);
}
