#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void manejadorInt(int num) {
	printf("\n Señal recibida \n");
	alarm(5);
} 

void manejadorAlr(int num) {
	printf("\n Fin alarma \n");
	exit(1);
}
int main(void) {
   signal(SIGINT, manejadorInt);
   signal(SIGALRM, manejadorAlr);
   alarm(5);
   while (1);
}