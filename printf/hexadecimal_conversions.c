/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexadecimal_conversions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 22:24:44 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/17 15:43:09 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*hexadecimal_conversion(unsigned int num, char *format)
{
	char			*str;
	int				i;
	int				j;
	unsigned int	tmp;
	int				len;

	i = 0;
	j = 0;
	len = hex_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	if (num == 0 && if_precision(format) == 2)
		str[len] = '0';
	if (num == 0 && if_precision(format) == 3)
		str[len] = '\0';
	while (num != 0)
	{
		tmp = num % 16;
		if (tmp < 10)
			str[i++] = (char)(tmp + 48);
		else
			str[i++] = (char)(tmp + 87);
		num = num / 16;
	}
	return (str);
}

char		*hexadecimal_conversion_long(unsigned long int num, char *format)
{
	char				*str;
	int					i;
	int					j;
	unsigned long int	tmp;
	int					len;

	i = 0;
	j = 0;
	len = hex_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	if (num == 0 && if_precision(format) != 1)
		str[len] = '0';
	while (num != 0)
	{
		tmp = num % 16;
		if (tmp < 10)
			str[i] = (char)(tmp + 48);
		else
			str[i] = (char)(tmp + 87);
		num = num / 16;
		i++;
	}
	return (str);
}

char		*hexadecimal_conversion_longx2(unsigned long long int num,
		char *format)
{
	char					*str;
	int						i;
	int						j;
	unsigned long long int	tmp;
	int						len;

	i = 0;
	j = 0;
	len = hex_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	if (num == 0 && if_precision(format) != 1)
		str[len] = '0';
	while (num != 0)
	{
		tmp = num % 16;
		if (tmp < 10)
			str[i] = (char)(tmp + 48);
		else
			str[i] = (char)(tmp + 87);
		num = num / 16;
		i++;
	}
	return (str);
}
