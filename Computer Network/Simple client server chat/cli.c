#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
 
int main(void)
{
  int sockfd = 0,n = 0,conn;
  char sendline[1024],recvline[1024];
  struct sockaddr_in serv_addr;
 
  if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
      printf("\n Error : Could not create socket \n");
      return 1;
    }
 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(5000);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
 
  if((conn=connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)))<0)
    {
      printf("\n Error : Connect Failed \n");
      return 1;
    }
 
   memset(sendline ,'\0' ,sizeof(sendline));
   printf("Send Message : ");	
   while (fgets(sendline, sizeof(sendline), stdin) != NULL) {
	 printf("Sended line : %s \n" ,sendline);	
	  send(sockfd, sendline, strlen(sendline), 0);

	  if (recv(sockfd, recvline, sizeof(recvline),0) == 0){
	   //error: server terminated prematurely
	   printf("The server terminated prematu");
	   return 1;
	  }
	  printf("Server : ");
	  fputs(recvline, stdout);

    }
 
  if( n < 0)
    {
      printf("\n Read Error \n");
    }
  return 0;
}

