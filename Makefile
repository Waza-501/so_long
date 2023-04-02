NAME :=					so_long
CC := 					gcc
CFLAGS :=				-Wall -Werror -Wextra -g -fsanitize=address
MLX_FLAGS :=			-I include -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit
MLX_FLAGS_MACBOOK :=	-Iinclude -lglfw -L"/opt/homebrew/Cellar/glfw/3.3.8/lib/" -framework Cocoa -framework OpenGL -framework IOKit

LIBRARIES :=	./libraries/libft/libft.a\
				./MLX42/build/libmlx42.a\

SOURCES	:=	hooks.c\
			map_converter.c\
			map_solver.c\
			map_validator.c\
			mapgen.c\
			utils.c\
			test_mlx.c\
			so_long.c\

INCLUDE_DIR :=	./includes
HEADERS :=		-I ./includes -I ./libraries/libft/header
LIBFT :=		./libraries/libft
MLX :=			./MLX42/build
SOURCE_DIR :=	./sources
OBJECT_DIR	:=	./objects
OBJECTS :=		$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

all:	libraries $(NAME)

$(NAME):		$(OBJECTS) 
					$(CC) $(FLAGS) $(MLX_FLAGS) $(LIBRARIES) -o $@ $^ $(HEADERS)


$(OBJECT_DIR)/%.o:	$(SOURCE_DIR)/%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS) $(HEADERS) -c -o $@ $< -O3

clean:
		rm -f $(OBJECTS)
		$(MAKE) fclean -C $(LIBFT)

fclean:	clean
		rm -f $(NAME)
		if [ -d "$(OBJECT_DIR)" ]; then rm -drf $(OBJECT_DIR); fi

libraries:
		@$(MAKE) -s -C $(LIBFT)
		@$(MAKE) -s -C $(MLX)

re: fclean all

.PHONY: all clean fclean re libraries