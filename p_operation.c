/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 23:59:04 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/19 14:06:56 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			**pa(t_len *length, t_str *strings)
{
	int		*tmp_a;
	int		*tmp_b;

	if (strings->str_b == NULL)
		return (strings->str_both);
	if (strings->str_a == NULL)
		tmp_a = (int *)malloc(sizeof(int) * (1));
	else
	{
		tmp_a = shift_down_a(length, strings);
		free(strings->str_a);
		strings->str_a = NULL;
	}
	tmp_a[0] = strings->str_b[0];
	tmp_b = shift_up_b(length, strings);
	strings->str_both[0] = tmp_a;
	strings->str_both[1] = tmp_b;
	length->len_a++;
	length->len_b--;
	return (strings->str_both);
}

int			**pb(t_len *length, t_str *strings)
{
	int		*tmp_a;
	int		*tmp_b;

	if (strings->str_a == NULL)
		return (strings->str_both);
	if (strings->str_b == NULL)
		tmp_b = (int *)malloc(sizeof(int) * (1));
	else
	{
		tmp_b = shift_down_b(length, strings);
		free(strings->str_b);
		strings->str_b = NULL;
	}
	tmp_b[0] = strings->str_a[0];
	tmp_a = shift_up_a(length, strings);
	strings->str_both[0] = tmp_a;
	strings->str_both[1] = tmp_b;
	length->len_a--;
	length->len_b++;
	return (strings->str_both);
}
