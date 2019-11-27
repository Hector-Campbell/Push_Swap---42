/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:32:55 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 11:38:19 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			specifier_finder(char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == 'h')
		{
			if (format[i + 1] == 'h')
				return (1);
			else
				return (2);
		}
		if (format[i] == 'l')
		{
			if (format[i + 1] == 'l')
				return (4);
			else
				return (3);
		}
		if (format[i] == 'L')
			return (5);
		i++;
	}
	return (0);
}

char		arg_value(char *format)
{
	int		i;
	char	c;

	i = 0;
	c = 'H';
	while (format[i] != '\0')
	{
		if (format[i] == 'd' || format[i] == 'i' || format[i] == 'o' ||
				format[i] == 'u' || format[i] == 'x' || format[i] == 'X' ||
				format[i] == 'f' || format[i] == 'c' || format[i] == 's' ||
				format[i] == 'p')
		{
			c = format[i];
			break ;
		}
		i++;
	}
	return (c);
}

char		**arg_split(va_list lst_arg, char *format)
{
	char	c;
	char	*str;
	char	**big_str;

	str = NULL;
	big_str = pure_str(format);
	format = big_str[0];
	c = arg_value(format);
	if (c == 'c')
	{
		str = c_split(lst_arg, format);
		if (str == NULL)
		{
			big_str[1] = number_merge(format, big_str[1]);
			big_str[0] = NULL;
			return (big_str);
		}
	}
	else
		str = arg_split_cont(lst_arg, format, c, str);
	big_str[0] = str_completion(str, format);
	return (big_str);
}

char		*arg_split_cont(va_list lst_arg, char *format, char c, char *str)
{
	if (c == 'd' || c == 'i')
		str = d_split(lst_arg, format);
	if (c == 'o')
		str = str_rev(o_split(lst_arg, format));
	else if (c == 'u')
		str = u_split(lst_arg, format);
	else if (c == 'x' || c == 'X')
		str = str_rev(x_split(lst_arg, format));
	else if (c == 'f')
		str = f_split(lst_arg, format);
	else if (c == 's')
		str = s_split(lst_arg, format);
	else if (c == 'p')
		str = p_split(lst_arg, format);
	else if (c == 'H')
		str = percent_split(c, format);
	return (str);
}
