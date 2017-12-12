/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 10:28:36 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:04:03 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isdigit_str(char *str)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (ft_isdigit(str[i]) != 1)
			return (-1);
		i++;
	}
	return (1);
}
