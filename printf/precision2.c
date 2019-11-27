/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 16:56:21 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 19:15:17 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*precision_split(char *str, char *format)
{
	char	c;
	char	*newstr;
	int		pv;

	c = arg_value(format);
	newstr = NULL;
	pv = find_precision(format);
	if (pv == 0)
		return (str);
	if (c == 'f')
		newstr = precision_float(str, format, pv);
	else if (c == 'd' || c == 'i' || c == 'o' || c == 'x' || c == 'X' ||
			c == 'u')
		newstr = precision_digit(str, pv);
	else if (c == 's')
		newstr = precision_string(str, pv);
	else if (c == 'p')
		newstr = precision_pointer(str, pv + 2);
	return (newstr);
}

char		*too_long_float(char *str, char *format)
{
	char *newstr;

	newstr = rounding(str, format);
	return (newstr);
}

char		*too_short_float(char *str, int pv)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (pv + 1));
	newstr[pv] = '\0';
	i = 0;
	while (pv > i)
		newstr[i++] = '0';
	newstr = ft_strjoin(str, newstr);
	return (newstr);
}

char		*decimal_and_pv(char *str, int pv)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (pv + 2));
	newstr[pv] = '\0';
	newstr[i] = '.';
	i++;
	while (newstr[i] != '\0')
		newstr[i++] = '0';
	newstr = ft_strjoin(str, newstr);
	return (newstr);
}

char		*too_short_integer(char *str, int pv)
{
	char	*newstr;
	int		i;

	i = 0;
	newstr = (char *)malloc(sizeof(char) * (pv + 1));
	newstr[pv] = '\0';
	while (i >= pv)
		newstr[i++] = '0';
	newstr = ft_strjoin(newstr, str);
	return (newstr);
}
