/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_va_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:12:31 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:36:49 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*x_none(va_list lst_arg, char *format)
{
	unsigned int	arg;
	char			*str;

	str = NULL;
	arg = va_arg(lst_arg, unsigned int);
	str = hexadecimal_conversion(arg, format);
	return (str);
}

char			*x_hh(va_list lst_arg, char *format)
{
	unsigned char	arg;
	char			*str;

	str = NULL;
	arg = va_arg(lst_arg, unsigned int);
	str = hexadecimal_conversion(arg, format);
	return (str);
}

char			*x_h(va_list lst_arg, char *format)
{
	unsigned short int	arg;
	char				*str;

	str = NULL;
	arg = va_arg(lst_arg, unsigned int);
	str = hexadecimal_conversion(arg, format);
	return (str);
}

char			*x_l(va_list lst_arg, char *format)
{
	unsigned long int	arg;
	char				*str;

	str = NULL;
	arg = va_arg(lst_arg, unsigned long int);
	str = hexadecimal_conversion_long(arg, format);
	return (str);
}

char			*x_ll(va_list lst_arg, char *format)
{
	unsigned long long int	arg;
	char					*str;

	str = NULL;
	arg = va_arg(lst_arg, unsigned long long int);
	str = hexadecimal_conversion_longx2(arg, format);
	return (str);
}
