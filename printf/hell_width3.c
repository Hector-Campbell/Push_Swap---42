/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hell_width3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 16:09:00 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/18 12:27:56 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*hell_right_space_with_sign(char *str, char *format)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("+", str);
		str = hell_right_space(str, format);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("-", str);
		str = hell_right_space(str, format);
	}
	else
		str = hell_right_space(str, format);
	return (str);
}

char		*hell_left_space_with_sign(char *str, char *format)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("+", str);
		str = hell_left_space(str, format);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("-", str);
		str = hell_left_space(str, format);
	}
	else
		str = hell_left_space(str, format);
	return (str);
}

char		*hell_right_space(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		i;

	width = hell_find_width(format);
	i = ft_strlen(str);
	width = width - i;
	tmp = (char *)malloc(sizeof(char) * (width + 1));
	tmp[width--] = '\0';
	while (width >= 0)
		tmp[width--] = ' ';
	tmp = ft_strjoin(str, tmp);
	return (tmp);
}

char		*hell_left_space(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		i;

	width = hell_find_width(format);
	i = ft_strlen(str);
	width = width - i;
	tmp = (char *)malloc(sizeof(char) * (width + 1));
	tmp[width--] = '\0';
	while (width >= 0)
		tmp[width--] = ' ';
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}
