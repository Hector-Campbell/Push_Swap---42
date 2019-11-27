/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 16:55:51 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:34:11 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		*pointer_to_str(void *arg, char *format)
{
	char	*newstr;

	newstr = hexadecimal_conversion_longx2((unsigned long)arg, format);
	newstr = str_rev(newstr);
	if (if_precision(format) == 3 && find_precision(format) == 0)
		newstr = ft_strdup("0x");
	else
		newstr = ft_strjoin("0x", newstr);
	return (newstr);
}
