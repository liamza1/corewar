/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_from_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 02:24:22 by hmthimun          #+#    #+#             */
/*   Updated: 2017/09/29 14:24:33 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		get_int_from_bytes(t_vm *vm, t_process *process, int addr)
{
	int		i;
	long	value;
	int		result[4];

	i = 0;
	while (i < 4)
	{
		result[i] = vm->memory[ft_loop_memory(process->pc + addr + i)];
		i++;
	}
	value = (256L * 256L * 256L * result[0]) + (256L * 256L * result[1])
		+ (256L * result[2]) + result[3];
	return ((int)value);
}

int		get_int_from_two_bytes(t_vm *vm, t_process *process, int addr)
{
	int		i;
	long	value;
	int		result[2];

	i = 0;
	while (i < 2)
	{
		result[i] = vm->memory[ft_loop_memory(process->pc + addr + i)];
		i++;
	}
	value = 256L * result[0] + result[1];
	if (value > (256 * 256) / 2)
		value -= 256 * 256;
	return ((int)value);
}
