#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define MAX 100
#define MAXB 8192


int main (){

	mqd_t cola_mensajes;
	char* c_buffer;
	struct mq_attr atributos;

	if((cola_mensajes = mq_open("/mq_so", O_RDWR)) == -1){
		perror("No se pudo leer cola de mensajes");
		return 1;
	}
	
	while(1){

		printf("HOLA");
		if(mq_receive(cola_mensajes, c_buffer, MAXB, NULL) == -1){
			perror("No se pudo recibir el mensaje");
			return -1;
		}

		printf("%s", c_buffer);
	}

	mq_close(cola_mensajes);
}