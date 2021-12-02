SRCS =	./srcs/main.c ./srcs/message.c \
		./srcs/map/check.c ./srcs/map/manipulation.c ./srcs/map/draw.c \
		./srcs/game/game_config.c ./srcs/game/resources.c ./srcs/game/game_init.c\
		./srcs/player/resources.c ./srcs/player/draw.c ./srcs/player/action.c ./srcs/player/check.c

OBJS = $(SRCS:.c=.o)

UTILS = ./srcs/utils/create_img.c ./srcs/utils/ft_calloc.c ./srcs/utils/ft_itoa.c ./srcs/utils/ft_strcat.c \
		./srcs/utils/ft_strjoin.c ./srcs/utils/ft_strlen.c ./srcs/utils/get_next_line_utils.c \
		./srcs/utils/get_next_line.c ./srcs/utils/is_in.c ./srcs/utils/only_has.c ./srcs/utils/pixel_manipulation.c


OBJS_UTILS = $(UTILS:.c=.o)
NAME = so_long

CFLAGS		= -g
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

CC = clang

RM = rm -f

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): $(UTILS) $(OBJS)
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(UTILS) $(FLAGS)

clean:
	$(RM) $(OBJS) $(OBJS_UTILS)

run: re
	valgrind --leak-check=full  ./$(NAME)
fclean : clean
	$(RM) $(NAME)

re: fclean all