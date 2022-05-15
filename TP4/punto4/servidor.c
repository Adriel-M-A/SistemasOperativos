/*
 * Sistemas Operativos - UNPSJB
*/
 
#include <stdio.h>
#include <string.h>   
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>     //close
#include <arpa/inet.h>  //close
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/time.h>   //FD_SET, FD_ISSET, FD_ZERO macros
 
#define TRUE   1
#define FALSE  0
#define PORT 8888    //puerto escucha del servidor

int main(int argc , char *argv[])
{
    int opt = TRUE;
    int socket_master, addrlen, nuevo_socket, socket_cliente[30], max_clientes=30, actividad, i, leido, sd;
	int max_sd;
    struct sockaddr_in direccion;
     
    char buffer[1025];  //data buffer of 1K
     
    //set de descriptores de sockets
    fd_set fds_lectura;
     
    //mensaje
    char *mensaje = "ECHO Daemon v1.0 \r\n";
 
    for (i = 0; i < max_clientes; i++) 
    {
        socket_cliente[i] = 0;
    }
     
    //Llama a un socket y devuelve el FD en socket_master. Si la operacion falla muestra el error
    if( (socket_master = socket(AF_INET , SOCK_STREAM , 0)) == 0) 
    {
        perror("Llamada socket falló");
        exit(EXIT_FAILURE);
    }
 
    /*La funcion controla el comportamiento del socket. Permite asignar espacio al bufer, controlar tiempos
    de espera o permitir transmision de datos. */
    if( setsockopt(socket_master, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
    {
        perror("Llamada setsockopt falló");
        exit(EXIT_FAILURE);
    }
 

    direccion.sin_family = AF_INET;
    direccion.sin_addr.s_addr = INADDR_ANY;
    direccion.sin_port = htons(PORT);
     
    //Una vez creado y configurado el socket se le asigna una direccion especificada.
    if (bind(socket_master, (struct sockaddr *)&direccion, sizeof(direccion))<0) 
    {
        perror("Llamada bind falló");
        exit(EXIT_FAILURE);
    }
	printf("Escuchando en puerto %d \n", PORT);
	
    //Le indica al socket que se usará para aceptar solicitudes de conexiones
	if (listen(socket_master, 3) < 0)
    {
        perror("Llamada listen falló");
        exit(EXIT_FAILURE);
    }
     
    //Se le "asigna un nombre" al socket. 
    addrlen = sizeof(direccion);
    puts("Esperando conexiones entrantes ...");
    
	while(TRUE) 
    {
        //Macro para borrar todos los FD (para evitar basura) 
        FD_ZERO(&fds_lectura);
 
	    //Macro para agregar un FD a la lista de lectura.
        FD_SET(socket_master, &fds_lectura);
        max_sd = socket_master;
		
		//Itera segun la cantidad maxima de clientes y realiza los siguientes pasos.
        for (i = 0 ; i < max_clientes ; i++) 
        {
        	//descriptor de socket
			sd = socket_cliente[i];
            
			//si hay descriptor de socket valido entonces se añade a la lista de lectura
			if (sd > 0)
				FD_SET(sd, &fds_lectura);
            
                //maximo numero de descriptores de socket
            if (sd > max_sd)
				max_sd = sd;
        }
 
        //Select selecciona el cliente y lo llama para ser atendido
        actividad = select( max_sd + 1 , &fds_lectura , NULL , NULL , NULL);
   
        if ((actividad < 0) && (errno!=EINTR)) 
        {
            printf("Llamada a select falló");
        }
         
        //Primero verifica si el FD sigue estando presente en la lista. Luego acepta la conexion con el cliente y si falla termina.
        if (FD_ISSET(socket_master, &fds_lectura)) 
        {
            if ((nuevo_socket = accept(socket_master, (struct sockaddr *)&direccion, (socklen_t*)&addrlen))<0)
            {
                perror("Llamada accept falló");
                exit(EXIT_FAILURE);
            }

            printf("Nueva conexion , file descriptor de socket es %d , ip es : %s , puerto : %d \n" , nuevo_socket , inet_ntoa(direccion.sin_addr) , ntohs(direccion.sin_port));
       
            //Envia un mensaje al cliente
            if( send(nuevo_socket, mensaje, strlen(mensaje), 0) != strlen(mensaje) ) 
                perror("Llamada send falló");
             
            puts("Mensaje enviado exitosamente");
             
            //Itera segun la cantidad maxima de clientes
            for (i = 0; i < max_clientes; i++) 
            {
                
				if( socket_cliente[i] == 0 ) //Si no esta el socket lo añade a la lista
                {
               	    socket_cliente[i] = nuevo_socket;
                    printf("Añadiendo a lista de sockets como %d\n" , i);
					
				    break;
                }
            }
        }
         
        //Si hay alguna otra operacion en algun otro socket
        for (i = 0; i < max_clientes; i++) 
        {
            sd = socket_cliente[i];
             
            if (FD_ISSET(sd , &fds_lectura)) 
            {
                
				if ((leido = read(sd ,buffer, 1024)) == 0)
                {
                    //Alguno se desconetó, obtengo detalles y muestro
                    getpeername(sd , (struct sockaddr*)&direccion , (socklen_t*)&addrlen);
                    printf("Host desconectado , ip %s , puerto %d \n" , inet_ntoa(direccion.sin_addr) , ntohs(direccion.sin_port));
                     
                    //Cierro socket y marco como disponible en lista
                    close( sd );
                    socket_cliente[i] = 0;
                }
                 
                else
                {
                    //set the string terminating NULL byte on the end of the data read
                    buffer[leido] = '\0';
                    send(sd , buffer , strlen(buffer) , 0 );
                }
            }
        }
    }
     
    return 0;
}