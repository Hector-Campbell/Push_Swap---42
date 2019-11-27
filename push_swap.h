/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 19:27:49 by hecampbe          #+#    #+#             */
/*   Updated: 2019/10/15 20:06:14 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdarg.h>
# include "printf/ft_printf.h"
# include "gnl/get_next_line.h"

typedef struct	s_str
{
	int		*str_b;
	int		*str_a;
	int		**str_both;
}				t_str;

typedef struct	s_len
{
	int		len_a;
	int		len_b;
}				t_len;

typedef struct	s_ft
{
	char	**list;
}				t_ft;

typedef struct	s_list2
{
	char	*stepz;
}				t_list2;

void        order_a_rotate(t_len *length, t_str *strings, t_list2 *steps);
void        order_a_reverse_rotate(t_len *length, t_str *strings, t_list2 *steps);
void        order_b_rotate(t_len *length, t_str *strings, t_list2 *steps);
void        order_b_reverse_rotate(t_len *length, t_str *strings, t_list2 *steps);
int	        cull_supreme(t_len *length, t_str *strings, t_list2 *steps);
void		cull_push(t_len *length, t_str *strings, t_list2 *steps);
int         cull_rotate(t_len *length, t_str *strings, t_list2 *steps, int hold);
void		order_a(t_len *length, t_str *strings, t_list2 *steps);
void		place_b(t_len *length, t_str *strings, t_list2 *steps);
int			solved_b(t_len *length, t_str *strings);
void		order_b(t_len *length, t_str *strings, t_list2 *steps);
int         rotate_value(int len, int *str);
int         r_rotate_value(int len, int *str);
int			algorithim(t_len *length, t_str *strings, t_list2 *steps);
int			middle_value(int *str, int len);
int			instruction_parser2(t_ft *steps);
int			compare(int value, int *str, int len);
int			max_compare(char *str);
void		prompt(int program);
//Parsing and others
int         *intdup_a(t_len *length, int *str);
int         *intdup_b(t_len *length, int *str);
int			*intnew(int len);
//Instrcuted Functions, and their helpers
int         **pa(t_len *length, t_str *strings);
int         **pb(t_len *length, t_str *strings);
int         *shift_down_a(t_len *length, t_str *strings);
int         *shift_up_a(t_len *length, t_str *strings);
int         *shift_down_b(t_len *length, t_str *strings);
int         *shift_up_b(t_len *length, t_str *strings);
int         *ra(t_len *length, t_str *strings);
int         *rb(t_len *length, t_str *strings);
int         **rr(t_len *length, t_str *strings);
int         *rra(t_len *length, t_str *strings);
int         *rrb(t_len *length, t_str *strings);
int         **rrr(t_len *length, t_str *strings);
int         *sa(t_len *length, t_str *strings);
int         *sb(t_len *length, t_str *strings);
int         **ss(t_len *length, t_str *strings);

//Parsing
int			int_parser(t_len *length, t_str *strings, int argc, char **argv);
int			instruction_parser(t_len *length, t_ft *steps, int argc, char **argv);
//Simple Algorithim
int			simple_algorithim(t_len *length, t_str *strings, t_ft *steps);
void		simple_algorithim2(t_len *length, t_str *strings, t_ft *steps, int i);
int			solved(t_len *length, t_str *strings);

//String Transfer
void		transfer_a(t_len *length, t_str *strings, int *str);
void		transfer_b(t_len *length, t_str *strings, int *str);
void		transfer_both(t_len *length, t_str *strings, int **str);
//All Algorithim stuff unorganized
//optimizatio.c
int			main(int argc, char **argv);
int			complex_algorithim(t_len *length, t_str *strings, t_list2 *steps);
int			put_instruction(char *new_step, t_list2 *steps);
void		print_solution2(t_len *length, t_str *strings, t_list2 *steps);
//Find_value.c
int			find_small(int len, int *str, int rank);
int			find_big(int len, int *str, int rank);
//push.c
int			push_smallest(t_len *length, t_str *strings, t_list2 *steps);
int			if_odd(int value);
void		transfer_ra(t_len *length, t_str *strings, t_list2 *steps, int i);
//split.c
void		if_a_two(t_len *length, t_str *strings, t_list2 *steps);
void		if_a_three(t_len *length, t_str *st, t_list2 *steps);
void		if_a_five_or_lower(t_len *length, t_str *strings, t_list2 *steps);

#endif
