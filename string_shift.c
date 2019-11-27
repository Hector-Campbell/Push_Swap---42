/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_shift.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 18:47:08 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/24 18:47:20 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*shift_down_a(t_len *length, t_str *strings)
{
	int		*newstr;
	int		i;

	i = 1;
	newstr = intnew(length->len_a + 1);
	while (i < length->len_a + 1)
	{
		newstr[i] = strings->str_a[i - 1];
		i++;
	}
	free(strings->str_a);
	strings->str_a = NULL;
	return (newstr);
}

int			*shift_down_b(t_len *length, t_str *strings)
{
	int		*newstr;
	int		i;

	i = 1;
	newstr = intnew(length->len_b + 1);
	while (i < length->len_b + 1)
	{
		newstr[i] = strings->str_b[i - 1];
		i++;
	}
	free(strings->str_b);
	strings->str_b = NULL;
	return (newstr);
}

int			*shift_up_a(t_len *length, t_str *strings)
{
	int		*newstr;
	int		i;

	i = 0;
	newstr = intnew(length->len_a - 1);
	while (i < length->len_a - 1)
	{
		newstr[i] = strings->str_a[i + 1];
		i++;
	}
	free(strings->str_a);
	strings->str_a = NULL;
	return (newstr);
}

int			*shift_up_b(t_len *length, t_str *strings)
{
	int		*newstr;
	int		i;

	i = 0;
	newstr = intnew(length->len_b - 1);
	while (i < length->len_b - 1)
	{
		newstr[i] = strings->str_b[i + 1];
		i++;
	}
	free(strings->str_b);
	strings->str_b = NULL;
	return (newstr);
}
