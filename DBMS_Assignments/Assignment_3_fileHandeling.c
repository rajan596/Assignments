#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

typedef struct
{
    int id;
    char name[20];
    char department[10];
}student;

char file1[]={"index.txt"};
char file2[]={"detail.txt"};

int menu();
void append();
void display();
void search();
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
    FILE *fp1=fopen(file1,"ab");
    FILE *fp2=fopen(file2,"ab");

    printf("Roll no / ID : ");
    scanf("%d",&s.id);

    printf("Name : ");
    scanf("%s",s.name);

    printf("Department : ");
    scanf("%s",s.department);

    fwrite(&s.id,sizeof(s.id),1,fp1);  // index
    fwrite(&s,sizeof(s),1,fp2);  // content

    fclose(fp1);
    fclose(fp2);
}

void display()
{

    FILE *fp=fopen(file2,"rb");   //content

    if (fp==NULL)
    {
        printf("No such file exists.....\n");
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
    FILE *fp1=fopen(file1,"rb");
    student s;
    int id;
    int found=0;

    printf("Enter ID : ");
    scanf("%d",&id);

    int no;
    int record=0;
    while(1)
    {
        fread(&no,sizeof(no),1,fp1);
        record++;

        if(feof(fp1))
            break;

        if(id==no)
        {
            found=1;

            FILE *fp2=fopen(file2,"rb");
            fseek(fp2,sizeof(s)*(record-1),SEEK_SET);
            fread(&s,sizeof(s),1,fp2);

            printf("---------- Student Records -----------\n");
            printf("ID\tName\t\t\tDepartment\n\n");
            printf("%02d\t",s.id);
            printf("%-20s\t",s.name);
            printf("%-5s",s.department);
            printf("\n");
            fclose(fp2);

            break;

        }
    }

    if(found==0)
    {
        printf("no record found\n\n");
    }

    fclose(fp1);
}
// using temp file
/*
void delete_record()
{
    FILE *fp,       //detail.txt
         *fp1,      //temp_detail.txt
         *fp2,      //index.txt
         *fp3;      //temp_index.txt
    int id;
    student s;
    fp=fopen(file2,"rb+");
    fp1=fopen("temp_detail.txt","wb+");
    fp2=fopen(file1,"rb+");
    fp3=fopen("temp_index.txt","wb+");

    printf("Enter student id to delete record : ");
    scanf("%d",&id);

    //------ Copying data filename to temp.txt except id==s.id
    while(1)
    {
        fread(&s,sizeof(s),1,fp);

        if(feof(fp))
            break;

        if(id!=s.id)
        {
            fwrite(&s,sizeof(s),1,fp1);
            fwrite(&s.id,sizeof(s.id),1,fp3);
        }
    }

    fclose(fp);
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    remove(file2);
    remove(file1);
    rename("temp_detail.txt",file2);      // rename(oldfile , newfile)
    rename("temp_index.txt",file1);

    //---------------------end of copy

    printf("\n\nSuccessfully deleted record...\n\n");
}
*/

// without using temp file
void delete_record()
{
    FILE *fp1,       //index.txt
         *fp2;      //detail.txt
    int count=0;
    int id,no,index[50];    // index[] ans ss[] to store datail of file except index to be deleted
    student s,ss[50];

    fp1=fopen(file1,"rb+");
    fp2=fopen(file2,"rb+");

    printf("Enter student id to delete record : ");
    scanf("%d",&id);

    while(1)
    {
        fread(&s,sizeof(s),1,fp2);
        fread(&no,sizeof(no),1,fp1);

        if(feof(fp1))
            break;

        if(id!=s.id)
        {
            ss[count]=s;
            index[count]=no;
            count++;
        }

    }
    fclose(fp1);
    fclose(fp2);

    // reopen file
    fp1=fopen(file1,"wb");
    fp2=fopen(file2,"wb");
    fwrite(&s.id,sizeof(s.id),count,fp1);
    fwrite(&ss,sizeof(ss[0]),count,fp2);

    fclose(fp1);
    fclose(fp2);

    printf("\n\nSuccessfully deleted record...\n\n");
}
