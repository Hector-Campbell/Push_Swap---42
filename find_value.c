/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 18:32:21 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/29 18:32:37 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			find_big(int len, int *str, int rank)
{
	int		i;
	int		biggest;
	int		value;

	i = 0;
	biggest = str[0];
	while (i != len)
	{
		if (biggest < str[i])
			biggest = str[i];
		i++;
	}
	while (rank != 1)
	{
		while (i != len)
		{
			if (value < str[i] && str[i] < biggest)
				value = str[i];
		}
		rank--;
		biggest = value;
	}
	return (biggest);
}

int			find_small(int len, int *str, int rank)
{
	int		i;
	int		smallest;
	int		value;

	i = 0;
	smallest = str[0];
	value = find_big(len, str, 1);
	while (i != len)
	{
		if (smallest > str[i])
			smallest = str[i];
		i++;
	}
	while (rank != 1)
	{
		while (i != len)
		{
			if (value > str[i] && str[i] > smallest)
				value = str[i];
		}
		rank--;
		smallest = value;
	}
	return (smallest);
}
