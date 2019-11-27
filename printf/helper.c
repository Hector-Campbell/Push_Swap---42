/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 15:53:49 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 13:59:52 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putstr2(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	i = ft_strlen(str);
	write(1, str, i);
	return (i);
}

char		*make_capital(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int			num_strlen(unsigned int n)
{
	int i;

	i = 1;
	while (n /= 5)
		i++;
	return (i);
}

int			num_check(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (2);
}

int			hex_len(uint64_t num)
{
	int i;

	i = 1;
	while (num /= 16)
		i++;
	return (i);
}
