NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror

INC = -I ../INCLUDES

LIB = -pthread

M_SRCS_PATH = ./

M_SRCS_NAME = \
	main.c \
	ft_atoi.c \
	philo_routine.c \
	launch.c \
	init.c \
	utils.c \
	lst_clear.c \
	destroy.c
	
M_OBJS_NAME = $(M_SRCS_NAME:.c=.o)

M_OBJS = $(addprefix $(M_SRCS_PATH),$(M_OBJS_NAME))

%.o : %.c
	$(CC) $(CFLAGS) $(INC) -c $<

all : $(NAME)

$(NAME) : $(M_OBJS)
	$(CC) $(CFLAGS)  $(LIB) $(M_OBJS) -o $@

clean :
	@rm -f $(M_OBJS)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re