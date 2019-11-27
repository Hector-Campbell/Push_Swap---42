/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 02:00:25 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/06 02:43:57 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			octal_num(unsigned int num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num /= 8;
		i++;
	}
	return (i);
}

int			hexadecimal_num(unsigned int num)
{
	int i;

	i = 0;
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}
