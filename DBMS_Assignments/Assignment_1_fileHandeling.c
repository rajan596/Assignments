/*
*1) Sequential File Organization
*
*   Implement following problem statement using C language
*
*      Make a structure of student detail and perform the following operations on it.
*
* Write a program to read data from a given text file.
* Write a program to write data to a given text file.
* Write a program to copy the content of one file to another.
* Write a program to search specific record from a given file.
* Write a program to delete a specific record from a given file.
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
    int id;
    char name[20];
    char department[10];
}student;

char filename[]={"data.txt"};
char file2[]={"copiedfile.txt"};

int menu();
void append();
void display();
void search();
void copy_file();
void delete_record();


int main()
{
    while(1)
    {
        system("cls");
        int choice=menu();

        switch(choice)
        {
            case 1: append();
                system("pause");
                break;

            case 2: display();
                system("pause");
                break;

            case 3:
                search();
                system("pause");
                break;

            case 4:
                delete_record();
                system("pause");
                break;
            case 5:
                 copy_file();
                 system("pause");
                break;

            default:
                printf("Wrong Entry\n");
                system("pause");
                break;
        }
    }

    getch();
    return 0;
}

int menu()
{
    printf("1 : Insert / Append \n");
    printf("2 : Display All records\n");
    printf("3 : Search\n");
    printf("4 : Delete record\n");
    printf("5 : Copy file\n");

    int choice;
    printf("Enter your choice : ");
    scanf("%d",&choice);

    return choice;
}

void append()
{
    student s;
    FILE *fp=fopen(filename,"ab");

    printf("Roll no / ID : ");
    scanf("%d",&s.id);

    printf("Name : ");
    scanf("%s",s.name);

    printf("Department : ");
    scanf("%s",s.department);

    fwrite(&s,sizeof(s),1,fp);

    fclose(fp);
}

void display()
{

    FILE *fp=fopen(filename,"rb");
    
    if (fp==NULL)
    {
        printf("Error Reading file or No such file is exists..");
        break;
    }

    printf("---------- Student Records -----------\n");
    printf("ID\tName\t\t\tDepartment\n\n");

    // Empty file
    if(feof(fp))
    {
        printf("No record found\n");
    }

    while(1)
    {
        student s;
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
            break;

        printf("%02d\t",s.id);
        printf("%-20s\t",s.name);
        printf("%-5s",s.department);
        printf("\n");
    }

    fclose(fp);
}

void search()
{
    FILE *fp=fopen(filename,"rb");
    student s;
    int id;
    int found=0;

    printf("Enter ID : ");
    scanf("%d",&id);

    while(1)
    {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
            break;

        if(id==s.id)
        {
            found=1;

            printf("---------- Student Records -----------\n");
            printf("ID\tName\t\t\tDepartment\n\n");
            printf("%02d\t",s.id);
            printf("%-20s\t",s.name);
            printf("%-5s",s.department);
            printf("\n");

        }
    }

    if(found==0)
    {
        printf("no record found\n\n");
    }

    fclose(fp);
}

void copy_file()
{
    FILE *fp,*fp1;
    student s;

    fp=fopen(filename,"rb");
    fp1=fopen(file2,"wb");

    while(1)
    {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
            break;

        fwrite(&s,sizeof(s),1,fp1);
    }

    fclose(fp);
    fclose(fp1);

    printf("\nFile successfully copied\n");

}

/* Logic : delete_record() function
* Copy all data from main file to temp file except the record we have to delete(id=s.id)
*
* Then again transfer data from temp to our main file .. it will not contain id=s.id   or rename temp file
*/

void delete_record()
{
    FILE *fp,*fp1;
    int id;
    student s;
    fp=fopen(filename,"rb+");
    fp1=fopen("temp.txt","wb+");

    printf("Enter student id to delete record : ");
    scanf("%d",&id);

    //------ Copying data filename to temp.txt except id==s.id
    while(1)
    {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
            break;

        if(id!=s.id)
            fwrite(&s,sizeof(s),1,fp1);
    }

    fclose(fp);
    fclose(fp1);
    /*
    //------copying from temp.txt to filename
    fp=fopen(filename,"wb");
    fp1=fopen("temp.txt","rb");

    while(1)
    {
        fread(&s,sizeof(s),1,fp1);

        if(feof(fp1))
            break;

        fwrite(&s,sizeof(s),1,fp);
    }*/
    remove(filename);
    rename("temp.txt",filename);      // rename(oldfile , newfile)

    fclose(fp);
    fclose(fp1);
    //---------------------end of copy

    printf("\n\nSuccessfully deleted record...\n\n");
}
