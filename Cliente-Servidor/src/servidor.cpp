#include "servidor.h"


Servidor::Servidor(char *puerto){

	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons( atoi(puerto) );

	//Creando Socket
	socket_desc = socket(AF_INET, SOCK_STREAM, 0);

	if(socket_desc == -1){
		perror("Could not create socket. Error \n");
		exit(-1);
	}
	printf("Socket created: %d\n", socket_desc);

	//Esto es para poder reusar el address sin esperar a que se resetee en caso de no cerrarlo bien
	int activado = 1;
	setsockopt(socket_desc,SOL_SOCKET, SO_REUSEADDR,&activado, sizeof(activado));

	//Bind
	if( bind(socket_desc, (struct sockaddr *)&server, sizeof(server) ) != 0){
		printf("Server Bind Failed. Errno %i: %s\n",errno,strerror(errno));
		exit(-1);
	}else{
		printf("Bind Done \n");
	}

	//Listen
	printf("Listening on port %s. Waiting for acceptance... \n", puerto);
	listen(socket_desc, 4);
	fflush(stdout);

}

Servidor::~Servidor(){

	close(socket_desc);

}

void Servidor::sendInfo(int clientSocket){

	printf("Mensaje Server:\n");
	bzero(info, 1000);
	fgets(info, 1000, stdin);
	send(clientSocket, info, strlen(info), 0);

}

void Servidor::reciveInfo(){

}