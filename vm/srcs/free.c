/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:23:12 by hmthimun          #+#    #+#             */
/*   Updated: 2017/09/29 14:26:07 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		free_first(t_vm *vm, t_process **tmp)
{
	vm->process = (*tmp)->next;
	free(*tmp);
	*tmp = NULL;
	if (!vm->process)
		ft_finish(vm);
	*tmp = vm->process;
	(*tmp)->prev = NULL;
}

void		free_middle(t_process **tmp)
{
	t_process	*to_free;

	(*tmp)->prev->next = (*tmp)->next;
	(*tmp)->next->prev = (*tmp)->prev;
	to_free = *tmp;
	*tmp = (*tmp)->next;
	free(to_free);
	to_free = NULL;
}

void		free_last(t_process **tmp)
{
	(*tmp)->prev->next = NULL;
	free(*tmp);
	*tmp = NULL;
}
