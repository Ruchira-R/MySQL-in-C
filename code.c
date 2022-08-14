#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<conio.h>
#include <my_global.h>
#include <mysql.h>
void login();
void student();
void teacher();
void stu_retrieve();
void stu_delete();
void stu_update();
void stu_add();
void tea_retrieve();
void tea_delete();
void tea_update();
void tea_add();
void finish_with_error(MYSQL *con)
{
  fprintf(stderr, "%s\n", mysql_error(con));
  mysql_close(con);
  exit(1);        
}
int main()
{
    int i,j,k,l,input,x=25,y=5,sp=3,xd=10,old=0,newval=1,ex=0;
    for(i=0;;++i)
    {
        if(kbhit())
        {
            input=getch();
            if(input=='w'&&old==2)
                newval=1;
            if(input=='s'&&old==1)
                newval=2;
            if(input=='v'&&old==1)
                {login();old=0;newval=1;}
            if(input=='v'&&old==2)
                ex=1;
            if(input=='w'&&old==1)
                newval=2;
            if(input=='s'&&old==2)
                newval=1;
        }
        if(old!=newval)
        {
            system("cls");
            if(newval==1)
            {
                for(j=0;j<y-1;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Login");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Exit");
            }
            if(newval==2)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Login");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Exit");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");

            }

            old=newval;
        }
        if(ex==1)
            break;
    }
    return 0;
}
void login()
{
    system("cls");
    char un[50],p[50];
    int check=1,i,j,k,l,input,x=15,y=5,sp=7,xd=25,old=0,newval=1,ex=0;
    printf("Enter username : ");
    gets(un);
    printf("Enter password and press v : ");
    i=0;
    for(j=0;;++j)
    {
        if(kbhit())
        {
            input=getch();
            if(input!='v'){
            printf("*");
            p[i]=(char)(input);
            ++i;}
            if(input=='v')
                break;
        }
    }
    p[i]='\0';
    if(!strcmp(un,"admin") && !strcmp(p,"123"))
        check=1;
    else
        check=0;
    if(check==0)
        goto end;
    for(i=0;;++i)
    {
        if(kbhit())
        {
            input=getch();

            if(input=='w'&&old>1)
                newval-=1;
            if(input=='s'&&old<3)
                newval+=1;
            if(input=='v'&&old==1)
                {student();old=0;newval=1;}
            if(input=='v'&&old==2)
            {
                teacher();old=0;newval=1;
            }
            if(input=='v'&&old==3)
                ex=1;
            if(input=='w'&&old==1)
                newval=3;
            if(input=='s'&&old==3)
                newval=1;
        }
        if(old!=newval)
        {
            system("cls");
            if(newval==1)
            {
                for(j=0;j<y-1;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Student");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Teacher");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");
            }
            if(newval==2)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Student");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Teacher");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==3)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Student");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Teacher");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");

            }


            old=newval;
        }
        if(ex==1)
            break;
    }
    end:
        ;
}
void student()
{
    system("cls");
    int check=0,i,j,k,l,input,x=15,y=5,sp=7,xd=25,old=0,newval=1,ex=0;
    for(i=0;;++i)
    {
        if(kbhit())
        {
            input=getch();
            if(input=='w'&&old>1)
                newval-=1;
            if(input=='s'&&old<5)
                newval+=1;
            if(input=='v'&&old==1)
                {stu_retrieve();old=0;newval=1;}
            if(input=='v'&&old==2)
            {
                stu_update();old=0;newval=1;
            }
            if(input=='v'&&old==3)
            {
                stu_delete();old=0;newval=1;
            }
            if(input=='v'&&old==4)
            {
                stu_add();old=0;newval=1;
            }
            if(input=='v'&&old==5)
                ex=1;
            if(input=='w'&&old==1)
                newval=5;
            if(input=='s'&&old==5)
                newval=1;
        }
        if(old!=newval)
        {
            system("cls");
            if(newval==1)
            {
                for(j=0;j<y-1;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==2)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==3)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==4)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n\n");

                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }

            if(newval==5)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n\n");

                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");

            }

            old=newval;
        }
        if(ex==1)
            break;
    }
}
void teacher()
{
    system("cls");
    int check=0,i,j,k,l,input,x=15,y=5,sp=7,xd=25,old=0,newval=1,ex=0;
    for(i=0;;++i)
    {
        if(kbhit())
        {
            input=getch();
            if(input=='w'&&old>1)
                newval-=1;
            if(input=='s'&&old<5)
                newval+=1;
            if(input=='v'&&old==1)
                {tea_retrieve();old=0;newval=1;}
            if(input=='v'&&old==2)
            {
                tea_update();old=0;newval=1;
            }
            if(input=='v'&&old==3)
            {
                tea_delete();old=0;newval=1;
            }
            if(input=='v'&&old==4)
            {
                tea_add();old=0;newval=1;
            }
            if(input=='v'&&old==5)
                ex=1;
            if(input=='w'&&old==1)
                newval=5;
            if(input=='s'&&old==5)
                newval=1;
        }
        if(old!=newval)
        {
            system("cls");
            if(newval==1)
            {
                for(j=0;j<y-1;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==2)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==3)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }
            if(newval==4)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n\n");

                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");

            }

            if(newval==5)
            {
                for(j=0;j<y;++j)
                    printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Retrieve");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Update");
                printf("\n\n\n");

                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Delete");
                printf("\n\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Add");
                printf("\n\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<(xd-sp)/2;++j)
                    printf(" ");
                printf("Back");
                printf("\n");
                for(j=0;j<x;++j)
                    printf(" ");
                for(j=0;j<xd;++j)
                    printf("~");
                printf("\n");

            }

            old=newval;
        }
        if(ex==1)
            break;
    }
}
void stu_retrieve()
{
    system("cls");
     MYSQL *con = mysql_init(NULL);
  
  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, "SELECT * FROM student")) 
  {
      finish_with_error(con);
  }
  
  MYSQL_RES *result = mysql_store_result(con);
  
  if (result == NULL) 
  {
      finish_with_error(con);
  }
