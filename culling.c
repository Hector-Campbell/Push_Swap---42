/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithim2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 03:57:48 by hecampbe          #+#    #+#             */
/*   Updated: 2019/11/19 07:04:57 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int        cull_supreme(t_len *length, t_str *strings, t_list2 *steps)
{
    int     mid_value;
    int     hold;
	int		half_len_value;
	int		tmp;

	hold = -1;
	mid_value = middle_value(strings->str_a, length->len_a);
	half_len_value = strings->str_a[length->len_a / 2];
	tmp = length->len_a;
    while (strings->str_a[0] != half_len_value)
	{
		if (strings->str_a[0] > mid_value)
			cull_push(length, strings, steps);
		else
			hold = cull_rotate(length, strings, steps, hold);
	}
	if (if_odd(length->len_a) == 1)
	{
		if (strings->str_a[0] >= mid_value)
			hold = cull_rotate(length, strings, steps, hold);
		else
			cull_push(length, strings, steps);
	}
	while (hold != strings->str_a[0])
	{
		if (strings->str_a[0] <= mid_value)
			cull_push(length, strings, steps);
		else
			hold = cull_rotate(length, strings, steps, hold);
	}
	tmp = length->len_a;
	mid_value = middle_value(strings->str_a, length->len_a);
	half_len_value = strings->str_a[length->len_a / 2];
	return (0);
}

void		cull_push(t_len *length, t_str *strings, t_list2 *steps)
{
    transfer_both(length, strings, pb(length, strings));
	put_instruction("pb", steps);
	order_b(length, strings, steps);
}

int         cull_rotate(t_len *length, t_str *strings, t_list2 *steps, int hold)
{
    int tmp;

    tmp = strings->str_a[0];
    if (hold == -1)
		hold = strings->str_a[0];
	transfer_a(length, strings, ra(length, strings));
	put_instruction("ra", steps);
    tmp = strings->str_a[length->len_a - 1];
    return (hold);
}
