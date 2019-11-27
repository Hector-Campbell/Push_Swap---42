/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_va_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:15:50 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/17 18:41:39 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*d_none(va_list lst_arg, char *format)
{
	int		arg;
	char	*str;

	arg = va_arg(lst_arg, int);
	if (arg == 0 && if_precision(format) == 3)
		return (NULL);
	str = ft_itoa2(arg);
	return (str);
}

char		*d_hh(va_list lst_arg, char *format)
{
	signed char		arg;
	char			*str;

	arg = va_arg(lst_arg, int);
	if (arg == 0 && (if_precision(format) == 1 || if_precision(format) == 3))
		return (NULL);
	str = ft_itoa2(arg);
	return (str);
}

char		*d_h(va_list lst_arg, char *format)
{
	short int		arg;
	char			*str;

	arg = va_arg(lst_arg, int);
	if (arg == 0 && (if_precision(format) == 1 || if_precision(format) == 3))
		return (NULL);
	str = ft_itoa2(arg);
	return (str);
}

char		*d_l(va_list lst_arg, char *format)
{
	long int		arg;
	char			*str;

	arg = va_arg(lst_arg, long int);
	if (arg == 0 && (if_precision(format) == 1 || if_precision(format) == 3))
		return (NULL);
	if (arg == LONG_MIN)
		str = ft_strdup("-9223372036854775808");
	else
		str = ft_itoa_long(arg);
	return (str);
}

char		*d_ll(va_list lst_arg, char *format)
{
	long long int	arg;
	char			*str;

	arg = va_arg(lst_arg, long long int);
	if (arg == 0 && (if_precision(format) == 1 || if_precision(format) == 3))
		return (NULL);
	if (arg == LLONG_MIN)
		str = ft_strdup("-9223372036854775808");
	else
		str = ft_itoa_long(arg);
	return (str);
}
