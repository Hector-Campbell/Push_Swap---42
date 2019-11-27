/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 21:20:26 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/27 21:20:36 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_len		*length;
	t_str		*strings;
	t_list2		*steps;

	length = (t_len *)malloc(sizeof(t_len));
	strings = (t_str *)malloc(sizeof(t_str));
	steps = (t_list2 *)malloc(sizeof(t_list2));
	steps->stepz = (char *)malloc(sizeof(char));
	steps->stepz = NULL;
	if (argc < 1)
		ft_printf("%s", "Error");
	else
	{
		int_parser(length, strings, argc, argv);
		algorithim(length, strings, steps);
	}
	/*else
	{
		if ((int_parser(length, strings, argc, argv) == 1) ||
			(complex_algorithim(length, strings, steps) != 1))
		{
			ft_printf("%s", "Error");
			return (0);
		}
	}*/
	print_solution2(length, strings, steps);
	//ft_printf("%s\n", "sa");
	return (0);
}

void		print_solution2(t_len *length, t_str *strings, t_list2 *steps)
{
	int		i;

	i = 0;
	//length->len_a = 0;
	//strings->str_a[0] = 0;
	//steps->stepz = NULL;
	while (i < length->len_a)
	{
		ft_printf("%d", strings->str_a[i]);
		ft_printf("%c", ',');
		ft_printf("%c", ' ');
		i++;
	}
	i = 0;
	if (steps->stepz != NULL)
	{
		ft_putchar('\n');
		//this new line is just for help with reading my numbers
		ft_printf("%s\n", steps->stepz);
	}
}

int			complex_algorithim(t_len *length, t_str *strings, t_list2 *steps)
{
	strings->str_both = (int **)malloc(sizeof(int *) * (2));
	strings->str_b = NULL;
	strings->str_both[0] = intdup_a(length, strings->str_a);
	strings->str_both[1] = strings->str_b;
	length->len_b = 0;
	while (solved(length, strings) == 1)
	{
		if_a_five_or_lower(length, strings, steps);
	}
	return (1);
}

int			put_instruction(char *new_step, t_list2 *steps)
{
	if (steps->stepz == NULL)
		steps->stepz = ft_strdup(new_step);
	else
	{
		steps->stepz = ft_strjoin(steps->stepz, "\n");
		steps->stepz = ft_strjoin(steps->stepz, new_step);
	}
	return (0);
}
