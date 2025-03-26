NAME			:=	so_long
CC				:=	cc
CFLAGS			:=	-Wall -Werror -Wextra
MLX_FLAGS		:= -Iinclude -ldl -lglfw -pthread -lm

LIBRARIES		:=	./libraries/libft/libft.a\
					./MLX42/build/libmlx42.a\

LIBFT			:= ./libraries/libft
MLX42			:= ./MLX42/build

SOURCES_DIR		:=	sources/
SOURCES			:=	error_and_free.c\
					hooks.c\
					initialize_structs.c\
					prepare_map.c\
					so_long.c\
					solve_map.c\
					start_game.c\
					utils.c\
					validate_map.c\
					

OBJECTS_DIR		:=	objects/
OBJECTS			:= $(addprefix $(OBJECTS_DIR), $(SOURCES:.c=.o))
HEADERS			:=	-I ./includes -I ./libraries/libft

NO_COLOR = \033[0;39m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
CYAN = \033[0;96m

all:		libraries $(NAME)
			$(info Finished compiling so_long)

$(NAME):	$(OBJECTS)
				$(CC) $(CFLAGS) -o $@ $^ $(HEADERS) $(LIBRARIES) $(MLX_FLAGS)


$(OBJECTS_DIR)%.o:	$(SOURCES_DIR)%.c
					@mkdir -p $(dir $@)
					$(CC) $(CFLAGS) $(HEADERS) -c -o $@ $< -O3

libraries:	
			$(MAKE) -C $(LIBFT)
			$(MAKE) -C $(MLX42)

clean:
			@rm -rf $(OBJECTS)
			@$(MAKE) -C $(LIBFT) clean

fclean:		clean
			@rm -rf $(NAME)
			@$(MAKE) -C $(LIBFT) fclean
			@if [ -d "$(OBJECTS_DIR)" ]; then rm -drf $(OBJECTS_DIR); fi
			@echo Cleaned up all created files.

re:	fclean all

.PHONY:		all libraries clean fclean re
