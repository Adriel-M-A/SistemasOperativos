
OBJ = servidor.o comunicaciones.o hardware.o

all: servidor cliente

cliente: cliente.o comunicaciones.o hardware.o
	gcc -o cliente $(OBJ)

servidor: $(OBJ)
	gcc -o servidor $(OBJ)

servidor.o: servidor.c servidor.h interfaz.h comunicaciones.h
	gcc -c servidor.c 

comunicaciones.o: comunicaciones.c comunicaciones.h hardware.h
	gcc -c comunicaciones.c 

hardware.o: hardware.c hardware.h
	gcc -c hardware.c

clean:
	rm $(OBJ)
