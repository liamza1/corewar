/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 18:03:26 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:03:05 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_arrprint(char **arr)
{
	int i;

	i = 0;
	if (arr && *arr)
	{
		while (arr[i])
		{
			ft_putendl(arr[i]);
			i++;
		}
	}
}
