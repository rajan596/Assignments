#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

void keyword(char *k);
int i=0,iden=0,keyw=0,num=0,oper=0;

char keys[32][10]={
				   "sizeof",
                   "static",
                   "struct",
                   "switch",
                   "typedef",
                   "union",
                   "unsigned",
                   "void",
                   "volatile",
                   "auto",
                   "break",
                   "case",
                   "char",
                   "const",
                   "continue",
                   "default",
                   "do",
                   "double",
                   "else",
                   "enum",
                   "extern",
                   "float",
                   "for",
                   "goto",
                   "if",
                   "int",
                   "long",
                   "register",
                   "return",
                   "short",
                   "signed",
                   "while"
                   };

int main()
{
	char ch,pre,str[25],delimit[18]=" \t\n,;(){}[]#\"<>",opert[]="!%^&*-+=~|.<>/?";
	int j;
	char fname[50];
	FILE *f1;

    f1 = fopen("input.txt","r");

	if(f1==NULL)
	{
	 printf("File Not Found");
	 exit(0);
	}
	while((ch=fgetc(f1))!=EOF)
	{
		// Multiline commments
       if(pre=='/' && ch=='*') {
       		printf("Comment : ");
     		while(!(pre=='*' && ch=='/')){
     			pre=ch;

     			if(ch!='*' && ch!='/')
					printf("%c",ch);
				ch=fgetc(f1);
     		}
       }	

       // single line comment
       if(pre=='/' && ch=='/'){
       		printf("Single line Comment : ");
       		while((ch=fgetc(f1))!='\n') printf("%c",ch);
       		printf("\n");
       }

       for(j=0;j<=14;j++)
       {
                         if(ch==opert[j])
                         {
                          printf("%c is an operator\n",ch);
                          oper++;
                          str[i]='\0';
                          keyword(str);
                         }
       }
       for(j=0;j<=14;j++)
       {
                         if(i==-1)
                         break;
                         if(ch==delimit[j])
                         {
                                        if(ch=='#')
                                        {
                                                   while(ch!='>')
                                                   {
                                                      printf("%c",ch);
                                                      ch=fgetc(f1);
                                                   }
                                                   printf("%c is a header file\n",ch);
                                                   i=-1;
                                                   break;
                                        }
                                        if(ch=='"')
                                        {
                                                   do
                                                   {
                                                         ch=fgetc(f1);
                                                         printf("%c",ch);
                                                   }while(ch!='"');
                                                   printf("\b is an argument\n");
                                                   i=-1;
                                                   break;
                                        }
                                        str[i]='\0';
                                        keyword(str);
                         }
       }
       if(i!=-1)
       {
        str[i]=ch;
        i++;
       }
       else {
           i=0;
           str[0]='\0';
       }

       pre=ch;
	}
printf("Keywords: %d\nIdentifiers: %d\nOperators: %d\nNumbers: %d\n",keyw,iden,oper,num);
return 0;
}
void keyword(char *p)
{	
	if(strcmp(p,"")==0) {
		i=-1;
		return;
	}

     int k,flag=0;
     for(k=0;k<=31;k++)
     {
                       if(strcmp(keys[k],p)==0)
                       {
                                               printf("%s is a keyword\n",p);
                                               keyw++;
                                               flag=1;
                                               break;
                       }
     }
     if(flag==0)
     {					
                       if(isdigit(p[0]))
                       						  for(int k=0;k<strlen(p);k++){
                       						  		if(p[k]>='0' && p[k]<='9'){

                       						  		}
                       						  		else
                       						  		{	
                       						  			printf("Invalid token : %s\n",p);
                       						  			flag=1;
                       						  			i=-1;
                       						  			return;
                       						  		}
                       						  }
                       						   if(flag==0) {
                                               		printf("%s is a number\n",p);
                                               		num++;
                                           		}
                       }
                       else
                       {
                                               if(p[0]!='\0')
                                               {
                                                             printf("%s is an identifier\n",p);
                                                             iden++;
                                               }
                        }
     

     i=-1;
}
