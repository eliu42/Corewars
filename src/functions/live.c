/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:06:43 by eliu              #+#    #+#             */
/*   Updated: 2018/06/02 14:58:13 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	I need to add a function that lets the function controller know that
**	a champion is alive due to the processes.
*/
/*
static void	last_to_live(t_vm *vm, int player)
{
	vm->last_to_live = player;
}
*/

static void	show_alive(t_process *process)
{
	ft_printf("A process shows that Player %d (%s) is alive.\n", \
				process->player_alive, "process->name");
}

int			ft_live(t_vm *vm, t_champ *champ, t_process *process)
{
	(void)champ;
	ft_putendl("ft_live:");
	read_4_bytes(vm, process, process->index + 1, 0);
	process->process_alive = 1;
	process->player_alive = process->arg.v[0];

	if (-4 <= process->arg.v[0] && process->arg.v[0] <= -1)
		vm->last_to_live = process->arg.v[0];
	printf("vm->last_live = %d <-------- MODIFYED PENDEJADA\n", process->arg.v[0]);
	vm->total_lives += 1;
	printf("Total_lives so far = %d\n", vm->total_lives);
	printf("The latest player to call live is player: |%d|\n", vm->last_to_live);
	show_alive(process);
	return (1);
}
