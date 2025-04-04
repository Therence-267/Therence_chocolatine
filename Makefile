##
## EPITECH PROJECT, 2025
## cuddle
## File description:
## function
##

libmy.a:
	gcc *.c -o 108trigo -lm

all: libmy.a

clean:
	rm -rf *.o
	rm -rf *.c~
	rm -rf *108trigo
	rm -rf *.csv
	rm -rf *.log
	rm -rf *~

fclean: clean
	rm -rf *.a

re: all
