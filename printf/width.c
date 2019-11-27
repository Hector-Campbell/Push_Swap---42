/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 21:39:10 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:36:09 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			if_width(char *format)
{
	int i;
	int check;
	int	width;
	int zero;

	i = 0;
	check = 0;
	width = 0;
	zero = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '0')
		{
			check = num_check(format[i - 1]);
			if (check == 2)
				zero = 1;
		}
		if (format[i] >= '1' && format[i] <= '9')
			width = 1;
		i++;
	}
	if (width == 1 && zero == 1)
		width = 2 - if_right(format);
	return (width);
}

int			if_right(char *format)
{
	int	check;
	int i;

	i = 0;
	check = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '-')
		{
			check++;
			break ;
		}
		i++;
	}
	return (check);
}

char		*right_width(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		check;
	int		i;

	check = if_width(format);
	width = find_width(format);
	i = 0;
	if (str == NULL)
	{
		str = (char *)malloc(sizeof(char) * (1));
		str[0] = '\0';
	}
	i = ft_strlen(str);
	width = width - i;
	if (width > 0)
	{
		tmp = (char *)malloc(sizeof(char) * (width + 1));
		tmp[width--] = '\0';
		if (check == 2 && if_precision(format) == 2)
			return (right_zero_with_sign(str, format));
		else
			return (right_space_with_sign(str, format));
	}
	return (str);
}

char		*left_width(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		check;
	int		i;

	check = if_width(format);
	width = find_width(format);
	i = 0;
	if (str == NULL)
	{
		str = (char *)malloc(sizeof(char) * (1));
		str[0] = '\0';
	}
	i = ft_strlen(str);
	width = width - i;
	if (width > 0)
	{
		tmp = (char *)malloc(sizeof(char) * (width + 1));
		tmp[width--] = '\0';
		if (check == 2 && if_precision(format) == 2)
			return (left_zero_with_sign(str, format));
		else
			return (left_space_with_sign(str, format));
	}
	return (str);
}

int			find_width(char *format)
{
	int		i;
	int		start;
	char	*tmp;

	i = 0;
	start = 0;
	tmp = NULL;
	while (format[i] != '\0' && format[i] != '.')
	{
		if (format[i] >= '1' && format[i] <= '9')
		{
			start = i;
			while (format[i] >= '0' && format[i] <= '9')
				i++;
			tmp = ft_strsub(format, start, i);
			start = ft_atoi(tmp);
			return (start);
		}
		i++;
	}
	return (start);
}
