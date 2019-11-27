/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:27:11 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/24 14:36:11 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*sa(t_len *length, t_str *strings)
{
	int		tmp;

	if (strings->str_a == NULL)
		return (strings->str_a);
	tmp = strings->str_a[0];
	strings->str_a[0] = strings->str_a[1];
	strings->str_a[1] = tmp;
	tmp = strings->str_a[0];
	return (intdup_a(length, strings->str_a));
}

int			*sb(t_len *length, t_str *strings)
{
	int		tmp;

	if (strings->str_b == NULL)
		return (strings->str_b);
	tmp = strings->str_b[0];
	strings->str_b[0] = strings->str_b[1];
	strings->str_b[1] = tmp;
	return (intdup_b(length, strings->str_b));
}

int			**ss(t_len *length, t_str *strings)
{
	free(strings->str_both);
	strings->str_both = (int **)malloc(sizeof(int *) * (2));
	strings->str_both[0] = sa(length, strings);
	strings->str_both[1] = sb(length, strings);
	return (strings->str_both);
}
