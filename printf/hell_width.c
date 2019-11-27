/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_width.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:04:10 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 12:17:03 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*hell_right_width(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		check;
	int		i;

	check = if_width(format);
	width = hell_find_width(format);
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
			return (hell_right_zero_with_sign(str, format));
		else
			return (hell_right_space_with_sign(str, format));
	}
	return (str);
}

char		*hell_left_width(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		check;
	int		i;

	check = if_width(format);
	width = hell_find_width(format);
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
			return (hell_left_zero_with_sign(str, format));
		else
			return (hell_left_space_with_sign(str, format));
	}
	return (str);
}

int			hell_find_width(char *format)
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
			if (arg_value(format) == 'c')
				start = start - 1;
			return (start);
		}
		i++;
	}
	return (start);
}
