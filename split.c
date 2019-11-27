/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 15:56:47 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/30 15:56:56 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void			if_a_two(t_len *length, t_str *strings, t_list2 *steps)
{
	while (solved(length, strings) != 0)
	{
		transfer_a(length, strings, sa(length, strings));
		put_instruction("sa", steps);
	}
}

void			if_a_three(t_len *length, t_str *st, t_list2 *steps)
{
	while (solved(length, st) != 0)
	{
		if ((st->str_a[0] > st->str_a[1]) && (st->str_a[0] < st->str_a[2]))
		{
			transfer_a(length, st, sa(length, st));
			put_instruction("sa", steps);
		}
		else if ((st->str_a[0] < st->str_a[1]) && (st->str_a[0] < st->str_a[2]))
		{
			transfer_a(length, st, sa(length, st));
			transfer_a(length, st, ra(length, st));
			put_instruction("sa", steps);
			put_instruction("ra", steps);
		}
		else if ((st->str_a[0] < st->str_a[1]) && (st->str_a[0] > st->str_a[2]))
		{
			transfer_a(length, st, rra(length, st));
			put_instruction("rra", steps);
		}
		else if ((st->str_a[0] > st->str_a[1]) && (st->str_a[0] > st->str_a[2]))
		{
			transfer_a(length, st, ra(length, st));
			put_instruction("ra", steps);
		}
	}
}

void			if_a_five_or_lower(t_len *length, t_str *strings,
									t_list2 *steps)
{
	int		check;

	check = 0;
	while (length->len_a > 3)
	{
		push_smallest(length, strings, steps);
		put_instruction("pb", steps);
		check++;
	}
	if (length->len_a == 2)
		if_a_two(length, strings, steps);
	else if (length->len_a == 3)
		if_a_three(length, strings, steps);
	while (check != 0)
	{
		transfer_both(length, strings, pa(length, strings));
		put_instruction("pa", steps);
		check--;
	}
}
