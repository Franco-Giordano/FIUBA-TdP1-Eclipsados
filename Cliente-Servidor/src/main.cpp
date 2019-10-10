#include "servidor.h"
#include "cliente.h"

int main(int argc, char *argv[]) {

	char mensaje[1000], client_reply[1000];

	Servidor servidor(argv[1]);

	Cliente cliente(&servidor);

	while(1){

		printf("Enter message:\n");
		servidor.sendInfo(mensaje, cliente.getSocket());

		if( strcmp(mensaje, "quit\n") == 0){
			break;
		}

		cliente.respuesta(client_reply);
		puts("Mensaje Cliente: ");
		printf("%s\n",client_reply);



	}

	servidor.~Servidor();
	cliente.~Cliente();

	return 0;
}

