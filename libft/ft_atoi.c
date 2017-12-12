/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 14:29:13 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:03:27 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int i;
	int done;
	int flag;

	done = 0;
	i = 0;
	flag = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v' || nptr[i]
			== '+' || nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\n')
		i++;
	if (nptr[i] == '-')
	{
		flag++;
		i++;
	}
	while (nptr[i] > 47 && nptr[i] < 58)
	{
		done = ((done * 10) + nptr[i]) - '0';
		i++;
	}
	if (flag == 1)
		done = done * -1;
	return (done);
}
