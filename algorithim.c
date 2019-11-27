/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 23:53:54 by hecampbe          #+#    #+#             */
/*   Updated: 2019/11/19 07:05:19 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			middle_value(int *str, int len)
{
	int		i;
	int		mid;
	int		bigger_than;
	int		value;
	int		j;

	i = 0;
	mid = len / 2;
	bigger_than = 0;
	value = str[i];
	j = 1;
	if (if_odd(len) == 1)
		mid = mid + 1;
	while (bigger_than != mid - 1)
	{
		while (i < len)
		{
			if (value > str[i])
				bigger_than++;
			i++;
		}
		i = 0;
		if (bigger_than != mid - 1)
		{
			value = str[j++];
			bigger_than = 0;
		}
	}
	return (value);
}

int			algorithim(t_len *length, t_str *strings, t_list2 *steps)
{
	int		half_len_value;
	int		tmp;

	half_len_value = strings->str_a[length->len_a / 2];
	tmp = length->len_a;

	strings->str_both = (int **)malloc(sizeof(int *) * (2));
	strings->str_b = NULL;
	strings->str_both[0] = intdup_a(length, strings->str_a);
	strings->str_both[1] = strings->str_b;
	length->len_b = 0;
	while (length->len_a >= 2)
	{
		//half_len_value = strings->str_a[length->len_a / 2];
		cull_supreme(length, strings, steps);
		tmp = length->len_a;
	}
	//cull_supreme(length, strings, steps);
	//order_a(length, strings, steps);
	//place_b(length, strings, steps);
	return (0);
}

void		place_b(t_len *length, t_str *strings, t_list2 *steps)
{
	int		hold;
	int		tmp_a;
	int		tmp_b;
	int		tmp_len;

	hold = -1;
	tmp_len = length->len_b;
	if (strings->str_b[0] < strings->str_a[0])
	{
		tmp_a = strings->str_a[0];
		tmp_b = strings->str_b[0];
		transfer_both(length, strings, pa(length, strings));
		put_instruction("pa", steps);
		if (hold == -1)
			hold = strings->str_a[0];
		transfer_a(length, strings, ra(length, strings));
		put_instruction("ra", steps);
	}
	else
	{
		if (hold == -1)
			hold = strings->str_a[0];
		transfer_a(length, strings, ra(length, strings));
		put_instruction("ra", steps);
	}
	while (strings->str_a[0] != hold && strings->str_b != NULL)
	{
		tmp_a = strings->str_a[0];
		tmp_b = strings->str_b[0];
		if (strings->str_b[0] < strings->str_a[0])
		{
			transfer_both(length, strings, pa(length, strings));
			put_instruction("pa", steps);
			transfer_a(length, strings, ra(length, strings));
			put_instruction("ra", steps);
		}
		else
		{
			transfer_a(length, strings, ra(length, strings));
			put_instruction("ra", steps);
		}
	}
	while (length->len_b != 0)
	{
		tmp_a = strings->str_a[0];
		tmp_b = strings->str_b[0];
		transfer_both(length, strings, pa(length, strings));
		put_instruction("pa", steps);
		transfer_a(length, strings, ra(length, strings));
		put_instruction("ra", steps);
	}
}