int j;
  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  

  while ((row = mysql_fetch_row(result))) 
  { 
      for(int i = 0; i < num_fields; i++) 
      { 
          printf("%s",row[i]?row[i]:"NULL");
          for(j=0;j<20-strlen(row[i]);++j)
          printf(" ");
      } 
          printf("\n"); 
  }
  
  mysql_free_result(result);
  mysql_close(con);

    getch();
    
}
void stu_delete()
{    system("cls");
    int sc;
    printf("Enter the student details :\n ");
    printf("Enter the student code : ");
    scanf("%d",&sc);
    printf("\n");
    MYSQL *con = mysql_init(NULL);
    char query[100] = {0};
 snprintf(query,100, "delete from student where scode = %d;",sc);
 if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }
   else{

       printf("SUCCESSFUL");
   }
  getch();
  system("cls");
    
}
void stu_update()
{   
    system("cls");
    int sc;
    char n[100],m[100];
    printf("Enter the student details :\n ");
    printf("Enter the student code : ");
    scanf("%d",&sc);
    printf("\n");
    printf("Enter the column to be updated : ");
    scanf("%s",n);
    printf("\n");
    printf("Enter value to be updated : ");
    scanf("%s",m);
    printf("\n");
    MYSQL *con = mysql_init(NULL);
    char query[100] = {0};
 snprintf(query,100, "update student set %s = '%s' where scode = %d ;",n,m,sc);
 if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }
   else{

       printf("SUCCESSFUL");
   }
  getch();
  system("cls");
}
void stu_add()
 {
          system("cls");
    char n[20],dob[15],email[100];int sc,year,fd,fa;
    printf("Enter the student details :\n ");
    printf("Enter the student code : ");
    scanf("%d",&sc);
    printf("\n");
    printf("Enter the name : ");
    scanf("%s",n);
    printf("\n");
    printf("Enter the year : ");
    scanf("%d",&year);
    printf("\n");
    printf("Enter the date of birth in yyyy/mm/dd : ");
    scanf("%s",dob);
    printf("\n");
    printf("Enter the email id : ");
    scanf("%s",email);
    printf("\n");
    printf("Enter the fee due : ");
    scanf("%d",&fd);
    printf("\n");
    printf("Enter the fee advance : ");
    scanf("%d",&fa);
    printf("\n");

     MYSQL *con = mysql_init(NULL);
    char query[100] = {0};
 snprintf(query,100, "INSERT INTO student VALUES (%d,'%s','%s',%d,%d,%d,'%s')",sc,dob,email,year,fd,fa,n);
 if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);

         
}
if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }
   else{

       printf("SUCCESSFUL");
   }
