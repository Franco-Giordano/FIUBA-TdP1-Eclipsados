#include "servidor.h"
#include "cliente.h"


int main(int argc, char *argv[]) {


	vector<Cliente*> clientes;
	char mensaje[1000], client_reply[1000];


	Servidor servidor(argv[1]);

	for(int i = 0; i < 2; i++){

		Cliente* cliente = new Cliente(&servidor);
		clientes.push_back(cliente);

	}

	while(1){

		for(int i = 0; i < 2; i++){
			servidor.sendInfo(clientes[i]->getSocket());

			clientes[i]->recibirMensaje(client_reply);
		}

		if( strcmp(mensaje, "quit\n") == 0 || strcmp(client_reply, "quit\n") == 0){
			break;
		}

	}

	servidor.~Servidor();
	for(int i =0; i < 2; i++){
		clientes[i]->~Cliente();
	}


	return 0;
}

