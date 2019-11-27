/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_completion2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 19:56:09 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:35:26 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*str_completion(char *str, char *format)
{
	if (format == NULL)
		return (str);
	if (arg_value(format) == 'u' && str != NULL)
		str = remove_sign(str);
	if (if_precision(format) == 1 && arg_value2(format) != 'c')
		str = precision_split(str, format);
	if (if_sign(format) == 0 && arg_value(format) != 's' && arg_value2(format)
			!= 'u' && arg_value2(format) != 'c')
		str = sign(str, format);
	if (if_hashsign(format) == 1 && if_width(format) != 2)
		str = hashsign_0x(str, format);
	if (if_right(format) == 1)
		str = right_width(str, format);
	else if ((if_width(format) == 1 || if_width(format) == 2)
			&& (if_str(format) == 2 && width_precision_confusion(format) == 2))
		str = left_width(str, format);
	if (str == NULL)
		return (NULL);
	return (str);
}

int			if_str(char *format)
{
	int i;

	i = 0;
	while (format[i] != '%' && format[i] != '\0')
		i++;
	if (format[i] == '%')
		return (2);
	return (1);
}

int			width_precision_confusion(char *format)
{
	int i;

	i = 0;
	while (format[i] != '\0' && format[i] != '.')
		i++;
	if (format[i] == '.')
	{
		i--;
		if (format[i] >= '0' && format[i] <= '9')
			return (2);
	}
	else if (if_width(format) == 1 || if_width(format) == 2)
		return (2);
	return (1);
}

char		**pure_str(char *format)
{
	char	*tmp;
	int		i;
	int		len;
	char	**str;
	int		ret;

	i = 0;
	len = ft_strlen(format);
	str = (char **)malloc(sizeof(char *) * (3));
	while (format[i] != '%' && format[i] != '\0')
		i++;
	tmp = ft_strsub(format, 0, i);
	ret = ft_putstr2(tmp);
	str[1] = ft_itoa(ret);
	str[0] = ft_strsub(format, i, len);
	return (str);
}

char		*remove_sign(char *str)
{
	char *tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
	}
	return (str);
}
