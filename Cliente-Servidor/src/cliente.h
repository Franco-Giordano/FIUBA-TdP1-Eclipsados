#ifndef CLIENTE_H_
#define CLIENTE_H_

#include "servidor.h"

class Cliente {
public:
	Cliente(Servidor* server);
	~Cliente();
	void recibirMensaje(char replay[1000]);
	int getSocket(){return socks;}

private:
	struct sockaddr_in cliente;
	int c;
	int socks;
	char reply[1000];

};



#endif /* CLIENTE_H_ */
