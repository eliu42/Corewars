/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:03:52 by eliu              #+#    #+#             */
/*   Updated: 2018/05/24 00:08:58 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

/*
**	Takes 3 parameters. The first two must be indexes, the third one must be a register.
**	This operation modifies the carry and functions as follows:
**	ldi(3, %4, r1 ) reads IND_SIZE bytes from the address PC + 3 % IDX_MOD , 
**	adds 4 to this value.
**	The sum is named S. 
**	REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1.
**
**	Gerardo's notes:
**	let's put it on revision becuase of the shift handeling
*/

int		ft_ldi(t_vm *vm, t_champ *champ, t_process *process)
{
	int		temp;
	int		index;

	champ = NULL;
	if (ind(process, 0) && ind(process, 1) && reg(process, 2))
	{
		index = (process.arg.v[0] + process.arg.v[1]) % IND_MOD;
		temp = vm.memory[index];
		temp = temp << 8; // shift handeling - reading info
		temp = temp + vm.memory[index + 1];
		if ((process.regs[process.arg.v[2]] = temp) == 0)
		{
			process.carry = 1;
		}
		else
		{
			process.carry = 0;
		}
		return (0);
	}
	return (1);
}
