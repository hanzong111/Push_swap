# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojing-ha <ojing-ha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/14 20:26:19 by ojing-ha          #+#    #+#              #
#    Updated: 2022/11/04 18:40:37 by ojing-ha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR     = \033[0;39m
GRAY         = \033[0;90m
RED         = \033[0;91m
GREEN         = \033[0;92m
YELLOW         = \033[0;93m
BLUE         = \033[0;94m
MAGENTA     = \033[0;95m
CYAN         = \033[0;96m
WHITE         = \033[0;97m
NAME		= push_swap

CC			= gcc

LIBFT_DIR	= libft/
OBJS_DIR	= objs/

CFLAGS	= -Wall -Werror -Wextra -I . -fsanitize=address -g3
LIBFTFLAGS	= -L$(LIBFT_DIR) -lft

SRC_FILES	= push_swap\
				ps_error_checks\
				ps_error_checks_utils\
				ps_initialize\
				ps_make_int_list\
				ps_d_list\


SRCS	= $(addsuffix .c, $(SRC_FILES))
OBJS	= $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all		:
		@mkdir -p $(OBJS_DIR)
		@echo "$(MAGENTA) --------------------------INSIDE LIBFT-------------------------- $(CYAN)"
		@echo "\n"
		@make -C ${LIBFT_DIR}
		@echo "$(MAGENTA) --------------------------INSIDE PUSH_SWAP-------------------------- $(CYAN)"
		@echo "\n"
		@make $(NAME)
		@echo "$(YELLOW)Done Creating ./push_swap$(DEF_COLOR)"
		@echo "\n"
		@echo "$(GREEN) -------------$(RED)I $(CYAN)AM $(GREEN)DONE $(YELLOW)MADAFAKA$(GREEN)-------------------------- $(DEF_COLOR)"

${OBJS_DIR}%.o:	%.c
		@$(CC) $(CFLAGS) -c $^ -o $@
		@echo "$(GREEN)Compiling $<...$(DEF_COLOR)"


$(NAME)	: ${OBJS}
		@${CC} ${CFLAGS} ${OBJS} ${LIBFTFLAGS} -o ${NAME}
		@echo "$(GREEN)Creating ./push_swap ...$(DEF_COLOR)"


clean	:
		rm -rf $(OBJS_DIR)
		make clean -C ${LIBFT_DIR}

fclean	:	clean
		rm -f $(NAME)
		make fclean -C ${LIBFT_DIR}

re		:fclean all

.PHONY	:all clean fclean re
