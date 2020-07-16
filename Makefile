NAME = ./fractol

FILES = main.c \
        julia.c \
        mandelbrot.c \
        exit.c \
        loop.c \
        random.c \
        calc.c \
        flow.c \

SRC = $(addprefix src/,$(FILES))

OBJ = $(addprefix obj/,$(FILES:.c=.o))

LIB = libft/libft.a


all : $(NAME)

$(NAME) : $(OBJ) inc
	@make -C libft/
	@gcc -g -o $(NAME) $(OBJ) $(LIB) -lmlx -lpthread -framework OpenGL -framework AppKit

obj/%.o: src/%.c
	@mkdir -p obj/
	@gcc $(FLAGS) -Iinc -o $@ -c $<

clean :
	@make clean -C libft/
	@rm -rf obj/

fclean : clean
	@make fclean -C libft
	@rm -f $(NAME)

re : fclean all
