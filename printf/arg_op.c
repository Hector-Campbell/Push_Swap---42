/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:13:35 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 11:18:29 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*d_split(va_list lst_arg, char *format)
{
	int		check;
	char	*str;

	check = specifier_finder(format);
	if (check == 1)
		str = d_hh(lst_arg, format);
	if (check == 2)
		str = d_h(lst_arg, format);
	if (check == 3)
		str = d_l(lst_arg, format);
	if (check == 4)
		str = d_ll(lst_arg, format);
	if (check == 0)
		str = d_none(lst_arg, format);
	return (str);
}

char		*o_split(va_list lst_arg, char *format)
{
	int		check;
	char	*str;

	check = specifier_finder(format);
	if (check == 1)
		str = o_hh(lst_arg, format);
	if (check == 2)
		str = o_h(lst_arg, format);
	if (check == 3)
		str = o_l(lst_arg, format);
	if (check == 4)
		str = o_ll(lst_arg, format);
	if (check == 0)
		str = o_none(lst_arg, format);
	return (str);
}

char		*u_split(va_list lst_arg, char *format)
{
	int		check;
	char	*str;

	check = specifier_finder(format);
	if (check == 1)
		str = u_hh(lst_arg, format);
	if (check == 2)
		str = u_h(lst_arg, format);
	if (check == 3)
		str = u_l(lst_arg, format);
	if (check == 4)
		str = u_ll(lst_arg, format);
	if (check == 0)
		str = u_none(lst_arg, format);
	return (str);
}

char		*x_split(va_list lst_arg, char *format)
{
	int		check;
	char	c;
	char	*str;

	check = specifier_finder(format);
	c = arg_value(format);
	if (check == 1)
		str = x_hh(lst_arg, format);
	if (check == 2)
		str = x_h(lst_arg, format);
	if (check == 3)
		str = x_l(lst_arg, format);
	if (check == 4)
		str = x_ll(lst_arg, format);
	if (check == 0)
		str = x_none(lst_arg, format);
	if (c == 88)
		str = make_capital(str);
	return (str);
}

char		*c_split(va_list lst_arg, char *format)
{
	char	arg;
	char	*str;

	arg = va_arg(lst_arg, int);
	if (arg == 0)
	{
		str = the_string_ender(arg, format);
		return (str);
	}
	else
	{
		str = (char *)malloc(sizeof(char) * 2);
		str[0] = arg;
		str[1] = '\0';
	}
	return (str);
}
