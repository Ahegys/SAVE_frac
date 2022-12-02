NAME = fractol

SRC_PATH = ./src/
OBJS_PATH = ./

SRC = $(addprefix $(SRC_PATH), main.c \
      window.c \
      print_pixel.c \
	  render.c \
	  set_mald.c )

PRINTF_LIB = ./includes/libftprintf.a

OBJS = $(SRC:$(SRC_PATH)%.c=$(OBJS_PATH)%.o)

INC = ./includes/fractal.h

FLAGS = -Wall -Werror -Wextra #-lm

MLX = -lmlx -Lminilibx -lXext -lX11 -g3

all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) $(PRINTF_LIB) $(MLX) -o $(NAME)

$(OBJS): $(SRC)
	cc $(FLAGS) -c $(SRC)

clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf *.o
	rm -rf fractal

re: fclean all

git:
	git status
	git add .
	git commit -m "$(m)"
	git push

#.PHONY: all clean fclean re
