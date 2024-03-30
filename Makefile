NAME	=	libftprintf.a

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

AR		=	ar rcs

SRCS	=	ft_printf.c ft_implement.c

OBJS	=	$(SRCS:.c=.o)


all:	$(NAME)

$(NAME):	$(OBJS)
	@	$(AR) $(NAME) $(OBJS)

%.o: %.c Makefile
	@	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@	$(RM) $(OBJS)

fclean:	clean
	@	$(RM) $(OBJS) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re