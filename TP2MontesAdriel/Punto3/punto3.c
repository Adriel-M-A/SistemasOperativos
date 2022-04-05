#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int SEG=30;
 
void manejadorInt () {
    alarm(0);
	printf("\n Alarma cancelada \n");
}

void manejadorAlr () {
	printf("\n Alarma terminada \n");
    exit(1);
}

void manejadorQuit () {
	signal (SIGALRM, SIG_IGN);
    printf("\n Fin alarma \n");
}

int main(void) {
   alarm(SEG);
   signal(SIGINT, manejadorInt);
   signal(SIGALRM, manejadorAlr);
   signal(SIGQUIT, manejadorQuit); 
   while (1);
}