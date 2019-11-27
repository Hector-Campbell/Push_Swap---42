/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:08:25 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 19:34:09 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				int_strlen(unsigned int *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				sint_strlen(int *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int				ull_oct_len(unsigned long long int num)
{
	int i;

	i = 1;
	while (num /= 8)
		i++;
	return (i);
}

int				after_dot(char *str)
{
	int i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	return (i);
}

char			*tmp_creation(char *str, char *format, char c)
{
	char *tmp;

	tmp = NULL;
	if (c == 'o')
		tmp = ft_strdup("0");
	if (c == 'x' || c == 'X')
		tmp = hashsign_hex(format);
	else if (c == 'f')
		tmp = hashsign_float(str);
	return (tmp);
}
