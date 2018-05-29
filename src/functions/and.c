/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 04:31:44 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 00:59:58 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

/*
**	Takes 3 parameters. It performs a binary AND '&' between the two parameters 
**	and stores the result into the third one (which must be a register).
**	This operation modifies the carry.
**	and(r2, %0, r3) puts r2 & 0 into r3.
*/

int		ft_and(t_vm *vm, t_champ *champ, t_process *process)
{
	int 	jndex;

	jndex = process->index + 1;
	if (g_ops[process->curr_op].descriptor == 1)
	{
		jndex += 1;
	}
	ft_putendl("	entered ft_and");
	(void)vm;
	(void)champ;
	if (any(process, 0) && any(process, 1) && reg(process, 2))
	{
		store_values(vm, process, jndex, 3);
		convert_if_register_number_to_value(process, 0);
		convert_if_register_number_to_value(process, 1);
		if ((process->regs[process->arg.v[2]] = \
			(process->arg.v[0] & process->arg.v[1])/* % IDX_MOD */) == 0)
		{
			process->carry = 1;
		}
		else
		{
			process->carry = 0;
		}
		printf("carry is :%d\n", process->carry);
		ft_putendl("	exited ft_and with return 0");
		return (0);
	}
	ft_putendl("	exited ft_and with return 1");
	return (1);
}
