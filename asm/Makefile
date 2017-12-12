# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaske <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/24 15:32:28 by tmaske            #+#    #+#              #
#    Updated: 2017/11/29 12:04:03 by hmthimun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

HLOC	=	includes
LIBFT	=	../libft/libft.a

NAME	=	asm
LOC		=	srcs/
HEADER	=	includes/asm.h\
			includes/op.h
FILES	=	asm.c\
			main.c\
			binaries.c\
			check.c\
			fill_file.c\
			op.c\
			fill_header.c\
			fill_label.c\
			free.c\
			handle.c\
			handle_cmds.c\
			handle_cmds_odds.c\
			init.c\
			parse.c\
			put_cmd_in_list.c\
			utils.c\
	
SRC		=	$(addprefix $(LOC), $(FILES))
OBJ		=	$(FILES:.c=.o)

FLAGS	=	-Wall -Werror -Wextra -I$(HLOC) -c -g -g3

all:  $(NAME)

$(NAME): 
	@gcc $(FLAGS) $(SRC)
	@gcc -o $(NAME) $(OBJ) $(LIBFT)
	@echo "$(NAME) Compiled"

clean:
	@rm -f $(OBJ)
	@echo "$(NAME) Cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) Executable Deleted"

re: fclean all

norm:
	@echo "\nNorme $(NAME)"
	@norminette -R CheckForbiddenSourceHeader $(SRC) $(HEADER)
