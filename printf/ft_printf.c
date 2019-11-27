/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:27:46 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:30:27 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(char *format, ...)
{
	va_list lst_arg;
	char	**str;
	int		ret;
	int		check;
	char	**big_str;

	ret = 0;
	str = NULL;
	check = 0;
	big_str = NULL;
	va_start(lst_arg, format);
	ret = ft_printf_loop(format, big_str, str, lst_arg);
	va_end(lst_arg);
	return (ret);
}

int			ft_printf_loop(char *format, char **big_str, char **str,
		va_list lst_arg)
{
	int ret;
	int check;

	ret = 0;
	check = 0;
	while (format != NULL)
	{
		if (format[0] == '%' && format[1] == '\0')
			return (0);
		if (check == 0)
		{
			str = format_splitter(format);
			check++;
		}
		else
			str = format_splitter(str[1]);
		big_str = arg_split(lst_arg, str[0]);
		ret = ret + ft_putstr2(big_str[0]) + ft_atoi(big_str[1]);
		if (str[1] == NULL)
			break ;
	}
	return (ret);
}
