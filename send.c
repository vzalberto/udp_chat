
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	int ss;
	struct sockaddr sa;
	struct in_addr addr;
	struct sockaddr_in soo;
	
	unsigned char ip[3];	
	
	ss = socket(AF_INET, SOCK_DGRAM, 0);
	printf("socket: %d", ss);
	
	inet_aton(argv[1], &addr);
	
	sa.sa_family = AF_INET;
	memcpy(&sa.sa_data, &addr, 4);
	
	char msg[2];
	msg[0] = ':';
	msg[1] = ')';
	
	
	printf("%x",sa.sa_data[0]);	printf("%x",sa.sa_data[1]);	printf("%x",sa.sa_data[2]);	printf("%x\n",sa.sa_data[3]);
	
	soo.sin_family = AF_INET;
	soo.sin_port = htons(80);
	soo.sin_addr = addr;
	
	int nu = sendto(ss, msg, sizeof(msg), 0, (struct sockaddr *)&soo, sizeof(soo));
	printf("Cc: %d\n", nu);
	perror("send");
	strerror(nu);
}

