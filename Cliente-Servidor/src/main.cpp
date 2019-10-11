#include "servidor.h"
#include "cliente.h"

int main(int argc, char *argv[]) {

	int bytesRecibidos;
	char mensaje[1000], client_reply[1000];

	Servidor servidor(argv[1]);

	Cliente cliente(&servidor);

	while(1){

		cliente.recibirMensaje(client_reply);

		servidor.sendInfo(cliente.getSocket());

		if( strcmp(mensaje, "quit\n") == 0 || strcmp(client_reply, "quit\n") == 0){
			break;
		}

	}

	servidor.~Servidor();
	cliente.~Cliente();

	return 0;
}

