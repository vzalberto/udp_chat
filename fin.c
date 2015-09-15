#include <stdio.h>
#include <string.h>
#include	<stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

void* recibir()
{
    int sock_udp, tam;
	char buffer[512];
	
	struct sockaddr_in servidor, cliente;
	sock_udp = socket(AF_INET, SOCK_DGRAM, 0);
	if(sock_udp == -1){
		perror("Error al abrir");
		exit(0);
	}

	else{
		printf("\nSocket abierto\n");
		memset(&servidor, 0x00, sizeof(servidor));
		servidor.sin_family = AF_INET;
		servidor.sin_port = htons(8080);
		servidor.sin_addr.s_addr = INADDR_ANY;

		if( bind(sock_udp, (struct sockaddr *)&servidor, sizeof(servidor)) == -1)
		{
			perror("Error en bind");
			exit('0');
		}
		else
		{
		while(1){
		int n = sizeof(cliente);
			tam = recvfrom(sock_udp, buffer, 512,0,(struct sockaddr*)&cliente,&n);
			if(tam == -1)
				printf("Error al recibir");
	
			else

				printf("\n%s\n",buffer);

	}	
}

}
}

void * enviar(void *argv)
{
int ss;
	struct sockaddr sa;
	struct in_addr addr;
	struct sockaddr_in soo;
	char msg[100];

	unsigned char ip[3];	
	
	ss = socket(AF_INET, SOCK_DGRAM, 0);
printf("\nEnvio listo: %d\n", ss);
	printf("socket: %d\n", ss);
	
	inet_aton("8.9.0.120", &addr);
	
//printf("Chat con %s\n", addr);
	sa.sa_family = AF_INET;
	memcpy(&sa.sa_data, &addr, 4);
soo.sin_family = AF_INET;
	soo.sin_port = htons(8080);
	soo.sin_addr = addr;

while(1){
	printf(">>> ");
scanf("%s",msg);
int nu = sendto(ss, msg, sizeof(msg), 0, (struct sockaddr *)&soo, sizeof(soo));
	strerror(nu);
	
}


}

int main(int argc, char ** argv){
    int s,t1,t2;
    struct sockaddr sa;
    
    pthread_t recibe, envia;
    
    t1 = pthread_create(&recibe, NULL, &recibir, NULL);
    if (t1 != 0)
	printf("\ncan't create thread :[%s]", strerror(t1));

  t2 = pthread_create(&envia, NULL, &enviar, &argv[1]);
 if (t2 != 0)
	printf("\ncan't create thread :[%s]", strerror(t1));
			
			
			do
			{
				
			}while(1);
    
}


