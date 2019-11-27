/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:58:20 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 17:48:48 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			find_precision(char *format)
{
	size_t			i;
	unsigned int	start;
	char			*str;
	int				amount;

	i = 0;
	start = 0;
	str = NULL;
	amount = 0;
	while (format[i] != '.' && format[i] != '\0')
		i++;
	if (format[i] == '\0')
		return (6);
	i++;
	start = i;
	while (format[i] >= '0' && format[i] <= '9')
		i++;
	i = i - 1;
	str = ft_strsub(format, start, i);
	amount = ft_atoi(str);
	if (arg_value(format) == 'd' || arg_value(format) == 'i')
		amount = amount + 1;
	return (amount);
}

int			if_precision(char *format)
{
	int i;
	int check;
	int decimal;

	i = 0;
	check = 0;
	decimal = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '.' && format[i] != '\0')
		{
			if (format[i + 1] >= '1' && format[i + 1] <= '9')
				check = 1;
			decimal = 1;
		}
		i++;
	}
	if (check == 0 && decimal == 1)
		check = 3;
	if (check == '\0')
		check = 2;
	return (check);
}

char		*precision_float(char *str, char *format, int pv)
{
	int i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
	{
		if (str[i] == '\0')
			str = decimal_and_pv(str, pv);
		i++;
	}
	i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		pv--;
		i++;
	}
	if (pv > 0)
		str = too_short_float(str, pv);
	if (pv < 0)
		str = too_long_float(str, format);
	return (str);
}

char		*precision_digit(char *str, int pv)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = NULL;
	while (str[i] != '\0')
	{
		pv--;
		i++;
	}
	if (pv > 0)
	{
		newstr = (char *)malloc(sizeof(char) * (pv + 1));
		newstr[pv--] = '\0';
		while (pv >= 0)
			newstr[pv--] = '0';
		return (rearrange(ft_strjoin(newstr, str)));
	}
	return (str);
}

char		*precision_string(char *str, int pv)
{
	char	*newstr;
	int		len;
	int		i;

	len = ft_strlen(str);
	newstr = NULL;
	i = 0;
	if (pv < len)
	{
		newstr = (char *)malloc(sizeof(char) * (pv + 1));
		newstr[pv] = '\0';
		while (i < pv)
		{
			newstr[i] = str[i];
			i++;
		}
		return (newstr);
	}
	return (str);
}
