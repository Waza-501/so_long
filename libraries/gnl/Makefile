NAME :=		gnl.a
CC :=			gcc
AR :=			ar rcs
FLAGS :=		-Wall -Werror -Wextra -c -g

SOURCES	:=	get_next_line.c\
			get_next_line_utils.c\

HEADERS :=		./includes
SOURCE_DIR :=	./sources
OBJECT_DIR :=	./objects
OBJECTS :=		$(addprefix $(OBJECT_DIR)/, $(SOURCES:.c=.o))


all:	$(NAME)

$(NAME):		$(OBJECTS)
					$(AR) $(NAME) $(FLAGS) -o $@ $^ $(HEADERS)

$(OBJECT_DIR)/%.o:	$(SOURCE_DIR)/%.c
						mkdir -p $(dir $@)
						$(CC) $(FLAGS) $(HEADERS) -c -o $@

clean:
		rm -f $(OBJECTS)

fclean:	clean
		rm -f $(NAME)
		if [ -d "$(OBJECT_DIR)" ]; then rm -drf $(OBJECT_DIR); fi

re: fclean all

.PHONY: all clean fclean re