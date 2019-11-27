/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_operation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:04:15 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/19 14:07:43 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*ra(t_len *length, t_str *strings)
{
	int		i;
	int		tmp;
	int		*newstr;

	i = 0;
	tmp = strings->str_a[0];
	newstr = intnew(length->len_a);
	while (i < (length->len_a - 1))
	{
		newstr[i] = strings->str_a[i + 1];
		i++;
	}
	newstr[i] = tmp;
	return (newstr);
}

int			*rb(t_len *length, t_str *strings)
{
	int		i;
	int		tmp;
	int		*newstr;

	i = 0;
	tmp = strings->str_b[0];
	newstr = intnew(length->len_b);
	while (i < (length->len_b - 1))
	{
		newstr[i] = strings->str_b[i + 1];
		i++;
	}
	newstr[i] = tmp;
	return (newstr);
}

int			**rr(t_len *length, t_str *strings)
{
	free(strings->str_both);
	strings->str_both = (int **)malloc(sizeof(int *) * (2));
	strings->str_both[0] = ra(length, strings);
	strings->str_both[1] = rb(length, strings);
	return (strings->str_both);
}
