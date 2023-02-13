# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: ohearn <ohearn@student.42.fr>                +#+                      #
#                                                    +#+                       #
#    Created: 2022/02/11 20:08:26 by ohearn        #+#    #+#                  #
#    Updated: 2023/02/01 16:31:43 by ohearn        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SRCS	=		ft_printf.c\
				fc_print_cha.c\
				fc_print_dec.c\
				fc_print_hex.c\
				fc_print_str.c\
				fc_putchar.c\
				fc_putnbr.c\
				fc_putstr.c\
				ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_itoa.c\
				ft_memchr.c\
				ft_memcmp.c\
				ft_memcpy.c\
				ft_memmove.c\
				ft_memset.c\
				ft_putchar_fd.c\
				ft_putendl_fd.c\
				ft_putnbr_fd.c\
				ft_putstr_fd.c\
				ft_split.c\
				ft_strchr.c\
				ft_strdup.c\
				ft_striteri.c\
				ft_strjoin.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\
				error_message.c\
				

NAME	=	libft.a
CC		=	@gcc
CFLAGS	=	-Wall -Werror -Wextra -c
AR		=	@ar rcs
OBJS	=	$(SRCS:%.c=%.o)

all:		$(NAME)
			$(info Finished compiling libft functions!)

$(NAME):	$(OBJS)
				$(AR) $(NAME) $(OBJS)
$(OBJS):	$(SRCS)
				$(CC) $(CFLAGS) $(SRCS)

clean:
			@rm -rf $(OBJS)
			@rm -rf $(BONUS)
			@echo ""
			@echo Removed object files libft functions.

fclean:		clean
			@rm -rf $(NAME)
			@echo ""
			@echo Removed all made libft functions.

re:	fclean all

.PHONY:		all, clean, fclean, re,