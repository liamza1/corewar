/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 15:55:44 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:08:12 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!f || !s)
		return (NULL);
	i = 0;
	str = (char *)ft_memalloc(ft_strlen(s) + 1);
	if (str)
	{
		while (s[i])
		{
			str[i] = f(i, (char)s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
