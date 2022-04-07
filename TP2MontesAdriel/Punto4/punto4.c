#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
#define TRUE 1

char*comando[3]={"/bin/ls","-ltr", NULL};

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