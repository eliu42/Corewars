/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 22:55:43 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/16 01:24:06 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	set_champs(t_champ *champ, char *filename)
{
	if (!champ)
		champ = malloc(sizeof(champ));
	champ->fd = open(filename, O_RDONLY);
	champ->plyr_nbr = 0;
	champ->size = 0;
	champ->processes = 0;
}

void	clear_vm_mem(t_vm *vm)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		vm->memory[i] = 0;
		i++;
	}
}
