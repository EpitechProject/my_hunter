##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

SRCLIB =	game/game_view.c \
			game/game_view2.c \
			game/game_view3.c \
			game/game_view4.c \
			my_hunter.c	\

OBJ = $(SRCLIB:.c=.o)

NAME = my_hunter

CFLAGS =	-W -Wall -Wextra

CSFML =	-lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window

all: $(OBJ)
	gcc $(OBJ) -o $(NAME) my_hunter2.c -I./include $(CFLAGS) $(CSFML)

$(NAMELIB): $(OBJ)
	gcc -c $(SRCLIB)
	ar rc $(NAMELIB) $(OBJ)
	make clean
	make cleanz

clean:
	rm -f $(OBJ)

cleanz : clean
	rm -f *.o

fclean: clean
	rm -f $(NAME) $(NAMELIB)
	rm -f *.o

re: fclean all
