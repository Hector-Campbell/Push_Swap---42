/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_op2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 00:21:51 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 11:18:41 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*s_split(va_list lst_arg, char *format)
{
	char	*arg;

	arg = va_arg(lst_arg, char *);
	if (arg == NULL)
		arg = ft_strdup("(null)");
	if (if_precision(format) == 3)
		arg = NULL;
	return (arg);
}

char		*f_split(va_list lst_arg, char *format)
{
	long double	arg;
	char		*str;
	int			check;

	check = specifier_finder(format);
	if (check == 5)
	{
		arg = va_arg(lst_arg, long double);
		str = l_double_to_str(arg, format);
	}
	else
	{
		arg = va_arg(lst_arg, double);
		str = double_to_str(arg, format);
	}
	return (str);
}

char		*p_split(va_list lst_arg, char *format)
{
	char	*str;
	void	*arg;

	arg = va_arg(lst_arg, void *);
	str = pointer_to_str(arg, format);
	return (str);
}

char		*percent_split(char c, char *format)
{
	char	*str;
	int		i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i++;
	c = format[i];
	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c;
	str[1] = '\0';
	return (str);
}
