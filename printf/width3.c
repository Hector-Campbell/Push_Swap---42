/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 08:48:50 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/17 20:36:20 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*right_space_with_sign(char *str, char *format)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("+", str);
		str = right_space(str, format);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("-", str);
		str = right_space(str, format);
	}
	else if ((tmp = ft_strchr(str, ' ')) && arg_value2(format) != 's')
	{
		str = special_split(str, tmp);
		str = ft_strjoin(" ", str);
		str = right_space(str, format);
	}
	else
		str = right_space(str, format);
	return (str);
}

char		*left_space_with_sign(char *str, char *format)
{
	char	*tmp;

	if ((tmp = ft_strchr(str, '+')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("+", str);
		str = left_space(str, format);
	}
	else if ((tmp = ft_strchr(str, '-')))
	{
		str = special_split(str, tmp);
		str = ft_strjoin("-", str);
		str = left_space(str, format);
	}
	else if ((tmp = ft_strchr(str, ' ')) && arg_value2(format) != 's')
	{
		str = special_split(str, tmp);
		str = ft_strjoin(" ", str);
		str = left_space(str, format);
	}
	else
		str = left_space(str, format);
	return (str);
}

char		*right_space(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		i;

	width = find_width(format);
	i = ft_strlen(str);
	width = width - i;
	tmp = (char *)malloc(sizeof(char) * (width + 1));
	tmp[width--] = '\0';
	while (width >= 0)
		tmp[width--] = ' ';
	tmp = ft_strjoin(str, tmp);
	return (tmp);
}

char		*left_space(char *str, char *format)
{
	int		width;
	char	*tmp;
	int		i;

	width = find_width(format);
	i = ft_strlen(str);
	width = width - i;
	tmp = (char *)malloc(sizeof(char) * (width + 1));
	tmp[width--] = '\0';
	while (width >= 0)
		tmp[width--] = ' ';
	tmp = ft_strjoin(tmp, str);
	return (tmp);
}
