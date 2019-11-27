/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_va_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 22:52:31 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/17 16:43:02 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*o_none(va_list lst_arg, char *format)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(lst_arg, unsigned int);
	str = octal_conversion(arg, format);
	return (str);
}

char		*o_hh(va_list lst_arg, char *format)
{
	unsigned char	arg;
	char			*str;

	arg = va_arg(lst_arg, unsigned int);
	str = octal_conversion(arg, format);
	return (str);
}

char		*o_h(va_list lst_arg, char *format)
{
	unsigned short int	arg;
	char				*str;

	arg = va_arg(lst_arg, unsigned int);
	str = octal_conversion(arg, format);
	return (str);
}

char		*o_l(va_list lst_arg, char *format)
{
	unsigned long int	arg;
	char				*str;

	arg = va_arg(lst_arg, unsigned long int);
	str = octal_conversion_long(arg, format);
	return (str);
}

char		*o_ll(va_list lst_arg, char *format)
{
	unsigned long long int	arg;
	char					*str;

	arg = va_arg(lst_arg, unsigned long long int);
	str = octal_conversion_longx2(arg, format);
	return (str);
}
