/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnwstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 11:07:22 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:07:23 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnwstr(wchar_t *str, size_t n)
{
	if (!str)
		write(1, "(null)", 6);
	while (*str && n-- > 0)
	{
		ft_putwchar(*str);
		str++;
	}
}
