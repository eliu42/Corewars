/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 23:35:02 by eliu              #+#    #+#             */
/*   Updated: 2018/05/29 23:21:04 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	read_4_bytes(t_vm *vm, t_process *process, int index, int i)
{
	ft_putendl("	arg is an indirect: entered read_4_bytes");
	process->arg.v[i] = (vm->memory[circulate_index(index)] & 0xFF) << 24;
	process->arg.v[i] += (vm->memory[circulate_index(index + 1)] & 0xFF) << 16;
	process->arg.v[i] += (vm->memory[circulate_index(index + 2)] & 0xFF) << 8;
	process->arg.v[i] += (vm->memory[circulate_index(index + 3)] & 0xFF);
	ft_putendl("	exited read_4_bytes");
}

void 	read_2_bytes(t_vm *vm, t_process *process, int index, int i)
{
	printf("	arg is an indirect: entered read_2_bytes index = %d\n", index);
	process->arg.v[i] = vm->memory[circulate_index(index)];
	process->arg.v[i] = (process->arg.v[i] & 0xFF) << 8; //cast to char
	process->arg.v[i] += vm->memory[circulate_index(index + 1)] & 0xFF;
	printf("i value = %d shift = %d\n", i, process->arg.v[i]);
	ft_putendl("	exited read_2_bytes");
}

void	find_direct(t_vm *vm, t_process *process, int index, int i)
{
	if (g_ops[process->curr_op].truncate == 1)
	{
		read_2_bytes(vm, process, index, i);
	}
	else 
	{
		read_4_bytes(vm, process, index, i);
	}
}

void	find_register(t_vm *vm, t_process *process, int index, int i)
{
	int register_number;

	register_number = vm->memory[circulate_index(index)] /* & 0xFF */;
	// find register number;
	//if ((0 < register_number && register_number <= REG_NUMBER))
//	if (0 <= register_number && register_number <= 16)	
		process->arg.v[i] = register_number;
//	else
//		process->arg.v[i] = 0;
	// store register value;
//	printf("arg v[%d] is :%d\n", i, process->arg.v[i]);
}

int 	find_arg_size(t_process *process, int i)
{
	if (process->arg.type[i] == 1)
	{
		printf("arg%d  is size :1\n", i);
		return (1);
	}
	else if (process->arg.type[i] == 2)
	{
		printf("curret op is: %d \n", process->curr_op);
		if (g_ops[process->curr_op].truncate == 1)
		{
			printf("arg%d is truncated ind, 2 byte size\n", i);
			return (2);
		}
		else
		{
			printf("arg%d is full ind, 4 byte size\n", i);
			return (4);
		}
	}
	if (process->arg.type[i] == 3)
	{
		printf("arg%d is dir from vm, 2 byte size\n",i );
		return (2);
	}
	ft_putendl("\n\n\n!!!!!error finding arg size\n\n\n");
	return (0);
}

void	find_value(t_vm *vm, t_process *process, int jndex, int param)
{
	if (process->arg.type[param] == 1)
	{
		find_register(vm, process, jndex, param);
	}
	else if (process->arg.type[param] == 2)
	{
		find_direct(vm, process, jndex, param);
	}
	else if (process->arg.type[param] == 3)
	{
		read_4_bytes(vm, process, jndex, param);
		printf("The address from where we want to read from is: %d\n", circulate_index(process->arg.v[param]));
		read_4_bytes(vm, process, process->arg.v[param], param);
		printf("The value at address of dir is: %d\n", process->arg.v[param]);
	}
}

void	store_values(t_vm *vm, t_process *process, int jndex, int argc)
{
	int i;

	i = 0;
	while (argc != 0)
	{
		find_value(vm, process, jndex, i);
		printf("stored values:\n process->arg.v[%d] = %d\n\n\n", i, process->arg.v[i]);
		jndex = circulate_index(jndex + find_arg_size(process, i));

		argc--;
		i++;
	}
}

void	print_regs(int a[])
{
	int i = 0;
	while (i <= 16)
	{
		printf("| register %d : %d |\n", i, a[i]);
		i++;
	}


}	

