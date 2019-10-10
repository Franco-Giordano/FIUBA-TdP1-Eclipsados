#include "servidor.h"
#include "cliente.h"

int main(int argc, char *argv[]) {

	char mensaje[1000], client_reply[1000];

	Servidor servidor(argv[1]);

	Cliente cliente(&servidor);

	while(1){

		cliente.respuesta(&client_reply[1000]);
		puts("Mensaje Cliente: ");
		printf("%s\n",client_reply);

		if( strcmp(client_reply, "quit\n") == 0){
			break;
		}





	}

	servidor.~Servidor();
	cliente.~Cliente();

	return 0;
}

