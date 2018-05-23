/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 05:03:52 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 14:26:34 by eliu             ###   ########.fr       */
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
*/

void	ft_ldi_cylces(t_process *process)
{
	process->cycle_counter = 25;
}

// Encoding byte exists!
// Truncating byte exists!

void	ft_ldi(t_process *process)
{
	char	temp;

	if (ind(process) && ind(process) && reg(process))
	{
		temp = process->arg.v[0] + process->arg.v[1];
		process->arg.v[2] = vm[process->pc + temp];
		// Reads IND_SIZE bytes at addres (PC + v[0] % INX_MOD);
		// Takes above value and adds v[1];
		// Reads REG_SIZE bytes at addres (PC + S % IND_MOD);
		// v[3] == Above value.
	}
}

/*
t_process		*ft_ldi(char first, char second, char third)
{
	char		carry;
	t_process	*process;

	process = NULL;
	// If first and second paramters are index && third parameter is a register:
	// {
			read_value = 0;
	// S = read_index_size(address_of(PC) + address_of_value(first % IND_MOD));
	read_value = read_index_size(address_of(PC) + address_of_value(first % IND_MOD));
		

	value_at_address_(third) = read_copy(address_of(PC) + S % IND_MOD);

	// }
	
	//	process->carry = 1 ? 0 : 1;
	carry = 1 ? 0 : 1;
	return (process);
}
*/
