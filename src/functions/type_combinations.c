/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_combinations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 00:11:42 by eliu              #+#    #+#             */
/*   Updated: 2018/05/22 01:11:14 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/corewar.h"

char	all(t_process *process, int x)
{
	return (reg(process, x) || dir(process, x) || ind(process, x));
}

char	dir_ind(t_process *process, int x)
{
	return (dir(process, x) || ind(process, x));
}

char	reg_dir(t_process *process, int x)
{
	return (reg(process, x) || dir(process, x));
}

char	reg_ind(t_process *process, int x)
{
	return (dir(process, x) || ind(process, x));
}

/*
char	dir_ind(t_process *process, int x)
{
	return (dir(process, x) || ind(process, x));
}
*/
