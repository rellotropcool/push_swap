NAME		=	push_swap

CC		=	cc

FLAGS		=	-Wall -Wextra -Werror -g3

SRC		=	src/main.c \
			src/ft_split.c \
			src/parsing_utils.c \
			src/parsing_utils2.c \
			src/push_swap_utils.c \
			src/push_swap_utils2.c \
			src/push_swap_utils3.c \
			src/push_swap.c \
			src/push_swap2.c \
			src/reset.c

all:		$(NAME)

$(NAME):	$(SRC)
		
		@$(CC) $(FLAGS) $(SRC) -o $(NAME)
		@echo Compiled

clean: 

		@echo Cleaned
			
fclean:		clean
		@rm push_swap

			
re:		fclean all


.PHONY:		all clean fclean re
