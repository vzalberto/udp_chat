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
    int s;
    char msg[100];
    struct sockaddr sa;
    
    s = socket(AF_INET, SOCK_DGRAM, 0);
    
    if((s < 0))
        perror("Error al abrir socket para recibir");
        
    printf("\nSocket abierto: %d\n", s);
    
    do{
    //memset(&sa, 0x00, 15);
    memset(&msg, 0x00, 100);
    int n = sizeof(sa);
    
    if(recvfrom(s, msg, sizeof(msg), 0, (struct sockaddr *)&sa, &n) < 0)
    {
          perror("Error al recibir");
		exit(-1);
    }
    
    else
    	printf(":D\n");
    
    }while(1); 
}

int main(int argc, char ** argv){
    int s,t1;
    struct sockaddr sa;
    
    pthread_t recibe;
    
    t1 = pthread_create(&recibe, NULL, &recibir, NULL);
    if (t1 != 0)
			printf("\ncan't create thread :[%s]", strerror(t1));
			
			
			do
			{
				
			}while(1);
    
}


