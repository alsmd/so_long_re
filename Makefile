SRCS =	./srcs/main.c ./srcs/message.c ./srcs/init.c \
		./srcs/map/check.c ./srcs/map/utils.c ./srcs/map/draw.c \
		./srcs/game/game_config.c ./srcs/game/resources.c ./srcs/game/game_init.c ./srcs/game/utils.c \
		./srcs/game/draw.c ./srcs/game/check.c \
		./srcs/player/resources.c ./srcs/player/draw.c ./srcs/player/action.c ./srcs/player/check.c \
		./srcs/pokemon/resources.c ./srcs/pokemon/draw.c ./srcs/pokemon/check.c ./srcs/pokemon/action.c \
		./srcs/enemy/resources.c ./srcs/enemy/draw.c ./srcs/enemy/check.c ./srcs/enemy/action.c \
		./srcs/enemy/utils.c \
		./srcs/vetor/create.c ./srcs/vetor/operation.c ./srcs/vetor/f_create.c ./srcs/vetor/f_operation.c ./srcs/vetor/f_operation_2.c

OBJS = $(SRCS:.c=.o)

UTILS = ./srcs/utils/create_img.c ./srcs/utils/ft_calloc.c ./srcs/utils/ft_itoa.c ./srcs/utils/ft_strcat.c \
		./srcs/utils/ft_strjoin.c ./srcs/utils/ft_strlen.c ./srcs/utils/get_next_line_utils.c ./srcs/utils/ft_strdup.c \
		./srcs/utils/get_next_line.c ./srcs/utils/is_in.c ./srcs/utils/only_has.c ./srcs/utils/pixel_manipulation.c \
		./srcs/utils/color.c ./srcs/utils/my_rand.c


OBJS_UTILS = $(UTILS:.c=.o)
NAME = so_long

CFLAGS		= -g
FLAGS		= -ldl -Imlx -Lmlx -lmlx -lm -lbsd -lXext -lX11

CC = gcc

RM = rm -f

all: $(NAME)

.c.o:
	${CC} ${CFLAGS} -Imlx -Ibass -c $< -o ${<:.c=.o}

$(NAME): $(UTILS) $(OBJS)
	${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(UTILS) $(FLAGS)

clean:
	$(RM) $(OBJS) $(OBJS_UTILS)

run: re
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) ./maps/simple.ber
fclean : clean
	$(RM) $(NAME)

re: fclean all