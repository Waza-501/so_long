NAME :=			so_long
CC := 			gcc
CFLAGS :=		-Wall -Werror -Wextra -g
MLX_FLAGS :=	-framework Cocoa -framework OpenGL -framework IOKit

LIBRARIES :=	./libraries/libft/libft.a\
				./MLX42/build/libmlx42.a\

SOURCES	:=	so_long.c\
			map_check.c\
			utils.c\

INCLUDE_DIR :=	./includes
HEADERS :=		-I ./includes -I ./libraries/libft/header
LIBFT :=		./libraries/libft
MLX :=			./MLX42/build
SOURCE_DIR :=	./sources
OBJECT_DIR	:=	./objects
OBJECTS :=		$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))

all:	libraries $(NAME)

$(NAME):		$(OBJECTS) 
					$(CC) $(FLAGS) $(LIBRARIES) -o $@ $^ $(HEADERS)


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