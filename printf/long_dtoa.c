/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_dtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:31:50 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 15:20:15 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ldtoa(long double num, char *format)
{
	char			*str;
	long long int	whole;
	long double		decimal;
	int				afterpoint;

	str = NULL;
	if (num != num)
		return (special_case(format));
	whole = (long long int)num;
	decimal = num - (long double)whole;
	str = ft_itoa3(whole);
	afterpoint = find_decpart_l(decimal, format);
	if (afterpoint != 0)
	{
		str = ft_strjoin(str, ".");
		whole = decimal * power(10, afterpoint);
		str = ft_strjoin(str, ft_itoa3(whole));
	}
	return (str);
}

int			find_decpart_l(long double num, char *format)
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

char		*ft_itoa3(long long int n)
{
	long long int	tmp;
	size_t			len;
	char			*str;
	long long int	sign;

	if (n < 0)
	{
		tmp = -n;
		sign = -1;
	}
	else
	{
		tmp = n;
		sign = 1;
	}
	len = long_strlen(n);
	str = ft_strnew(len);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	return (str);
}

char		*special_case(char *format)
{
	char	*str;
	int		pv;

	pv = find_precision(format) + 1;
	str = (char *)malloc(sizeof(char) * (pv + 1));
	str[pv--] = '\0';
	while (pv >= 0)
		str[pv--] = '0';
	str = ft_strjoin("0.", str);
	return (str);
}
