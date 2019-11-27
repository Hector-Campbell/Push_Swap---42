/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 12:01:23 by hecampbe          #+#    #+#             */
/*   Updated: 2019/11/21 12:01:26 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void        order_a(t_len *length, t_str *strings, t_list2 *steps)
{
	int     i;
	int     rot;
	int		r_rot;

	i = 0;
	rot = rotate_value(length->len_a, strings->str_a);
	r_rot = r_rotate_value(length->len_a, strings->str_a);
	while (solved(length, strings) != 0 && length->len_a >= 1)
	{
		if (strings->str_a[i] > strings->str_a[i + 1] && i != length->len_a + 1)
		{
			if (strings->str_a[0] > strings->str_a[1] && length->len_a == 2)
			{
				transfer_a(length, strings, sa(length, strings));
				put_instruction("sa", steps);
			}
			else if (strings->str_a[0] > strings->str_a[1] && strings->str_a[0] < strings->str_a[2])
			{
				transfer_a(length, strings, sa(length, strings));
				put_instruction("sa", steps);
			}
			else
			{
				if(rot <= r_rot)
					order_a_rotate(length, strings, steps);
				else
					order_a_reverse_rotate(length, strings, steps);
			}
		}
		else
			i++;
	}
}

void        order_a_reverse_rotate(t_len *length, t_str *strings, t_list2 *steps)
{
    int     rot;

    rot = 0;
    transfer_both(length, strings, pb(length, strings));
	put_instruction("pb", steps);
	while (strings->str_b[0] > strings->str_a[0])
	{
		transfer_a(length, strings, ra(length, strings));
		put_instruction("ra", steps);
		rot++;
	}
	transfer_both(length, strings, pa(length, strings));
	put_instruction("pa", steps);
	while (rot != -1)
	{
		transfer_a(length, strings, rra(length, strings));
		put_instruction("rra", steps);
		rot--;
	}
}


void        order_a_rotate(t_len *length, t_str *strings, t_list2 *steps)
{
    int     r_rot;

    r_rot = 0;
    transfer_both(length, strings, pb(length, strings));
	put_instruction("pb", steps);
	while (strings->str_b[0] < strings->str_a[length->len_a])
	{
		transfer_a(length, strings, rra(length, strings));
		put_instruction("rra", steps);
		r_rot++;
	}
	transfer_both(length, strings, pa(length, strings));
	put_instruction("pa", steps);
    while (r_rot != -1)
	{
		transfer_a(length, strings, ra(length, strings));
		put_instruction("ra", steps);
		r_rot--;
	}
}
