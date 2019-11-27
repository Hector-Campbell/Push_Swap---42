/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 10:04:41 by hecampbe          #+#    #+#             */
/*   Updated: 2019/11/20 10:04:43 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		order_b(t_len *length, t_str *strings, t_list2 *steps)
{
	int		rot;
	int		r_rot;

	rot = rotate_value(length->len_b, strings->str_b);
	r_rot = r_rotate_value(length->len_b, strings->str_b);
	if (solved_b(length, strings) != 0 && length->len_b > 1)
	{
		if (strings->str_b[0] > strings->str_b[1] && length->len_b == 2)
		{
			transfer_b(length, strings, sb(length, strings));
			put_instruction("sb", steps);
		}
		else if ((strings->str_b[0] > strings->str_b[1]) && (strings->str_b[0] < strings->str_b[2]))
		{
			transfer_b(length, strings, sb(length, strings));
			put_instruction("sb", steps);
		}
		else
		{
			if (rot <= r_rot)
				order_b_rotate(length, strings, steps);
			else
				order_b_reverse_rotate(length, strings, steps);
		}
	}
}

void        order_b_rotate(t_len *length, t_str *strings, t_list2 *steps)
{
    int     r_rot;

    r_rot = 0;
    transfer_both(length, strings, pa(length, strings));
	put_instruction("pa", steps);
	while (strings->str_a[0] < strings->str_b[length->len_b])
	{
		transfer_b(length, strings, rrb(length, strings));
		put_instruction("rrb", steps);
		r_rot++;
	}
	transfer_both(length, strings, pb(length, strings));
	put_instruction("pb", steps);
    while (r_rot != -1)
	{
		transfer_b(length, strings, rb(length, strings));
		put_instruction("rb", steps);
		r_rot--;
	}
}

void        order_b_reverse_rotate(t_len *length, t_str *strings, t_list2 *steps)
{
    int     rot;

    rot = 0;
    transfer_both(length, strings, pa(length, strings));
	put_instruction("pa", steps);
	while (strings->str_a[0] > strings->str_b[0])
	{
		transfer_b(length, strings, rb(length, strings));
		put_instruction("rb", steps);
		rot++;
	}
	transfer_both(length, strings, pb(length, strings));
	put_instruction("pb", steps);
	while (rot != -1)
	{
		transfer_b(length, strings, rrb(length, strings));
		put_instruction("rrb", steps);
		rot--;
	}
}
