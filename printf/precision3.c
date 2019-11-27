/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 09:42:29 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 14:34:44 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*rearrange(char *str)
{
	char *tmp;

	if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("-", str);
	}
	else if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("+", str);
	}
	return (str);
}

char		*precision_pointer(char *str, int pv)
{
	int		i;
	char	*newstr;
	int		len;

	i = 0;
	newstr = NULL;
	len = ft_strlen(str);
	while (str[i] != '\0')
	{
		pv--;
		i++;
	}
	if (pv > 0)
	{
		newstr = (char *)malloc(sizeof(char) * (pv + 1));
		newstr[pv--] = '\0';
		while (pv >= 0)
			newstr[pv--] = '0';
		newstr = ft_strjoin("0x", newstr);
		str = ft_strsub(str, 2, len);
		return (rearrange(ft_strjoin(newstr, str)));
	}
	return (str);
}
