NAME =	push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = parsing.c sorting.c stack_init.c stack_utils.c main.c \
		push.c reverse_rotate.c rotate.c sort.c swap.c

OBJS = $(SRCS:.c=.o)

all:			$(NAME)
				@clear
				@echo " __________             .__        _________              _________  ";
				@echo " \______   \__ __  _____|  |__    /   _____/  _  _______  \______  \ ";
				@echo "  |     ___/  |  \/  ___/  |  \   \_____  \\ \/ \/ /\__  \ |     ___/ ";
				@echo "  |    |   |  |  /\___ \|   Y  \  /        \\     /  / __ \|    |     ";
				@echo "  |____|   |____//____  >___|  / /_______  /\/\_/  (____  /____|     ";
				@echo "                      \/     \/          \/             \/           ";

$(NAME):		$(OBJS)
				make -C libft/ && mv libft/libft.a .
				$(CC) -o $(NAME) $(OBJS) libft.a

clean:			
				make clean -C libft/
				$(RM) $(OBJS)
				@clear
				@echo "        /\                __              __                         ";
				@echo "  ____  )/ ____   _______/  |_      ____ |  |   ____  _____    ____   ";
				@echo "/  ___\  /  __ \ /  ___/\   __\   /  ___\|  | /  __ \ \__  \  /    \  ";
				@echo "\  \___  \  ___/ \___ \  |  |     \  \___|  |_\  ___/ / __  \|   |  \ ";
				@echo " \____ >  \____ >_____ > |__|      \____ >____/\____> ____  / ___|  / ";
				@echo "                                                          \/      \/  ";


fclean: 		clean
				$(RM) $(NAME) libft.a
				@clear
				@echo "        /\                __        _____       __                         ";
				@echo "  ____  )/ ____   _______/  |_    _/ ____\____ |  |   ____  _____    ____   ";
				@echo "/  ___\  /  __ \ /  ___/\   __\   \  __\/  ___\|  | /  __ \ \__  \  /    \  ";
				@echo "\  \___  \  ___/ \___ \  |  |      |  | \  \___|  |_\  ___/  / __ \|   |  \ ";
				@echo " \____ >  \____> _____ > |__|      |__|  \____ >____/\____ > ____  /___|  / ";
				@echo "                                                                 \/     \/  ";

re: 			fclean all

.PHONY:			all clean fclean re