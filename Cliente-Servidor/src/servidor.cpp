#include "servidor.h"


Servidor::Servidor(char *puerto){

	//Creando Socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc == -1){
		perror("Could not create socket. Error \n");
	}
	printf("Socket created \n");

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( atoi(puerto) );

	//Esto es para poder reusar el address sin esperar a que se resetee en caso de no cerrarlo bien
	int activado = 1;
	setsockopt(socket_desc,SOL_SOCKET, SO_REUSEADDR,&activado, sizeof(activado));

	//Bind
	if( bind(socket_desc, (struct sockaddr *)&server, sizeof(server) ) != 0){
		perror("Bind Failed. Error \n");
	}else{
		printf("Bind Done \n");
	}

	//Listen
	printf("Listening on port %s. Waiting for acceptance. \n", puerto);
	listen(socket_desc, 4);
	fflush(stdout);

}

Servidor::~Servidor(){

	close(socket_desc);

}
