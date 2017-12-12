/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 12:45:49 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:07:55 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *d;

	d = (char*)ft_memalloc(ft_strlen(s) + 1);
	if (!d)
		return (NULL);
	d = ft_strcpy(d, s);
	return (d);
}
