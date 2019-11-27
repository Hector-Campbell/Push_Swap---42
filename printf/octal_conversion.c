/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:53:28 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/17 16:56:41 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*octal_conversion(unsigned int num, char *format)
{
	char			*str;
	int				i;
	int				len;
	unsigned int	tmp;

	i = 0;
	len = ull_oct_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	if (num == 0 && if_precision(format) == 2 && if_hashsign(format) != 1)
		str[0] = '0';
	while (num != 0)
	{
		tmp = num % 8;
		str[i] = (char)(tmp + 48);
		num = num / 8;
		i++;
	}
	return (str);
}

char		*octal_conversion_long(unsigned long int num, char *format)
{
	char				*str;
	int					i;
	int					len;
	unsigned long int	tmp;

	i = 0;
	len = ull_oct_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (num == 0 && if_precision(format) != 1 && if_hashsign(format) != 1)
		str[0] = '0';
	while (num != 0)
	{
		tmp = num % 8;
		str[i] = (char)(tmp + 48);
		num = num / 8;
		i++;
	}
	return (str);
}

char		*octal_conversion_longx2(unsigned long long int num, char *format)
{
	char					*str;
	int						i;
	int						len;
	unsigned long long int	tmp;

	i = 0;
	len = ull_oct_len(num);
	str = (char *)malloc(sizeof(char) * (len + 1));
	str[len] = '\0';
	if (num == 0 && if_precision(format) == 2 && if_hashsign(format) != 1)
		str[0] = '0';
	if (num == 0 && if_precision(format) == 3)
		str[len] = '\0';
	while (num != 0)
	{
		tmp = num % 8;
		str[i] = (char)(tmp + 48);
		num = num / 8;
		i++;
	}
	return (str);
}
