#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MAX 30

char*comando[MAX]={}

//* se obitiene un comando o combinacion de comandos apartir de una cadena 
void getCommand(char str[]) {
    char comando_aux[10];
    int pos = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] != ' ') {
            strcat(comando_aux, str[i]);
        }
        else {
            comando[pos] = comando_aux;
            pos++;
        }
    }
}

int main () {
    char str[MAX];

    scanf("%s", str);
    getComando(str);
    return 0;
}