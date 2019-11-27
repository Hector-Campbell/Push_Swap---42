/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_completion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 16:17:06 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/15 23:56:37 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			if_sign(char *format)
{
	int check;
	int i;

	i = 0;
	check = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '+')
		{
			check++;
			break ;
		}
		i++;
	}
	return (check);
}

int			if_hashsign(char *format)
{
	int check;
	int i;

	i = 0;
	check = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '#')
		{
			check++;
			break ;
		}
		i++;
	}
	return (check);
}

int			if_space(char *format)
{
	int check;
	int	i;

	i = 0;
	check = 0;
	while (format[i] != '\0')
	{
		if (format[i] == ' ')
		{
			check++;
			break ;
		}
		i++;
	}
	return (check);
}
