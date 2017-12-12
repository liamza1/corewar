/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 16:24:56 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:09:02 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			len;

	if (!s)
		return ("");
	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	if (s[i] == '\0')
		return ("");
	while (s[len] && (s[len] == ' ' || s[len] == '\n' || s[len] == '\t'))
		len--;
	len++;
	str = (char *)ft_memalloc((len - i) + 1);
	if (str)
		str = ft_strsub(s, i, len - i);
	return (str);
}
