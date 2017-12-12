/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_check_state.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 22:21:20 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/29 11:40:38 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

static void		ft_print(t_vm *vm, int i)
{
	ft_putstr("Player ");
	ft_putnbr(vm->champions[i].number);
	ft_putstr(" (");
	ft_putstr(vm->champions[i].name);
	ft_putendl(") has won ");
}

void			ft_finish(t_vm *vm)
{
	int		i;

	i = 0;
	if (vm->champ_nb < 2)
	{
		ft_putstr("Player ");
		ft_putnbr(vm->last_champion_alive_number);
		ft_putstr(" (");
		ft_putstr(vm->last_champion_alive_name);
		ft_putendl(") has won ");
	}
	else
	{
		while (i < vm->champ_nb)
		{
			if (vm->champions[i].number == vm->last_champion_alive_number)
				ft_print(vm, i);
			i++;
		}
	}
	exit(0);
}

static void		ft_check_process(t_vm *vm)
{
	t_process	*tmp;

	tmp = vm->process;
	if (!tmp)
		ft_finish(vm);
	while (tmp)
	{
		if (tmp->live == 0)
		{
			if (tmp->prev == NULL)
				free_first(vm, &tmp);
			else if (tmp->next == NULL)
			{
				free_last(&tmp);
				return ;
			}
			else
				free_middle(&tmp);
		}
		else
		{
			tmp->live = 0;
			tmp = tmp->next;
		}
	}
}

void			ft_check_alive(t_vm *vm)
{
	static int	checks_without_decrementing = 0;

	checks_without_decrementing++;
	ft_check_process(vm);
	if (vm->lives_in_current_period >= NBR_LIVE ||
			checks_without_decrementing >= MAX_CHECKS)
	{
		vm->cycle_to_die -= CYCLE_DELTA;
		checks_without_decrementing = 0;
	}
	vm->lives_in_current_period = 0;
	vm->cycle_in_current_period = 0;
	if (vm->process == NULL)
		ft_finish(vm);
}
