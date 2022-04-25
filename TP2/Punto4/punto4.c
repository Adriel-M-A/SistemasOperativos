#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#define TRUE 1

char*comando[3]={"/bin/ls","-ltr", NULL};

/*
	4a) Que Hace?
	Lo que hace el programa, es crear un nuevo proceso con el fork, si el valor que devuelve es 0 entonces
	es ejecutado por el hijo, que abre una nueva ventana de Firefox. De lo contrario si el valor es 1, quiere
	decir que es ejecutado por el padre; éste imprime que es el padre y espera a que el hijo termine de
	ejecutarse para terminar el proceso.
*/

int main() {
	int status;

	if (fork() != 0) /* Código del padre */
	{
		printf("\nPADRE\n");
		waitpid(-1, &status,0);
	}
	else
		/* Código del hijo */
		//execl("/usr/bin/firefox", "",NULL);
		execv(comando[0], comando);
	return 0;
}