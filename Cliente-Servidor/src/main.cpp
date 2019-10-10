#include "servidor.h"
#include "cliente.h"

int main(int argc, char *argv[]) {

	char mensaje[1000], client_reply[1000];

	Servidor servidor(argv[1]);

	Cliente cliente(&servidor);

	/*while(1){

		client_reply[1000] = cliente.respuesta();
		printf("Mensaje Cliente: ");
		printf("%s\n",client_reply);

		if( strcmp(client_reply, "quit\n") == 0){
			break;
		}





	}*/

	for(;;);

	servidor.~Servidor();
	cliente.~Cliente();

	return 0;
}

