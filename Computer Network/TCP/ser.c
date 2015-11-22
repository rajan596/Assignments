#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(void)
{
  int listenfd = 0,connfd = 0;
  struct sockaddr_in serv_addr,client_addr;
  char buffer[1025];  
  int numrv,n;  
 
  listenfd = socket(AF_INET, SOCK_STREAM, 0);
  printf("socket retrieve success\n");
  
  memset(&serv_addr, '0', sizeof(serv_addr));
  memset(buffer, '\0', sizeof(buffer));
      
  serv_addr.sin_family = AF_INET;    
  serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); 
  serv_addr.sin_port = htons(5000);    
 
  bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
  
  if(listen(listenfd, 10) == -1){
      printf("Failed to listen\n");
      return -1;
  }
  
  while(1)
    {
      int clilen=sizeof(client_addr);
      connfd = accept(listenfd, (struct sockaddr*)(&client_addr) , &clilen); // accept awaiting request
	while ( (n = recv(connfd, buffer, sizeof(buffer),0)) > 0)  {
  		printf("Client : ");
   		fputs(buffer,stdout);

		memset(buffer ,'\0' ,sizeof(buffer));
		printf("Send message : ");
		fgets(buffer , sizeof(buffer),stdin);
		send(connfd, buffer, sizeof(buffer), 0);
  	}
 
      close(connfd);    
      sleep(1);

    }
 
  return 0;
}

