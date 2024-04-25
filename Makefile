NAME		=	push_swap

CC			=	cc

FLAG		=	-Wall -Wextra -Werror -g3

LIBFT_PATH	=	.libft

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(LIBFT_PATH)/$(LIBFT_FILE)

C_FILE		=	./instruction/do_push.c \
				./instruction/do_reverse_rotate.c \
				./instruction/do_rotate.c \
				./instruction/do_swap.c \
				\
				./srcs/prepa_a_to_b.c \
				./srcs/prepa_b_to_a.c \
				./srcs/check_error.c \
				./srcs/sort_arg_utils.c \
				./srcs/utils_algo.c \
				./srcs/init_stack.c \
				./srcs/utils_list.c \
				./srcs/push_swap.c

OBJS		=	$(C_FILE:.c=.o)

.c.o:
	@printf "\r\033[K[push_swap] \033[0;32mBuilding : $<\033[0m"
	@$(CC) $(FLAG) -c $< -o $@

all:	$(NAME)

lib:
	@make -C $(LIBFT_PATH)

$(NAME): lib $(OBJS)
	@printf "\r\033[K[push_swap] \033[0;32mLinking...\033[0m"
	@$(CC) $(OBJS) $(LIBFT_LIB) -o $(NAME) -lm 
	@printf "\r\033[K[push_swap] \033[0;32mDone!\033[0m\n"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJS)
	@printf "[push_swap] \033[1;31mCleaned .o!\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@printf "[push_swap] \033[1;31mCleaned all!\033[0m\n"

re: fclean all

.PHONY: all clean fclean re