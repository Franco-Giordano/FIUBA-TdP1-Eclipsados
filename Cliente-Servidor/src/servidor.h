#ifndef SERVIDOR_H_
#define SERVIDOR_H_

#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
using namespace std;


class Servidor {
public:
	Servidor(char *puerto);
	~Servidor();

	int getSocketDesc(){return socket_desc;}
	void sendInfo(int clientSocket);
	void reciveInfo();

private:
	struct sockaddr_in server;
	int socket_desc;
	char info[1000];

};



#endif /* SERVIDOR_H_ */
