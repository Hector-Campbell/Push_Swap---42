/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 21:51:29 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/24 19:11:29 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*intdup_a(t_len *length, int *str)
{
	int		*newstr;
	int		i;

	i = 0;
	newstr = (int *)malloc(sizeof(int) * (length->len_a));
	if (newstr == NULL)
		return (NULL);
	while (i < length->len_a)
	{
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}

int			*intdup_b(t_len *length, int *str)
{
	int		*newstr;
	int		i;

	i = 0;
	newstr = (int *)malloc(sizeof(int) * (length->len_b + 1));
	if (newstr == NULL)
		return (NULL);
	while (i < length->len_b)
	{
		newstr[i] = str[i];
		i++;
	}
	return (newstr);
}

int			*intnew(int len)
{
	int		*newstr;

	newstr = (int *)malloc(sizeof(int) * (len));
	return (newstr);
}

int			int_parser(t_len *length, t_str *strings, int argc, char **argv)
{
	int		i;
	int		j;

	strings->str_a = (int *)malloc(sizeof(int) * (argc));
	length->len_a = 0;
	i = 0;
	j = 0;
	while (argv[i + 1] != '\0')
	{
		if (compare(ft_atoi(argv[i + 1]), strings->str_a, length->len_a) == 1)
			return (1);
		if (max_compare(argv[i + 1]) == 1)
			return (1);
		if (i == 0 && ft_isdigit(argv[i + 1][j]) != 1)
			return (1);
		else if (ft_isdigit(argv[i + 1][j]) != 1)
			return (0);
		else if (ft_isdigit(argv[i + 1][j]) == 1)
		{
			strings->str_a[i] = ft_atoi(argv[i + 1]);
			length->len_a++;
		}
		i++;
	}
	return (0);
}

int			solved(t_len *length, t_str *strings)
{
	int		i;

	i = 0;
	while (i < length->len_a - 1)
	{
		if (strings->str_a[i] < strings->str_a[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int			solved_b(t_len *length, t_str *strings)
{
	int		i;

	i = 0;
	while (i < length->len_b - 1)
	{
		if (strings->str_b[i] < strings->str_b[i + 1])
			i++;
		else
			return (1);
	}
	return (0);
}

int			max_compare(char *str)
{
	if (ft_strlen(str) > 10)
		return (1);
	if ((ft_atoi(str) - 2147483647) > 0)
		return (1);
	return (0);
}

int			compare(int value, int *str, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		if (value == str[i])
			return (1);
		i++;
	}
	return (0);
}
