/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 19:35:10 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 17:14:49 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*double_to_str(double num, char *format)
{
	char	*tmpstr;
	char	*newstr;
	int		sign;

	if (num < 0)
	{
		sign = -1;
		num = num * -1;
	}
	else
		sign = 1;
	tmpstr = dtoa(num, format);
	tmpstr = add_decimal(tmpstr, format);
	newstr = rounding(tmpstr, format);
	if (sign == -1 && newstr[0] != '-')
		newstr = ft_strjoin("-", newstr);
	else if (newstr[0] != '+')
		newstr = ft_strjoin("+", newstr);
	return (newstr);
}

char		*l_double_to_str(long double num, char *format)
{
	char		*tmpstr;
	char		*newstr;
	int			sign;

	if (num < 0)
	{
		sign = -1;
		num = num * -1;
	}
	else
		sign = 1;
	tmpstr = ldtoa(num, format);
	newstr = rounding(tmpstr, format);
	if (sign == -1 && newstr[0] != '-')
		newstr = ft_strjoin("-", newstr);
	else if (newstr[0] != '+')
		newstr = ft_strjoin("+", newstr);
	return (newstr);
}

char		*add_decimal(char *str, char *format)
{
	char	*tmp;
	int		pv;
	int		i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '.')
		return (str);
	pv = find_precision(format);
	i = pv + 1;
	tmp = (char *)malloc(sizeof(char) * (i + 2));
	tmp[i + 1] = '\0';
	tmp[0] = '.';
	while (pv >= 0)
	{
		tmp[i--] = '0';
		pv--;
	}
	str = ft_strjoin(str, tmp);
	return (str);
}
