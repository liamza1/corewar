# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hmthimun <hmthimun@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 13:46:58 by hmthimun          #+#    #+#              #
#    Updated: 2017/10/01 17:30:44 by hmthimun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= corewar

FILES		= corewar.c \
 			  check_errors.c \
 			  init_vm.c \
 			  get_vm.c \
			  load_champions.c \
			  vm.c \
			  vm_check_state.c \
			  vm_get_args.c \
			  hexdump.c \
			  utils.c \
			  get_from_memory.c \
			  op_code.c \
			  op_code2.c \
			  op_code3.c \
			  op_code4.c \
			  free.c \
			  check_header.c \
			  check_header2.c

SRC			= $(addprefix srcs/, $(FILES))
OBJ			= $(SRC:.c=.o)

LIBFT		= ../libft

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -g
INCLUDES	= -I$(LIBFT)/ -I.

CFLAGS		+= $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)/libft.a

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OBJ)
	@make -C $(LIBFT) clean

fclean: clean
	@rm -f $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re