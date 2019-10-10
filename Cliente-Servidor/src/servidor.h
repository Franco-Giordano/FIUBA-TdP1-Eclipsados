#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
using namespace std;


class Servidor {
public:
	Servidor(char *puerto);
	~Servidor();

	int getSocketDesc(){return socket_desc;}

private:
	struct sockaddr_in server;
	int socket_desc;

};



#endif /* SERVIDOR_H_ */
