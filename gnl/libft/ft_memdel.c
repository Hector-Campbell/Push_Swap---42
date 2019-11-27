/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 18:49:55 by hecampbe          #+#    #+#             */
/*   Updated: 2019/03/08 16:03:06 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_memdel(void **ap)
{
	if (ap != NULL && *ap != NULL)
	{
		free(*ap);
		*ap = NULL;
	}
}
