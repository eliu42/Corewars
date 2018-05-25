/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:06:43 by eliu              #+#    #+#             */
/*   Updated: 2018/05/24 22:55:02 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	I need to add a function that lets the function controller know that
**	a champion is alive due to the processes.
*/

int		ft_live(t_vm *vm, t_champ *champ, t_process *process)
{
	(void)vm;
	(void)champ;
	if (dir(process, 0))
	{
		process->live = process->arg.v[0];
		// process->index += args_size;
		// process->index += 5;
		return (0);
	}
	return (1);
}
