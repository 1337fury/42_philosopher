NAME = philo_bonus

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC = -I ../INCLUDES

SRCS_PATH = ./

SRCS_NAME = \
	main.c \
	ft_atoi.c \
	utils.c \
	philo_routine.c \
	init.c \
	create_all.c \
	wait_kill.c \
	errors.c

B_OBJS_NAME = $(SRCS_NAME:.c=.o)

B_OBJS = $(addprefix $(SRCS_PATH),$(B_OBJS_NAME))

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $<

$(NAME) : $(B_OBJS)
	$(CC) $(CFLAGS) $(B_OBJS) -o $@

clean :
	@rm -f $(B_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re