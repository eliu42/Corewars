/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_op_builder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adubugra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 18:33:23 by adubugra          #+#    #+#             */
/*   Updated: 2018/05/25 16:41:29 by adubugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		set_op_name(char **strreal, t_ops *op)
{
	int		i;
	char	*str;
	char	*tmp;

	if (!(*strreal) || !op)
		return (ft_printf_err("empty argument @opname\n"));
	str = *strreal;
	i = 0;
	while (!WHITESPACE(str[i]))
		i++;
	tmp = op->op_name;
	op->op_name = ft_strsub(str, 0, i);
	free(tmp);
	while (WHITESPACE(str[i]))
		i++;
	*strreal = &str[i];
	return (0);
}

int		set_arguments(char **strreal, t_ops *op)
{
	char	*str;
	int		i;
	char	*tmp;

	if (!strreal || !op)
		return (ft_printf_err("empty argument @setargs\n"));
	str = *strreal;
	op->arg_name = ft_strsplit(str, ',');
	i = 0;
	while (op->arg_name[i])
	{
		tmp = op->arg_name[i];
		remove_comments(op->arg_name[i]);
		op->arg_name[i] = ft_strtrim(op->arg_name[i]);
		free(tmp);
		i++;
	}
	if (i != op_table[op->op_code - 1].args)
		return (ft_printf_err("wrong args number!\n"));
	return (0);
}

void	set_bit_descriptor(char *descriptor, char *arg_name, int arg_num)
{
	char d;

	if (arg_name[0] == 'r')
		d = 1;
	else if (arg_name[0] == DIRECT_CHAR)
		d = 2;
	else
		d = 3;
	d = d << (8 - (2 * arg_num));
	*descriptor = *descriptor | d;
}

int		get_arguments_and_sizes(t_ops *op)
{
	int		i;

	i = -1;
	while (op->arg_name[++i])
	{
		if (check_argument(op->arg_name[i]))
			return (ft_printf_err("Argument parse error: %s\n", op->arg_name[i]));
		set_bit_descriptor(&(op->descriptor), op->arg_name[i], i + 1);
		op->label_arg[i] = (op->arg_name[i][0] == LABEL_CHAR ||
				op->arg_name[i][1] == LABEL_CHAR) ? 1 : 0;
		op->args[i] = ft_atoi(&(op->arg_name[i][1]));
		if (op->arg_name[i][0] == 'r')
			op->arg_sizes[i] = 1;
		else if (op->arg_name[i][0] == DIRECT_CHAR)
			op->arg_sizes[i] = op_table[(int)op->op_code - 1].truncate ? 2 : 4;
		else if (ft_isdigit_sign(op->arg_name[i][0]) ||
				op->arg_name[i][0] == LABEL_CHAR)
		{
			op->args[i] = ft_atoi(&(op->arg_name[i][0]));
			op->arg_sizes[i] = 2;
		}
		else
			return (ft_printf_err("unknow argument type\n"));
	}
	return (0);
}

int		set_size(t_ops *op)
{
	op->size = op_table[(int)op->op_code - 1].descriptor + 1;
	op->size += op->arg_sizes[0];
	op->size += op->arg_sizes[1];
	op->size += op->arg_sizes[2];
	return (1);
}
