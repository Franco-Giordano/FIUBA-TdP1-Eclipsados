#include "cliente.h"


Cliente::Cliente(Servidor* server){

	c = sizeof(struct sockaddr_in);

	//Accept
	sock = accept( server->getSocketDesc(), (struct sockaddr *)&cliente, (socklen_t *) &c);
	if (sock < 0){
		perror("Acceptance Failed. Error");
		close(sock);
		exit(-1);
	}else{
		puts("Connection Accepted");
		puts("Connection Successful");
	}

}

Cliente::~Cliente(){

	close(sock);
	printf("Socket numero: %d Closed\n", sock);

}


void Cliente::recibirMensaje(char reply[1000]){

	bzero(reply, 1000);
	recv(sock, reply, 1000, 0);
	printf("Cliente:\n");
	printf("%s\n", reply);

}
