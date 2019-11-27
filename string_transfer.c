/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_transfer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:57:04 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/25 13:57:16 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		transfer_a(t_len *length, t_str *strings, int *str)
{
	free(strings->str_a);
	free(strings->str_both[0]);
	strings->str_a = intdup_a(length, str);
	strings->str_both[0] = intdup_a(length, str);
}

void		transfer_b(t_len *length, t_str *strings, int *str)
{
	free(strings->str_b);
	free(strings->str_both[1]);
	strings->str_b = intdup_b(length, str);
	strings->str_both[1] = intdup_b(length, str);
}

void		transfer_both(t_len *length, t_str *strings, int **str)
{
	if (strings->str_a != NULL)
		free(strings->str_a);
	if (strings->str_b != NULL)
		free(strings->str_b);
	strings->str_a = intdup_a(length, str[0]);
	strings->str_b = intdup_b(length, str[1]);
}
