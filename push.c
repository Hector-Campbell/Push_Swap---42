/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/29 20:47:44 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/29 20:48:04 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			push_smallest(t_len *length, t_str *strings, t_list2 *steps)
{
	int		push_value;
	int		i;
	int		mid;

	push_value = find_small(length->len_a, strings->str_a, 1);
	i = 0;
	mid = length->len_a / 2;
	if (if_odd(length->len_a) == 1)
		mid = mid + 1;
	while (strings->str_a[i] != push_value)
		i++;
	if (mid > i)
		transfer_ra(length, strings, steps, i);
	else
	{
		while (i != length->len_a)
		{
			transfer_a(length, strings, rra(length, strings));
			put_instruction("rra", steps);
			i++;
		}
	}
	transfer_both(length, strings, pb(length, strings));
	return (0);
}

void		transfer_ra(t_len *length, t_str *strings, t_list2 *steps, int i)
{
	while (i != 0)
	{
		transfer_a(length, strings, ra(length, strings));
		put_instruction("ra", steps);
		i--;
	}
}

int			if_odd(int value)
{
	if (value % 2 == 0)
		return (0);
	else
		return (1);
}
