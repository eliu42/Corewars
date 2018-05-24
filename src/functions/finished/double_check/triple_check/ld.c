/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 03:08:54 by eliu              #+#    #+#             */
/*   Updated: 2018/05/23 20:45:53 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Loads the value of the first parameter into the second parameter,
**	which must be a register (not the PC). This operation modiefies the carry.
**	ld(34, r3) loads the REG_SIZE bytes (4 bytes aka int) starting at the address PC
**	PC + 34 % IND_MOD into r3. 5 cycles.
*/

void	ft_ld(t_process *process)
{
	if (dir_ind(process, 0) && reg(process, 1))
	{
		if ((process->reg[process->v[1]] = process->arg.v[0]) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
	}
}
