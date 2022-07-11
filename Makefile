##
## EPITECH PROJECT, 2022
## TEkPain
## File description:
## makefile
##

NAME	=	tekpaint

SRCS	=	src/main.c \
		src/window.c

OBJS	=	$(SRCS:.c=.o)

FFLAGS =	-l csfml-graphics -l csfml-system -l csfml-audio -l csfml-window -lm

CFLAGS =	-Wall  -Wextra -g3 -Iinc

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		gcc -o $(NAME) $(OBJS) $(FFLAGS)

clean:
		rm -rf $(OBJS)

fclean:		clean
		rm -rf $(NAME)

re: fclean all
