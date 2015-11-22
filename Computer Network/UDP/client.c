#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include <netdb.h>
#include<unistd.h>
#include<string.h>

int main()
{
	int sfd,numbytes;
	char ip[15];
	char buf[100],buf2[100];
	struct sockaddr_in client,server;
	int sin_size;
	strcpy(buf2 , "\0");
	client.sin_family=AF_INET;
	client.sin_port=htons(5555);
	printf("Enter IP address of Server :\n");
	gets(ip);
  	client.sin_addr.s_addr = inet_addr(ip);
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	sin_size=sizeof(struct sockaddr_in);
	printf("waiting for response....\n");
	
	while(1) 
	{	
		printf("Ask your question : ");
		gets(buf2);
		//strcpy(buf2,"hello");
		sendto(sfd,buf2,strlen(buf2),0,(struct sockaddr *)&client,sin_size);
		strcpy(buf , "\0");
		numbytes=recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&server,&sin_size);
		buf[numbytes]='\0';
		printf("%s\n",buf);
	}
	close(sfd);
return 0;
}
