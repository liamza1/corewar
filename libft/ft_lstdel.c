/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:01:20 by tmaske            #+#    #+#             */
/*   Updated: 2017/11/29 11:04:29 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*keep_track;
	t_list		*tracked;

	if (!alst || !*alst)
		return ;
	tracked = *alst;
	while (tracked)
	{
		keep_track = tracked->next;
		ft_lstdelone(&tracked, del);
		tracked = keep_track;
	}
	*alst = NULL;
}
