#include "cliente.h"


Cliente::Cliente(Servidor* server){

	c = sizeof(struct sockaddr_in);

	//Accept
	ACCEPT: sock = accept( server->getSocketDesc(), (struct sockaddr *)&cliente, (unsigned int *)c);
	if (sock < 0){
		perror("Acceptance Failed. Error");
		close(sock);
		goto ACCEPT;
	}else{
		printf("Connection Accepted");
	}

}

Cliente::~Cliente(){

	close(sock);
	printf("Socket numero %d Closed\n", sock);

}


char Cliente::respuesta(){

	bzero(reply, 1000);
	read(sock, reply, 1000);
	return reply[1000];

}
