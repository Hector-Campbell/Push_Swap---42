/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 19:28:52 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 12:12:05 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		**format_splitter(char *format)
{
	size_t	i;
	int		check;
	char	c;

	i = 0;
	check = 0;
	c = arg_value2(format);
	while (format[i] != '\0' && check == 0)
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] != '\0' && check == 0)
			{
				if (format[i] == c && c != 'H')
					check = 1;
				if (check == 0)
					i++;
			}
		}
		if (check == 0 && format[i] != '\0')
			i++;
	}
	return (format_return(format, ++i, ft_strlen(format) + 1));
}

char		**format_return(char *format, size_t i, int len)
{
	char	**str;
	char	*str2;

	str = (char **)malloc(sizeof(char *) * (3));
	str2 = format;
	if (format[i] == '\0')
	{
		str[0] = ft_strdup(str2);
		str[1] = NULL;
		return (str);
	}
	str[0] = ft_strsub(str2, 0, i);
	str[1] = ft_strsub(str2, i, len);
	return (str);
}

char		arg_value2(char *format)
{
	char	c;
	int		i;

	i = 0;
	c = 'H';
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			while (format[i] != '\0')
			{
				if (format[i] == 'd' || format[i] == 'i' || format[i] == 'o' ||
				format[i] == 'u' || format[i] == 'x' || format[i] == 'X' ||
				format[i] == 'f' || format[i] == 'c' || format[i] == 's' ||
				format[i] == 'p' || format[i] == '%')
					return (format[i]);
				i++;
			}
		}
		i++;
	}
	return (c);
}
