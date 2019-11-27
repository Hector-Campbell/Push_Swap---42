/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:09:46 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:31:42 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*str_rev(char *str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j + 1] != '\0')
		j++;
	tmp = (char *)malloc(sizeof(char) * (j + 1));
	tmp[j + 1] = '\0';
	while (str[i] != '\0')
		tmp[j--] = str[i++];
	return (tmp);
}

int			snum_strlen(int n)
{
	int i;

	i = 0;
	while (n /= 10)
		i++;
	i = i + 2;
	return (i);
}

long int	power(int x, int n)
{
	int i;
	int	number;

	i = 0;
	number = 1;
	while (i < n)
	{
		number = number * x;
		i++;
	}
	return (number);
}

char		*ft_itoa2(int n)
{
	unsigned int	tmp;
	size_t			len;
	char			*str;
	int				sign;

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
	len = snum_strlen(n);
	str = ft_strnew(len + 2);
	str[--len] = tmp % 10 + 48;
	while (tmp /= 10)
		str[--len] = tmp % 10 + 48;
	if (n < 0)
		*(str + 0) = '-';
	else
		*(str + 0) = '+';
	return (str);
}

int			oct_len(unsigned int num)
{
	int i;

	i = 1;
	while (num /= 8)
		i++;
	return (i);
}
