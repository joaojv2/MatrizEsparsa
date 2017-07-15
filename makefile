#Para escrever comentários ##
############################# Makefile ##########################
all: sparseArray matrix 
sparseArray: sparseArray.o main.o 
        # O compilador faz a ligação entre os dois objetos
        gcc -o sparseArray sparseArray.o main.o
#-----> Distancia com o botão TAB ### e não com espaços
sparseArray.o: sparseArray.c
        gcc -o sparseArray.o -c sparseArray.c -W -Wall -ansi -pedantic
matrix: matrix.o main.o 
        # O compilador faz a ligação entre os dois objetos
        gcc -o matrix matrix.o main.o
#-----> Distancia com o botão TAB ### e não com espaços
matrix.o: matrix.c
        gcc -o matrix.o -c matrix.c -W -Wall -ansi -pedantic

main.o: main.c sparseArray.h matrix.h
        gcc -o main.o -c main.c -W -Wall -ansi -pedantic
clean:
        rm -rf *.o
mrproper: clean
        rm -rf sparseArray
        rm -rf matrix