getch();
system("cls");

 }
void tea_retrieve()
{
        system("cls");
     MYSQL *con = mysql_init(NULL);
  
  if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, "SELECT * FROM teacher")) 
  {
      finish_with_error(con);
  }
  
  MYSQL_RES *result = mysql_store_result(con);
  
  if (result == NULL) 
  {
      finish_with_error(con);
  }

  int num_fields = mysql_num_fields(result);

  MYSQL_ROW row;
  int j;
  while ((row = mysql_fetch_row(result))) 
  { 
      for(int i = 0; i < num_fields; i++) 
      { 
          printf("%s",row[i]?row[i]:"NULL");
          for(j=0;j<20-strlen(row[i]);++j)
          printf(" ");
      } 
          printf("\n"); 
  }
  
  mysql_free_result(result);
  mysql_close(con);
getch();
}
void tea_delete()
{
         system("cls");
    int tc;
    printf("Enter the teacher details :\n ");
    printf("Enter the teacher code : ");
    scanf("%d",&tc);
    printf("\n");
    MYSQL *con = mysql_init(NULL);
    char query[100] = {0};
 snprintf(query,100, "delete from teacher where tcode = %d;",tc);
 if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }
   else{

       printf("SUCCESSFUL");
   }
  getch();
  system("cls");
    

}
void tea_update()
{
         system("cls");
    int tc;
    char n[100],m[100];
    printf("Enter the teacher details :\n ");
    printf("Enter the teacher code : ");
    scanf("%d",&tc);
    printf("\n");
    printf("Enter the column to be updated : ");
    scanf("%s",n);
    printf("\n");
    printf("Enter value to be updated : ");
    scanf("%s",m);
    printf("\n");
    MYSQL *con = mysql_init(NULL);
    char query[100] = {0};
 snprintf(query,100, "update teacher set %s = '%s' where tcode = %d ;",n,m,tc);
 if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }
   else{

       printf("SUCCESSFUL");
   }
  getch();
  system("cls");
    
}
void tea_add()
{
 system("cls");
    char n[20],doj[15];int tc,bas,cca,ta;
    printf("Enter the teacher details :\n ");
    printf("Enter the teacher code : ");
    scanf("%d",&tc);
    printf("\n");
    printf("Enter the name : ");
    scanf("%s",n);
    printf("\n");
    printf("Enter the date of joining in yyyy/mm/dd : ");
    scanf("%s",doj);
    printf("\n");
    printf("Enter the basic pay : ");
    scanf("%d",&bas);
    printf("\n");
    printf("Enter the city compensatory allowance : ");
    scanf("%d",&cca);
    printf("\n");
    printf("Enter the transport allowance : ");
    scanf("%d",&ta);
    printf("\n");
     MYSQL *con = mysql_init(NULL);
    char query[100] = {0};
 snprintf(query,100, "INSERT INTO teacher VALUES (%d,'%s',%d,'%s',%d,%d)",tc,n,bas,doj,cca,ta);
 if (con == NULL)
  {
      fprintf(stderr, "mysql_init() failed\n");
      exit(1);
  }  
  
  if (mysql_real_connect(con, "localhost", "root", "ruchira", 
          "school", 0, NULL, 0) == NULL) 
  {
      finish_with_error(con);
  }    
  
  if (mysql_query(con, query)) 
  {
      finish_with_error(con);
  }
   else{

       printf("SUCCESSFUL");
   }
  getch();
  system("cls");
}
