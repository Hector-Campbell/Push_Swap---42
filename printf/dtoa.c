/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:55:49 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 18:22:08 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*dtoa(double num, char *format)
{
	char			*str;
	long long int	whole;
	double			decimal;
	int				afterpoint;

	str = NULL;
	whole = (long long int)num;
	decimal = num - (double)whole;
	str = ft_itoa3(whole);
	afterpoint = find_decpart(decimal, format);
	if (afterpoint != 0)
	{
		str = ft_strjoin(str, ".");
		whole = decimal * power(10, afterpoint);
		str = ft_strjoin(str, ft_itoa3(whole));
	}
	return (str);
}

int			find_decpart(double num, char *format)
{
	int		tmp;
	int		count;
	int		precision;

	count = 0;
	precision = find_precision(format) + 1;
	while (num != 0 && count != precision)
	{
		num = num * 10;
		tmp = (long long int)num;
		num = num - tmp;
		count++;
	}
	return (count);
}

char		*rounding(char *str, char *format)
{
	int		precision_value;
	int		i;
	int		tmp;

	precision_value = find_precision(format);
	i = 0;
	tmp = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	i = i + precision_value + 0;
	if (str[i + 1] >= '5')
	{
		if (str[i] == '9')
		{
			while (str[i] == '9')
				str = rounding_help(str, i);
		}
		else
			str[i] = (str[i] + 1);
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

char		*rounding_help(char *str, int i)
{
	while (str[i] == '9')
	{
		if (str[i - 1] == '.')
		{
			str = the_dot(str, i);
			break ;
		}
		else if (str[i - 1] == '9')
			str[i--] = '0';
		else if (str[i - 1] >= '0' && str[i - 1] <= '8')
		{
			str[i--] = '0';
			str[i] = (str[i] + 1);
			break ;
		}
	}
	return (str);
}

char		*the_dot(char *str, int i)
{
	str[i--] = '0';
	i--;
	if (str[i] == '9')
	{
		while (str[i] == '9')
		{
			if (i == 0)
			{
				str[0] = '0';
				str = ft_strjoin("1", str);
			}
			if (str[i - 1] == '9')
				str[i--] = '0';
			if (str[i - 1] >= '0' && str[i - 1] <= '8')
			{
				str[i--] = '0';
				str[i] = (str[i] + 1);
				break ;
			}
		}
	}
	else
		str[i] = (str[i] + 1);
	return (str);
}
