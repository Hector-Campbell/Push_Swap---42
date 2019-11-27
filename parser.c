/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 19:12:14 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/24 19:12:21 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker.h"

/*int			main(int argc, char **argv)
{
	t_len		*length;
	t_str		*strings;
	t_ft		*steps;
	char		**tmp;

	steps = (t_ft *)malloc(sizeof(t_ft));
	length = (t_len *)malloc(sizeof(t_len));
	strings = (t_str *)malloc(sizeof(t_str));
	tmp = NULL;
	if (argc < 2)
	{
		return (0);
	}
	else
	{
		if (int_parser(length, strings, argc, argv) == 1)
		{
			ft_printf("%s", "Error\n");
			return (0);
		}
		if (instruction_parser2(steps) == 1)
		{
			ft_printf("%s", "Error\n");
			return (0);
		}
		if (simple_algorithim(length, strings, steps) == 1)
		{
			ft_printf("%s", "KO\n");
			return (0);
		}
		else
			ft_printf("%s", "OK\n");
	}
	return (0);
}*/

int			instruction_parser(t_len *length, t_ft *steps, int argc,
								char **argv)
{
	int		i;
	int		j;

	i = length->len_a + 1;
	j = 0;
	steps->list = (char **)malloc(sizeof(char *) * (argc - length->len_a));
	steps->list[argc - length->len_a - 1] = NULL;
	while (i != argc)
	{
		if (ft_strcmp(argv[i], "sa\n") == 0 || ft_strcmp(argv[i],
		"sb\n") == 0 || ft_strcmp(argv[i], "ss\n") == 0 ||
		ft_strcmp(argv[i], "ra\n") == 0 ||
			ft_strcmp(argv[i], "rb\n") == 0 || ft_strcmp(argv[i],
			"rr\n") == 0 || ft_strcmp(argv[i], "rra\n") == 0 ||
			ft_strcmp(argv[i], "rrb\n") == 0 ||
			ft_strcmp(argv[i], "rrr\n") == 0 || ft_strcmp(argv[i],
			"pa\n") == 0 || ft_strcmp(argv[i], "pb\n") == 0)
		{
			steps->list[j] = ft_strdup(argv[i]);
			j++;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

int			instruction_parser2(t_ft *steps)
{
	get_next_line(0, steps->list);
	return (0);
}
