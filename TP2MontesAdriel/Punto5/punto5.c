#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#define MAX 30

void manejadorAlr (){
	printf("Timeout \n");
	exit(1);
}


int main (){
	char log[MAX];
	char pas[MAX];
	int status;
    signal (SIGALRM, manejadorAlr);

	printf("ingrese nombre de usuario \n");
	scanf("%s", log);

	printf("ingrese contraseña \n");
	alarm(15);

    while(1){
        if (scanf("%s", pas) != 0) {
            alarm(0);
            if (fork() != 0) {
                waitpid(-1, &status,0);
            }
            else
            {
                execv("/bin/bash", NULL);
            }
        }
    }
}