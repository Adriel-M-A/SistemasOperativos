#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

char*comando[10][100] = {""};

//* se obtiene un comando o combinacion de comandos apartir de una cadena 
void getCommand(char str[]) {
    
}

int main () {
    char str[30];
    int init_size = strlen(str);

    char path[200];
    getcwd(path, 200);
    printf("%s$ ", path);

    scanf("%s", str);
    getCommand(str);

    return 0;
}