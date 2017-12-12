# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaske <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 15:32:28 by tmaske            #+#    #+#              #
#    Updated: 2017/11/29 12:08:05 by hmthimun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	core

FLAGS	=	-Wall -Werror -Wextra -I$(HLOC) -c -g -g3

all:  $(NAME)

$(NAME): 
	@make -C vm/ re && make -C asm/ re
	@echo "VM and ASM compiled"

clean:
	@make -C asm/ clean && make -C vm/ clean

fclean: clean
	@make -C asm/ fclean && make -C vm/ fclean

re: fclean all

norm:
	@echo "\nNorme $(NAME)"
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADER)
