/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ops.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 01:20:26 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/17 19:58:16 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		ft_put(char *str)
{
	ft_putstr(str);
	return (1);
}

void	set_ops_cycles(t_op *ops)
{
	ops[0].cycles = 0;
	ops[0x1].cycles = 10;
	ops[0x2].cycles = 5;
	ops[0x3].cycles = 5;
	ops[0x4].cycles = 10;
	ops[0x5].cycles = 10;
	ops[0x6].cycles = 6;
	ops[0x7].cycles = 6;
	ops[0x8].cycles = 6;
	ops[0x9].cycles = 20;
	ops[0xa].cycles = 25;
	ops[0xb].cycles = 25;
	ops[0xc].cycles = 800;
	ops[0xd].cycles = 10;
	ops[0xe].cycles = 50;
	ops[0xf].cycles = 1000;
	ops[0x10].cycles = 2;
}

void	set_ops_descriptor(t_op *ops)
{
	ops[0].descriptor= 0;
	ops[0x1].descriptor = 0;
	ops[0x2].descriptor = 1;
	ops[0x3].descriptor = 1;
	ops[0x4].descriptor = 1;
	ops[0x5].descriptor = 1;
	ops[0x6].descriptor = 1;
	ops[0x7].descriptor = 1;
	ops[0x8].descriptor = 1;
	ops[0x9].descriptor = 0;
	ops[0xa].descriptor = 1;
	ops[0xb].descriptor = 1;
	ops[0xc].descriptor = 0;
	ops[0xd].descriptor = 1;
	ops[0xe].descriptor = 1;
	ops[0xf].descriptor = 0;
	ops[0x10].descriptor = 1;
	set_ops_cycles(ops);
}

void	set_ops_args(t_op *ops)
{
	ops[0].args = 0;
	ops[0x1].args = 1;
	ops[0x2].args = 2;
	ops[0x3].args = 2;
	ops[0x4].args = 3;
	ops[0x5].args = 3;
	ops[0x6].args = 3;
	ops[0x7].args = 3;
	ops[0x8].args = 3;
	ops[0x9].args = 1;
	ops[0xa].args = 3;
	ops[0xb].args = 3;
	ops[0xc].args = 1;
	ops[0xd].args = 2;
	ops[0xe].args = 3;
	ops[0xf].args = 1;
	ops[0x10].args = 1;
	set_ops_descriptor(ops);
}

void	set_truncate(t_op *ops)
{
	ops[0].truncate = 0;
	ops[0x1].truncate = 0;
	ops[0x2].truncate = 0;
	ops[0x3].truncate = 0;
	ops[0x4].truncate = 0;
	ops[0x5].truncate = 0;
	ops[0x6].truncate = 0;
	ops[0x7].truncate = 0;
	ops[0x8].truncate = 0;
	ops[0x9].truncate = 1;
	ops[0xa].truncate = 1;
	ops[0xb].truncate = 1;
	ops[0xc].truncate = 1;
	ops[0xd].truncate = 0;
	ops[0xe].truncate = 1;
	ops[0xf].truncate = 1;
	ops[0x10].truncate = 1;
	set_ops_args(ops);
}

void	init_ops(t_op *ops)
{
	ops[0x1].func_to_be = &ft_printf;
	ops[0x2].func_to_be = &ft_printf;
	ops[0x3].func_to_be = &ft_printf;
	ops[0x4].func_to_be = &ft_printf;
	ops[0x5].func_to_be = &ft_printf;
	ops[0x6].func_to_be = &ft_printf;
	ops[0x7].func_to_be = &ft_printf;
	ops[0x8].func_to_be = &ft_printf;
	ops[0x9].func_to_be = &ft_printf;
	ops[0xa].func_to_be = &ft_printf;
	ops[0xb].func_to_be = &ft_printf;
	ops[0xc].func_to_be = &ft_printf;
	ops[0xd].func_to_be = &ft_printf;
	ops[0xe].func_to_be = &ft_printf;
	ops[0xf].func_to_be = &ft_printf;
	ops[0x10].func_to_be = &ft_printf;
	set_truncate(ops);
}
