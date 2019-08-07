#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

struct sockaddr_in nasil;

int main(){

	int msocket, con, port;
	printf("Port numarasi girin: ");
	scanf("%d", &port);
	
	if((msocket = socket(AF_INET,SOCK_STREAM, 0))==-1){
		perror("socket");
		exit(1);
	}
	nasil.sin_family = AF_INET;
	nasil.sin_port = htons(port);
	bzero(nasil.sin_zero, sizeof(nasil.sin_zero));
	
	if((con = connect(msocket, (struct sockaddr *)&nasil, sizeof(nasil))) == -1) {
		perror("connect");
		close(msocket);
		exit(1);
	}else{
		printf("%d acik.\n", port);
		exit(1);
	}
	return 0;
}
