# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hecampbe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/07 01:10:49 by hecampbe          #+#    #+#              #
#    Updated: 2019/10/18 00:19:18 by hecampbe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME_PS = push_swap

PRINTF = printf

GENERAL_C = int_help.c p_operation.c r_operation.c rr_operation.c s_operation.c string_shift.c string_transfer.c

GENERAL_O = int_help.o p_operation.o r_operation.o rr_operation.o s_operation.o string_shift.o string_transfer.o

CHECKER_C = parser.c checker_algorithim.c

CHECKER_O = parser.o checker_algorithim.o

PS_C = find_value.c optimization.c push.c split.c algorithim.c rotate.c culling.c order_b.c order_a.c

PS_O = find_value.o optimization.o push.o split.o algorithim.o rotate.o culling.o order_b.o order_a.o

FLAGS = -Wall -Wextra -Werror

all: $(GENERAL_O) $(NAME) $(NAME_PS)

$(GERNERAL_O): $(GENERAL_C)
	GCC $(FLAGS) -c $(GENERAL_C)

$(NAME): $(CHECKER_O)
	make -C $(PRINTF)
	gcc $(FLAGS) $(GENERAL_O) $(CHECKER_O) -g gnl/get_next_line.c printf/libftprintf.a -o $(NAME)

$(CHECKER_O): $(CHECKER_C)
	gcc $(FLAGS) -c $(CHECKER_C)

$(NAME_PS): $(PS_O)
	gcc $(GENERAL_O) $(PS_O) -g gnl/get_next_line.c printf/libftprintf.a -o $(NAME_PS)

$(PS_O): $(PS_C)
	gcc $(FLAGS) -c $(PS_C)

clean:
	rm -f $(CHECKER_O)
	rm -f $(PS_O)
	rm -f $(GENERAL_O)
	make clean -C $(PRINTF)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_PS)
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
