/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 21:18:54 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 15:19:43 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_long(long long int n)
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
	len = long_strlen(n) + 1;
	str = ft_strnew(len);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	if (n < 0)
		*(str + 0) = '-';
	else
		*(str + 0) = '+';
	return (str);
}

char		*ft_itoa_ulong(unsigned long long int n)
{
	unsigned long long int	tmp;
	size_t					len;
	char					*str;

	tmp = n;
	len = ulong_strlen(n);
	str = ft_strnew(len);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	return (str);
}

int			long_strlen(long long int num)
{
	int i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}

char		*special_split(char *str, char *tmp)
{
	char	*first;
	char	*second;

	*tmp++ = '\0';
	first = ft_strdup(str);
	second = ft_strdup(tmp);
	str = ft_strjoin(first, second);
	return (str);
}

int			ulong_strlen(unsigned long long int num)
{
	int i;

	i = 1;
	while (num /= 10)
		i++;
	return (i);
}