void	dummy_testing(t_vm *vm)
{
	//ft_and testing
	//0000 0000
	//0101 0100 
	//st.c
	//
	//pc -> memory[0];
	vm->memory[4080] = 0x0;
	vm->memory[4081] = 0xa2;
	vm->memory[4082] = 0xa2;
	vm->memory[4083] = 0xa2;
	vm->memory[4084] = 0xa2;
	vm->memory[4085] = 0xa2;
	vm->memory[4086] = 0xa2;
	vm->memory[4087] = 0xa2;
	vm->memory[4088] = 0xa2;
	vm->memory[4089] = 0xa2;
	vm->memory[4090] = 0xa2;
	vm->memory[4091] = 0xa2;
	vm->memory[4092] = 0x02;
	vm->memory[4093] = 0x87;
	vm->memory[4094] = 0x57;
	vm->memory[4095] = 0xb2;
	vm->memory[circulate_index(4096)] = 6;

int i = 0;

	vm->memory[i] = 6;			i++;		// 0
	vm->memory[i] = 0xac;		i++;		// 1

//	vm->memory[i] = 0x00;		i++;		// 14
//	vm->memory[i] = 0x00;		i++;		// 15

	vm->memory[i] = 0x00;		i++;		// 2
	vm->memory[i] = 0x00;		i++;		// 3

	vm->memory[i] = 0xff;		i++;		// 4
	vm->memory[i] = 0xfc;		i++;		// 5
	
	vm->memory[i] = 0x00;		i++;		// 6
	vm->memory[i] = 0x00;		i++;		// 7

	vm->memory[i] = 0x00;		i++;		// 8
	vm->memory[i] = 0x00;		i++;		// 9

	vm->memory[i] = 0x00;		i++;		// 10
	vm->memory[i] = 0x00;		i++;		// 11

	vm->memory[i] = 0x00;		i++;		// 12
	vm->memory[i] = 0x00;		i++;		// 13

	vm->memory[i] = 0x00;		i++;		// 14
	vm->memory[i] = 0x00;		i++;		// 15

	vm->memory[i] = 0x00;		i++;		// 16
	vm->memory[i] = 0x00;		i++;		// 17

	vm->processes->curr_op = 2;
	vm->processes->arg.type[0] = 3;
	vm->processes->arg.type[1] = 1;
	vm->processes->arg.type[2] = 1;
	vm->processes->regs[2] = 0x00;
	vm->processes->regs[3] = 0x00;
	vm->processes->regs[4] = 0x00;
	vm->processes->regs[5] = 0x00;
//	vm->processes->descriptor = 1;
//	g_ops[vm->processes->curr_op].truncate = 1;
	vm->processes->index = 0;
	vm->processes->truncate = 1;

	
/*	store_values(vm, vm->processes, vm->processes->index + 1 + 1, 2);

	printf("TESTING DUMMY TESTING\n\n");
	printf("pendejada vm->processes->arg.v[0] = %d\n", vm->processes->arg.v[0]);
	printf("pendejada vm->processes->arg.v[1] = %d\n", vm->processes->arg.v[1]);
	printf("pendejada vm->processes->arg.v[2] = %d\n", vm->processes->arg.v[2]);
	printf("ENDING DUMMY TESTING\n\n");
*/
	print_regs(vm->processes->regs);
	printf("^ registers at initiation ^\n\n");
	
//	ft_live(vm, &(vm->champs[0]), vm->processes);

	ft_ld(vm, &(vm->champs[0]), vm->processes);

//	ft_st(vm, &(vm->champs[0]), vm->processes);
//	ft_add(vm, &(vm->champs[0]), vm->processes);
//	ft_sub(vm, &(vm->champs[0]), vm->processes);
//	ft_and(vm, &(vm->champs[0]), vm->processes);
//	ft_or(vm, &(vm->champs[0]), vm->processes);
//	ft_xor(vm, &(vm->champs[0]), vm->processes);
//	ft_zjmp(vm, &(vm->champs[0]), vm->processes);
//	ft_ldi(vm, &(vm->champs[0]), vm->processes);
//	ft_sti(vm, &(vm->champs[0]), vm->processes);
//	ft_fork(vm, &(vm->champs[0]), vm->processes);
//	ft_lld(vm, &(vm->champs[0]), vm->processes);
//	ft_lldi(vm, &(vm->champs[0]), vm->processes);
//	ft_lfork(vm, &(vm->champs[0]), vm->processes);
//	ft_aff(vm, &(vm->champs[0]), vm->processes);
//	ft_xor(vm, &(vm->champs[0]), vm->processes);
//	ft_xor(vm, &(vm->champs[0]), vm->processes);

	printf("modified register: \n");
	print_regs(vm->processes->regs);
	printf("\n\nTESTING DUMMY TESTING\n\n");
	printf("pendejada vm->processes->arg.v[0] = %d\n", vm->processes->arg.v[0]);
	printf("pendejada vm->processes->arg.v[1] = %d\n", vm->processes->arg.v[1]);
	printf("pendejada vm->processes->arg.v[2] = %d\n", vm->processes->arg.v[2]);
	printf("pendejada vm->processes->regs.v[2] = %d\n", vm->processes->regs[2]);
	printf("\nENDING DUMMY TESTING\n\n");
}



















