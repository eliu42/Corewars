/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eliu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 23:50:39 by eliu              #+#    #+#             */
/*   Updated: 2018/05/28 07:01:51 by eliu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

char	reg(t_process *process, int x)
{
	if (process->arg.type[x] == REG_CODE && process->arg.v[x] <= REG_NUMBER)
		return (REG_CODE);
	return (0);
}

char	dir(t_process *process, int x)
{
	if (process->arg.type[x] == DIR_CODE)
		return (DIR_CODE);
	return (0);
}

char	ind(t_process *process, int x)
{
	if (process->arg.type[x] == IND_CODE)
		return (IND_CODE);
	return (0);
}
