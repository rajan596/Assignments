#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>

int main()
{
	int sfd;
	struct sockaddr_in serv,client;
	int sin_size;
	char buf[100],buf1[100];
	int res=0;
	
	serv.sin_family=AF_INET;
	serv.sin_port=htons(5555);
	serv.sin_addr.s_addr=htonl(INADDR_ANY);
	sfd=socket(AF_INET,SOCK_DGRAM,0);
	bind(sfd,(struct sockaddr *)&serv,sizeof(struct sockaddr));
	sin_size=(int)sizeof(struct sockaddr_in);
	strcpy(buf , "\0");
	strcpy(buf1 , "\0");
	while(1)
	{	
		res=recvfrom(sfd,buf,sizeof(buf),0,(struct sockaddr *)&client,&sin_size);
		buf[res]='\0';
		printf(" %s : %s \n",inet_ntoa(client.sin_addr),buf);
		
		printf("Cortana your ans : ");
		gets(buf);
		sendto(sfd,buf,strlen(buf),0,(struct sockaddr *)&client,sin_size);
		strcpy(buf , "\0");
		
	}
	close(sfd);
	
return 0;
}
