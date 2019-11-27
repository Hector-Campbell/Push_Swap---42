/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 22:22:38 by hecampbe          #+#    #+#             */
/*   Updated: 2019/09/23 19:38:30 by hecampbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include "libft/libft.h"
# include <limits.h>
# define UNIT_MAX 4294967295

int					ft_printf(char *format, ...);
char				**format_splitter(char *format);
int					check_percent(char *format, int end);
char				**format_return(char *format, size_t i, int len);
char				*make_capital(char *str);
char				*str_rev(char *str);
char				*ft_strdup2(char *src);
int					ft_strlen2(char *str);
char				**arg_split(va_list lst_arg, char *format);
int					num_strlen(unsigned int n);
char				*d_split(va_list lst_arg, char *format);
char				*d_none(va_list lst_arg, char *format);
char				*d_hh(va_list lst_arg, char *format);
char				*d_h(va_list lst_arg, char *format);
char				*d_l(va_list lst_arg, char *format);
char				*d_ll(va_list st_arg, char *format);
int					snum_strlen(int num);
char				*o_split(va_list lst_arg, char *format);
char				*o_none(va_list lst_arg, char *format);
char				*o_hh(va_list lst_arg, char *format);
char				*o_h(va_list lst_arg, char *format);
char				*o_l(va_list lst_arg, char *format);
char				*o_ll(va_list lst_arg, char *format);
char				*u_split(va_list lst_arg, char *format);
char				*u_none(va_list va_arg, char *format);
char				*u_hh(va_list lst_arg, char *format);
char				*u_h(va_list lst_arg, char *format);
char				*u_l(va_list lst_arg, char *format);
char				*u_ll(va_list lst_arg, char *format);
char				*octal_conversion(unsigned int num, char *format);
char				*octal_conversion_long(unsigned long int num, char *format);
char				*octal_conversion_longx2(unsigned long long int num,
		char *format);
char				*x_split(va_list last_arg, char *format);
char				*x_none(va_list lst_arg, char *format);
char				*x_hh(va_list lst_arg, char *format);
char				*x_h(va_list lst_arg, char *format);
char				*x_l(va_list lst_arg, char *format);
char				*x_ll(va_list lst_arg, char *format);
char				*hexadecimal_conversion(unsigned int num, char *format);
char				*hexadecimal_conversion_long(unsigned long int num,
		char *format);
char				*hexadecimal_conversion_longx2(unsigned long long int num,
		char *format);
int					int_strlen(unsigned int *str);
unsigned int		*int_strdup(unsigned int *src);
int					specifier_finder(char *format);
char				*f_split(va_list lst_arg, char *format);
char				*l_double_to_str(long double num, char *format);
char				*double_to_str(double num, char *format);
char				*ldtoa(long double num, char *format);
int					find_decpart_l(long double num, char *format);
char				*dtoa(double num, char *format);
char				*rounding(char *str, char *format);
char				*rounding_help(char *str, int i);
char				*the_dot(char *str, int i);
long int			power(int x, int n);
int					find_precision(char *format);
int					find_decpart(double num, char *format);
char				*c_split(va_list lst_arg, char *format);
char				*s_split(va_list lst_arg, char *format);
char				*p_split(va_list lst_arg, char *format);
char				*percent_split(char c, char *format);
void				*pointer_to_str(void *arg, char *format);
int					sint_strlen(int *str);
int					*sint_strdup(int *src);
int					ft_putstr2(char *str);
char				*str_completion(char *str, char *format);
int					if_precision(char *format);
char				*precision_split(char *str, char *format);
int					find_precision(char *format);
char				*precision_float(char *str, char *format, int pv);
char				*decimal_and_pv(char *str, int pv);
char				*too_short_float(char *format, int pv);
char				*too_long_float(char *str, char *format);
char				*precision_digit(char *str, int pv);
char				*too_short_integer(char *str, int pv);
int					if_sign(char *format);
char				*sign(char *str, char *format);
int					if_hashsign(char *format);
char				*hashsign_0x(char *str, char *format);
char				*hashsign_float(char *str);
char				arg_value(char *format);
int					if_right(char *format);
char				*right_width(char *str, char *format);
char				*left_width(char *str, char *format);
int					find_width(char *format);
int					if_width(char *format);
int					octal_num(unsigned int num);
int					hexadecimal_num(unsigned int num);
char				*str_left_width(char *str, char *format);
int					num_check(int c);
int					sign_finder(int n, int sign);
char				*ft_itoa2(int n);
char				*add_decimal(char *str, char *format);
char				*ft_itoa_long(long long int num);
int					long_strlen(long int long num);
char				*newline(char *str, char *format);
int					if_str(char *format);
char				**pure_str(char *format);
char				*right_zero(char *str, char *format, int num);
char				*left_zero(char *str, char *format, int num);
int					if_space(char *format);
int					hex_len(uint64_t num);
int					oct_len(unsigned int num);
char				*precision_string(char *str, int pv);
int					width_precision_confusion(char *format);
char				arg_value2(char *format);
char				*right_zero_with_sign(char *str, char *format);
char				*left_zero_with_sign(char *str, char *format);
char				*right_space(char *str, char *format);
char				*left_space(char *str, char *format);
char				*right_space_with_sign(char *str, char *format);
char				*left_space_with_sign(char *str, char *format);
char				*sign_precision(char *str, char *format);
char				*rearrange(char *str);
char				*the_string_ender(char satan, char *format);
char				*number_merge(char *str, char *big_str);
char				*hell_right_zero_with_sign(char *str, char *format);
char				*hell_left_zero_with_sign(char *str, char *format);
char				*hell_right_space(char *str, char *format);
char				*hell_left_space(char *str, char *format);
char				*hell_right_space_with_sign(char *str, char *format);
char				*hell_left_space_with_sign(char *str, char *format);
char				*hell_right_zero(char *str, char *format, int num);
char				*hell_left_zero(char *str, char *format, int num);
char				*hell_right_width(char *str, char *format);
char				*hell_left_width(char *str, char *format);
int					hell_find_width(char *format);
char				*hashsign_hex(char *format);
char				*remove_sign(char *format);
char				*precision_pointer(char *str, int pv);
char				*ft_itoa3(long long int n);
char				*special_split(char *str, char *tmp);
char				*ft_itoa_ulong(unsigned long long int n);
int					ulong_strlen(unsigned long long num);
int					ull_oct_len(unsigned long long int num);
char				*special_case(char *format);
char				*arg_split_cont(va_list lst_arg, char *format, char c,
		char *str);
int					ft_printf_loop(char *format, char **big_str, char **str,
		va_list lst_arg);
int					after_dot(char *str);
char				*tmp_creation(char *str, char *format, char c);

#endif
