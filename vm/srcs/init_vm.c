/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 14:00:21 by hmthimun          #+#    #+#             */
/*   Updated: 2017/11/15 04:26:52 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		init_champ(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		vm->champions[i].name = NULL;
		vm->champions[i].comment = NULL;
		vm->champions[i].data = NULL;
		vm->champions[i].number = -1;
		vm->champions[i].live = 0;
		i++;
	}
}

void		init_vm(t_vm *vm)
{
	int		i;

	i = 0;
	vm->dump_cycle = -1;
	vm->champ_nb = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->lives_in_current_period = 0;
	vm->cycle_in_current_period = 0;
	vm->last_champion_alive_number = 0;
	while (i < MEM_SIZE)
		vm->memory[i++] = 0;
	init_champ(vm);
}
