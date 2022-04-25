#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int SEG=30;
 
void manejadorInt () {
    alarm(0);
	printf("Alarma cancelada \n");
}

void manejadorAlr () {
	printf("Alarma terminada \n");
    exit(1);
}

void manejadorQuit () {
	signal (SIGALRM, SIG_IGN);
    printf("Fin alarma \n");
}

int main(void) {
   alarm(SEG);
   signal(SIGINT, manejadorInt);
   signal(SIGALRM, manejadorAlr);
   signal(SIGQUIT, manejadorQuit); 
   while (1);
}