/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 15:14:29 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:30:47 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*the_string_ender(char satan, char *format)
{
	char	*str;
	int		value;

	str = NULL;
	if (if_right(format) == 1)
		str = hell_right_width(str, format);
	else if ((if_width(format) == 1 || if_width(format) == 2)
			&& (if_str(format) == 2 && width_precision_confusion(format) == 2))
		str = hell_left_width(str, format);
	value = ft_putstr2(str) + 1;
	ft_putchar(satan);
	return (NULL);
}

char		*number_merge(char *str, char *big_str)
{
	int		value;
	char	*tmp;

	value = hell_find_width(str) + 1 + ft_atoi(big_str);
	tmp = ft_itoa(value);
	return (tmp);
}
