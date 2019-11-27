/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:38:09 by hecampbe          #+#    #+#             */
/*   Updated: 2019/10/31 19:38:14 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int         rotate_value(int len, int *str)
{
    int     i;
    int     j;

    i = len;
    j = 0;
    while (i != 0 && str[0] < str[i])
    {
        i--;
        j++;
    }
    return (j);
}

int         r_rotate_value(int len, int *str)
{
    int     i;

    i = 1;
    while (i != len && str[0] < str[i])
        i++;
    return (i);
}
