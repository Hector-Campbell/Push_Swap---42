/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 22:12:37 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 19:38:27 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*hashsign_0x(char *str, char *format)
{
	char	c;
	int		i;
	char	*tmp;

	i = 0;
	c = arg_value(format);
	tmp = NULL;
	while (str[i] == '0' && str[i] != '\0')
		i++;
	if (str[i] == '\0' && c != 'o')
		return (str);
	if (str[0] == '0' && c == 'o')
		return (str);
	tmp = tmp_creation(str, format, c);
	if (tmp == NULL)
		return (str);
	tmp = ft_strjoin(tmp, str);
	if ((tmp[ft_strlen(tmp) - 1] == 'X' || tmp[ft_strlen(tmp) - 1] == 'x') &&
			tmp[ft_strlen(tmp) - 2] == '0')
		tmp[ft_strlen(tmp) - 2] = '\0';
	return (tmp);
}

char		*hashsign_hex(char *format)
{
	char	c;
	char	*newstr;

	c = arg_value(format);
	newstr = (char *)malloc(sizeof(char) * (3));
	newstr[0] = '0';
	if (c == 'x')
		newstr[1] = 'x';
	if (c == 'X')
		newstr[1] = 'X';
	newstr[2] = '\0';
	return (newstr);
}

char		*hashsign_float(char *str)
{
	char			*newstr;
	size_t			i;
	unsigned int	start;

	i = 0;
	start = 0;
	newstr = NULL;
	while (str[i++] != '.')
		i++;
	if (str[i] != '.')
	{
		i = 0;
		while (str[i] < '0' && str[i] > '9')
			i++;
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		newstr = ft_strjoin(ft_strsub(str, start, --i), ".");
		while (str[i + 1] != '\0')
			i++;
		newstr = ft_strjoin(newstr, ft_strsub(str, start, i));
	}
	return (newstr);
}

char		*sign(char *str, char *format)
{
	char	*tmp;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '+' && str[i] != '\0')
		i++;
	if (str[i] == '\0')
		return (str);
	if (str[i] == '+')
	{
		tmp = ft_strchr(str, '+');
		if (if_space(format) == 1)
		{
			*tmp = ' ';
			if (if_precision(format) == 1)
				tmp = sign_precision(str, format);
			return (tmp);
		}
		str = special_split(str, tmp);
	}
	return (str);
}

char		*sign_precision(char *str, char *format)
{
	char		*tmp;
	char		*first;
	char		*second;

	format = NULL;
	if ((tmp = ft_strchr(str, ' ')))
	{
		*tmp++ = '\0';
		first = ft_strdup(str);
		second = ft_strdup(tmp);
		free(str);
		str = ft_strjoin(first, second);
		str = ft_strjoin(" ", str);
		free(first);
		free(second);
	}
	return (str);
}
