/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_va_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 23:11:46 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:35:55 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*u_none(va_list lst_arg, char *format)
{
	unsigned int	arg;
	char			*str;

	arg = va_arg(lst_arg, unsigned int);
	if (arg == 0 && if_precision(format) == 3)
		str = NULL;
	else
		str = ft_itoa_ulong(arg);
	return (str);
}

char				*u_hh(va_list lst_arg, char *format)
{
	unsigned char	arg;
	char			*str;

	arg = va_arg(lst_arg, unsigned int);
	if (arg == 0 && if_precision(format) == 3)
		str = NULL;
	else
		str = ft_itoa_ulong(arg);
	return (str);
}

char				*u_h(va_list lst_arg, char *format)
{
	unsigned short int		arg;
	char					*str;

	arg = va_arg(lst_arg, unsigned int);
	if (arg == 0 && if_precision(format) == 3)
		str = NULL;
	else
		str = ft_itoa_ulong(arg);
	return (str);
}

char				*u_l(va_list lst_arg, char *format)
{
	unsigned long int		arg;
	char					*str;

	arg = va_arg(lst_arg, unsigned long int);
	if (arg == 0 && if_precision(format) == 3)
		str = NULL;
	else
		str = ft_itoa_ulong(arg);
	return (str);
}

char				*u_ll(va_list lst_arg, char *format)
{
	unsigned long long int	arg;
	char					*str;

	arg = va_arg(lst_arg, unsigned long long int);
	if (arg == 0 && if_precision(format) == 3)
		str = NULL;
	else
		str = ft_itoa_ulong(arg);
	return (str);
}
