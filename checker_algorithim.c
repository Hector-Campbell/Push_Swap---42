/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_algorithim.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:56:42 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/25 13:56:50 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			simple_algorithim(t_len *length, t_str *strings, t_ft *steps)
{
	int		i;

	i = 0;
	strings->str_both = (int **)malloc(sizeof(int *) * (2));
	strings->str_b = NULL;
	strings->str_both[0] = intdup_a(length, strings->str_a);
	strings->str_both[1] = strings->str_b;
	length->len_b = 0;
	while (steps->list[i] != '\0')
	{
		simple_algorithim2(length, strings, steps, i);
		i++;
	}
	if (solved(length, strings) == 1)
		return (1);
	else
		return (0);
}

void		simple_algorithim2(t_len *length, t_str *strings, t_ft *steps,
								int i)
{
	if (ft_strcmp(steps->list[i], "sa\n") == 0)
		transfer_a(length, strings, sa(length, strings));
	else if (ft_strcmp(steps->list[i], "sb\n") == 0)
		transfer_b(length, strings, sb(length, strings));
	else if (ft_strcmp(steps->list[i], "ss\n") == 0)
		transfer_both(length, strings, ss(length, strings));
	else if (ft_strcmp(steps->list[i], "pa\n") == 0)
		transfer_both(length, strings, pa(length, strings));
	else if (ft_strcmp(steps->list[i], "pb\n") == 0)
		transfer_both(length, strings, pb(length, strings));
	else if (ft_strcmp(steps->list[i], "ra\n") == 0)
		transfer_a(length, strings, ra(length, strings));
	else if (ft_strcmp(steps->list[i], "rb\n") == 0)
		transfer_b(length, strings, rb(length, strings));
	else if (ft_strcmp(steps->list[i], "rr\n") == 0)
		transfer_both(length, strings, rr(length, strings));
	else if (ft_strcmp(steps->list[i], "rra\n") == 0)
		transfer_a(length, strings, rra(length, strings));
	else if (ft_strcmp(steps->list[i], "rrb\n") == 0)
		transfer_b(length, strings, rrb(length, strings));
	else if (ft_strcmp(steps->list[i], "rrr\n") == 0)
		transfer_both(length, strings, rrr(length, strings));
}
