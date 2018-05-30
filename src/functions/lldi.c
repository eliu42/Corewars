/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 06:11:20 by eliu              #+#    #+#             */
/*   Updated: 2018/05/30 04:19:20 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Similar to ldi without the %IDX_MOD. This operation modifies the carry.
*/

/*
**	t_process		*ldi(char first, char second, char third);
**	Takes 3 parameters. The first two must be indexes, the third one must be a register.
**	This operation modifies the carry and functions as follows:
**	ldi(3, %4, r1 ) reads IND_SIZE bytes from the address PC + 3 % IDX_MOD , 
**	adds 4 to this value.
**	The sum is named S. 
**	REG_SIZE bytes are read from the address PC + S % IDX_MOD and copied into r1.
*/

int		ft_lldi(t_vm *vm, t_champ *champ, t_process* process)
{
	int 	s;
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("ft_lldi");

	(void)vm;
	(void)champ;
	if (any(process, 0) && reg_dir(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		if (reg(process, 0) && reg_bounds(process->arg.v[0]))
			return (1);
		if (reg(process, 1) && reg_bounds(process->arg.v[1]))
			return (1);
		convert_if_register_number_to_value(process, 0);
		convert_if_register_number_to_value(process, 1);
		s = process->arg.v[0] + process->arg.v[1];
		s = circulate_index(s);
		read_4_bytes(vm, process, s, 2);
		if (process->regs[process->arg.v[2]] == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		printf("process carry is: |%d|\n", process->carry);
		return (0);
	}
	ft_putendl("ft_lldi did not execute");
	return (1);
}
