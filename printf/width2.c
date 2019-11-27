/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 11:33:04 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/17 20:33:09 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*right_zero(char *str, char *format, int num)
{
	int		width;
	char	*tmp;

	width = find_width(format) - ft_strlen(str) - num;
	if (if_hashsign(format) == 1)
	{
		if (arg_value(format) == 'x' || arg_value(format) == 'X')
			width = width - 2;
		else if (arg_value(format) == 'o')
			width = width - 1;
		tmp = (char *)malloc(sizeof(char) * (width + 1));
		tmp[width--] = '\0';
		while (width >= 0 && if_precision(format) == 2)
			tmp[width--] = '0';
		tmp = hashsign_0x(ft_strjoin(str, tmp), format);
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (width + 1));
		tmp[width--] = '\0';
		while (width >= 0 && if_precision(format) == 2)
			tmp[width--] = '0';
		tmp = ft_strjoin(str, tmp);
	}
	return (tmp);
}

char		*left_zero(char *str, char *format, int num)
{
	int		width;
	char	*tmp;

	width = find_width(format) - ft_strlen(str) - num;
	if (if_hashsign(format) == 1)
	{
		if (arg_value(format) == 'x' || arg_value(format) == 'X')
			width = width - 2;
		else if (arg_value(format) == 'o')
			width = width - 1;
		tmp = (char *)malloc(sizeof(char) * (width + 1));
		tmp[width--] = '\0';
		while (width >= 0 && if_precision(format) == 2)
			tmp[width--] = '0';
		tmp = hashsign_0x(ft_strjoin(tmp, str), format);
	}
	else
	{
		tmp = (char *)malloc(sizeof(char) * (width + 1));
		tmp[width--] = '\0';
		while (width >= 0 && if_precision(format) == 2)
			tmp[width--] = '0';
		tmp = ft_strjoin(tmp, str);
	}
	return (tmp);
}

char		*right_zero_with_sign(char *str, char *format)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = right_zero(str, format, 1);
		str = ft_strjoin("+", str);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = right_zero(str, format, 1);
		str = ft_strjoin("-", str);
	}
	else if ((tmp = ft_strchr(str, ' ')) && arg_value2(format) != 's')
	{
		str = special_split(str, tmp);
		str = right_zero(str, format, 1);
		str = ft_strjoin(" ", str);
	}
	else
		str = right_zero(str, format, 0);
	return (str);
}

char		*left_zero_with_sign(char *str, char *format)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = left_zero(str, format, 1);
		str = ft_strjoin("+", str);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = left_zero(str, format, 1);
		str = ft_strjoin("-", str);
	}
	else if ((tmp = ft_strchr(str, ' ')) && arg_value2(format) != 's')
	{
		str = special_split(str, tmp);
		str = left_zero(str, format, 1);
		str = ft_strjoin(" ", str);
	}
	else
		str = left_zero(str, format, 0);
	return (str);
}
