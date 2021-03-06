/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarrsml_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/19 17:38:34 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:03:52 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_iarrsml_pos(int *arr, int len)
{
	int i;
	int temp;
	int temp_pos;

	i = 0;
	temp = 2147483647;
	while (i < len)
	{
		if (arr[i] < temp)
		{
			temp = arr[i];
			temp_pos = i;
		}
		i++;
	}
	return (temp_pos);
}
