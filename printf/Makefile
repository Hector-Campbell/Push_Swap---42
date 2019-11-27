# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/12 19:36:08 by hecampbe          #+#    #+#              #
#    Updated: 2019/09/18 15:01:08 by hecampbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = libft

C_FILES = ft_printf.c arg_op.c arg_op2.c arg_split.c d_va_arg.c double_conversion.c dtoa.c format.c hell.c hell_width.c hell_width2.c hell_width3.c helper.c helper2.c helper3.c hexadecimal_conversions.c int_str.c long_dtoa.c o_va_arg.c octal_conversion.c pointer.c precision.c precision2.c precision3.c string_completion.c string_completion2.c string_maker.c u_va_arg.c width.c width2.c width3.c x_va_arg.c

O_FILES = ft_printf.o arg_op.o arg_op2.o arg_split.o d_va_arg.o double_conversion.o dtoa.o format.o hell.o hell_width.o hell_width2.o hell_width3.o helper.o helper2.o helper3.o hexadecimal_conversions.o int_str.o long_dtoa.o o_va_arg.o octal_conversion.o pointer.o precision.o precision2.o precision3.o string_completion.o string_completion2.o string_maker.o u_va_arg.o width.o width2.o width3.o x_va_arg.o

FLAGS = -Wall -Wextra -Werror -c

$(NAME): $(O_FILES)
	ar rcs $(NAME) libft/*.o $(O_FILES)

$(O_FILES): $(C_FILES)
	make -C $(LIBFT)
	gcc $(FLAGS) $(C_FILES)

all: $(NAME)

clean:
	make clean -C $(LIBFT)
	rm -f $(O_FILES)

fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
