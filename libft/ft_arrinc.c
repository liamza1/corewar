/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrinc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:01:45 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:03:00 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrinc(char ***a, char *str, int len)
{
	int		i;
	char	**new;
	char	**arr;

	arr = *a;
	new = (char**)ft_memalloc(sizeof(char*) * (len + 2));
	i = 0;
	while (i < len)
	{
		new[i] = arr[i];
		i++;
	}
	new[len] = ft_strdup(str);
	new[len + 1] = NULL;
	if (a && arr)
		free(*a);
	*a = new;
}
