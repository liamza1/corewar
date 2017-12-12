/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/16 13:58:46 by hmthimun          #+#    #+#             */
/*   Updated: 2017/10/01 17:23:43 by hmthimun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			set_champion_number(t_vm *vm, int max)
{
	int		i;

	i = 0;
	max = vm->champ_nb;
	while (i < vm->champ_nb)
	{
		if (vm->champions[i].number == -1)
			vm->champions[i].number = max;
		if (vm->champions[i].number <= 0)
			ft_error("Error: bad argument for -n");
		i++;
		max--;
	}
}

void			check_champion_number(t_vm *vm)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (i < vm->champ_nb)
	{
		j = 0;
		if (vm->champions[i].number > max)
			max = vm->champions[i].number;
		while (j < vm->champ_nb)
		{
			if (vm->champions[i].number == vm->champions[j].number && i != j
					&& vm->champions[j].number != -1)
				ft_error("Error: same number for champions");
			j++;
		}
		i++;
	}
	set_champion_number(vm, max);
}

static void		introduce_champs(t_vm *vm)
{
	int		i;

	i = 0;
	ft_putendl("Welcome to the stage...");
	while (i < vm->champ_nb)
	{
		ft_putstr("* Player ");
		ft_putnbr(vm->champions[i].number);
		ft_putstr(": ");
		ft_putstr(vm->champions[i].name);
		ft_putstr(" ##***> ");
		ft_putstr(vm->champions[i].comment);
		ft_putendl(" <***## !");
		i++;
	}
}

int				main(int argc, char **argv)
{
	t_vm		vm;

	init_vm(&vm);
	check_errors(argc, argv);
	check_cor_files(argc, argv);
	get_vm(&vm, argv, argc);
	check_champion_number(&vm);
	load_champions(&vm);
	introduce_champs(&vm);
	start_running_vm(&vm);
	return (0);
}
