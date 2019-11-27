/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:04:25 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/24 18:05:52 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*rra(t_len *length, t_str *strings)
{
	int		i;
	int		*newstr;
	int		tmp;

	i = 0;
	tmp = strings->str_a[length->len_a - 1];
	newstr = intnew(length->len_a);
	while (i < (length->len_a - 1))
	{
		newstr[i + 1] = strings->str_a[i];
		i++;
	}
	newstr[0] = tmp;
	return (newstr);
}

int			*rrb(t_len *length, t_str *strings)
{
	int		i;
	int		*newstr;
	int		tmp;

	i = 0;
	tmp = strings->str_b[length->len_b - 1];
	newstr = intnew(length->len_b);
	while (i < (length->len_b - 1))
	{
		newstr[i + 1] = strings->str_b[i];
		i++;
	}
	newstr[0] = tmp;
	return (newstr);
}

int			**rrr(t_len *length, t_str *strings)
{
	free(strings->str_both);
	strings->str_both = (int **)malloc(sizeof(int *) * (2));
	strings->str_both[0] = rra(length, strings);
	strings->str_both[1] = rrb(length, strings);
	return (strings->str_both);
}
