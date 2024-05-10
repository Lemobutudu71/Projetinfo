all : exec 

interface.o : interface.c interface.h 
	gcc -c interface.c -o interface.o
	
creerGrille.o : creerGrille.c creerGrille.h 
	gcc -c creerGrille.c -o creerGrille.o

main.o : main.c interface.h creerGrille.h 
	gcc -c main.c -o main.o

exec : main.o interface.o creerGrille.o
	gcc main.o interface.o creerGrille.o -o exec