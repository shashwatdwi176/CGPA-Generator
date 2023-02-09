//***************************************************************
//                   HEADER FILE USED IN PROJECT
//***************************************************************

#include<conio.h>
#include<stdio.h>
#include<process.h>
# include<stdlib.h>
# define clrscr(); system("cls");


//****************gotoxy function**************
void gotoxy(int x,int y)
{
printf("%c[%d;%df",0x1B,y,x);
}

//***************************************************************
//                   STURUCTURE USED IN PROJECT
//****************************************************************

struct student
{
 int registration_number;
 char name[50];
 int physics_marks,cs_marks,maths_marks,ecc_marks,huc_marks,english_marks;
 float cgpa;
 char grade;
 int std;
}students;

//***************************************************************
//        global declaration
//****************************************************************

 FILE *fptr;

//***************************************************************
//        function to write in file
//****************************************************************

void write_student()
   {
    fptr=fopen("student.csv","a");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The registration number of student ");
    scanf("%d",&students.registration_number);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    gets(students.name);
    printf("\nEnter The marks in PHY101 out of 100 : ");
    scanf("%d",&students.physics_marks);
    printf("\nEnter The marks in CS101 out of 100 : ");
    scanf("%d",&students.cs_marks);
    printf("\nEnter The marks in MAC101 out of 100 : ");
    scanf("%d",&students.maths_marks);
    printf("\nEnter The marks in ECC101 out of 100 : ");
    scanf("%d",&students.ecc_marks);
    printf("\nEnter The marks in HUC101 out of 100 : ");
    scanf("%d",&students.huc_marks);
    printf("\nEnter The marks in HUC102 out of 100 : ");
    scanf("%d",&students.english_marks);    
    students.cgpa=(students.physics_marks+students.cs_marks+students.maths_marks+students.ecc_marks+students.huc_marks+students.english_marks)/60.0;
    if(students.cgpa>=9.5 && students.cgpa<=10)
       students.grade='E';
    else if(students.cgpa>=9 &&students.cgpa<9.5)
      students.grade='A';
    else if(students.cgpa>=8 &&students.cgpa<9)
      students.grade='B';
    else if(students.cgpa>=7 &&students.cgpa<8)
      students.grade='c';
    else if(students.cgpa>=6 &&students.cgpa<7)
      students.grade='D';
    else if(students.cgpa>=5 &&students.cgpa<6)
      students.grade='P';
    else
     students.grade='F';
    fwrite(&students,sizeof(students),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}

//**************function write multiple record***************

    void multiple_add()
    {
    int a,i=1;
    clrscr();
    printf("\n\n\t\tEnter The Number Of Student\'s Record  You Want To Add: ");
    scanf("%d",&a);
    while(i<=a)
{
    write_student();
    i++;
    getch();
}
fclose(fptr);

}


//***************************************************************
//        function to read all records from file
//****************************************************************


void display_all()
{
    clrscr();
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.csv","r");
    while((fread(&students,sizeof(students),1,fptr))>0)
    {
      printf("\nRegistration number of Student : %d",students.registration_number);
      printf("\nName of student : %s",students.name);
      printf("\nMarks in PHY101 : %d",students.physics_marks);
      printf("\nMarks in CS101 : %d",students.cs_marks);
      printf("\nMarks in MAC101 : %d",students.maths_marks);
      printf("\nMarks in ECC101 : %d",students.ecc_marks);
      printf("\nMarks in HUC101 : %d",students.huc_marks);
      printf("\nMarks in HUC102 : %d",students.english_marks);

      printf("\nCGPA of student is  : %.2f",students.cgpa);
      printf("\nGrade of student is : %c",students.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}


//***************************************************************
//        function to read specific record from file
//****************************************************************


void display_sp(int n)
{
    int flag=0;
    fptr=fopen("student.csv","r");
    while((fread(&students,sizeof(students),1,fptr))>0)
    {
     if(students.registration_number==n)
        {
         clrscr();
            printf("\nRegistration number of student : %d",students.registration_number);
            printf("\nName of student : %s",students.name);
            printf("\nMarks in Physics : %d",students.physics_marks);
            printf("\nMarks in CS101 : %d",students.cs_marks);
            printf("\nMarks in MAC101 : %d",students.maths_marks);
            printf("\nMarks in ECC101 : %d",students.ecc_marks);
            printf("\nMarks in HUC101 : %d",students.huc_marks);
            printf("\nMarks in HUC102 : %d",students.english_marks);
            printf("\nPercentage of student is  : %.2f",students.cgpa);
            printf("\nGrade of student is : %c",students.grade);
         flag=1;
        }
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
}


//***************************************************************
//        function to modify record of file
//****************************************************************


void modify_student()
{
    int no,found=0;
    clrscr();
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The Registration number of student");
    scanf("%d",&no);
    fptr=fopen("student.csv","r+");
    while((fread(&students,sizeof(students),1,fptr))>0 && found==0)
    {
    if(students.registration_number==no)
           {
            printf("\nRegistration number of student : %d",students.registration_number);
            printf("\nName of student : %s",students.name);
            printf("\nMarks in Physics : %d",students.physics_marks);
            printf("\nMarks in CS101 : %d",students.cs_marks);
            printf("\nMarks in MAC101 : %d",students.maths_marks);
            printf("\nMarks in ECC101 : %d",students.ecc_marks);
            printf("\nMarks in HUC101 : %d",students.huc_marks);
            printf("\nMarks in HUC102 : %d",students.english_marks);
            printf("\nPercentage of student is  : %.2f",students.cgpa);
            printf("\nGrade of student is : %c",students.grade);
            printf("\nPlease Enter The New Details of student \n");
            printf("\nEnter The Registration number of student ");
            scanf("%d",&students.registration_number);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            gets(students.name);
            printf("\nEnter The marks in physics out of 100 : ");
            scanf("%d",&students.physics_marks);
            printf("\nEnter The marks in CS101 out of 100 : ");
            scanf("%d",&students.cs_marks);
            printf("\nEnter The marks in MAC101 out of 100 : ");
            scanf("%d",&students.maths_marks);
            printf("\nEnter The marks in ECC101 out of 100 : ");
            scanf("%d",&students.ecc_marks);
            printf("\nEnter The marks in HUC101 out of 100 : ");
            scanf("%d",&students.huc_marks);
            printf("\nEnter The marks in HUC102 out of 100 : ");
            scanf("%d",&students.english_marks);
            students.cgpa=(students.physics_marks+students.cs_marks+students.maths_marks+students.ecc_marks+students.huc_marks+students.english_marks)/60.0;
            if(students.cgpa>=9.5 && students.cgpa<=10)
                students.grade='E';
            else if(students.cgpa>=9 &&students.cgpa<9.5)
                students.grade='A';
            else if(students.cgpa>=8 &&students.cgpa<9)
                students.grade='B';
            else if(students.cgpa>=7 &&students.cgpa<8)
                students.grade='c';
            else if(students.cgpa>=6 &&students.cgpa<7)
                students.grade='D';
            else if(students.cgpa>=5 &&students.cgpa<6)
                students.grade='P';
            else
                students.grade='F';
            fseek(fptr,-(long)sizeof(students),1);
            fwrite(&students,sizeof(students),1,fptr);
            printf("\n\n\t Record Updated");
            found=1;
           }
         }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
}


//***************************************************************
//        function to delete record of file
//****************************************************************


void delete_student()
   {
    int no;
    FILE *fptr2;
    clrscr();
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The Registration number of student You Want To Delete");
    scanf("%d",&no);
    fptr=fopen("student.csv","r");

    fptr2=fopen("Temp.xls","w");
    rewind(fptr);
    while((fread(&students,sizeof(students),1,fptr))>0)
    {
       if(students.registration_number!=no)
       {
      fwrite(&students,sizeof(students),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.csv");
    rename("Temp.xls","student.csv");
    printf("\n\n\tRecord Deleted ..");
    getch();
}

//***************************************************************
//        function to display all students grade report
//****************************************************************

    void class_result()
    {
     clrscr();
     fptr=fopen("student.csv","r");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\t\t\t\t\tALL STUDENTS RESULT \n\n");
      printf("==================================================================================================================\n");
      printf("R.No.      Name      PHY101      CS101      MAC101      ECC101     HUC101       HUC102         CGPA          GRADE\n");
      printf("================================================================================================================== \n");

      while((fread(&students,sizeof(students),1,fptr))>0)
     {
       printf("%-6d %-10s %-12d %-12d %-12d %-12d %-12d %-12d %-12.2f  %-12c\n",students.registration_number,students.name,students.physics_marks,students.cs_marks,students.maths_marks,students.ecc_marks,students.huc_marks,students.english_marks,students.cgpa,students.grade);
     }
     fclose(fptr);
     getch();
}

//***************************************************************
//        function to display result menu
//****************************************************************

   void result()
   {
    int ans,rno;
    char ch;
    clrscr();
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Report Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice (1/2)? ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 : class_result();break;
     case 2 : {
        do{
        char ans;
        clrscr();
        printf("\n\nEnter Registration number Of Student : ");
        scanf("%d",&rno);
        display_sp(rno);
        printf("\n\nDo you want to See More Result (y/n)?");
        scanf("%c",&ans);
        }while(ans=='y'||ans=='Y');
        break;
           }
     case 3: break;
     default:  printf("\a");
    }
 }

//***************************************************************
//        INTRODUCTION FUNCTION
//****************************************************************

void intro()
{
 clrscr();
 gotoxy(35,11);
 printf("STUDENT");
 gotoxy(33,14);
 printf("REPORT CARD");
 gotoxy(35,17);
 printf("PROJECT");
 printf("\n\n\n\n\n\nTeam Member:  Shashwat Dwivedi  and  Shubham Yadav");
 printf("\n\nCOLLEGE : Indian Institute of Information Technology Kalyani");
 getch();
}
//***************************************************************
//        ENTRY / EDIT MENU FUNCTION
//****************************************************************
void entry_menu()
{
    char ch2;
   clrscr();
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.CREATE Multiple STUDENT\'s RECORD");
  printf("\n\n\t3.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t4.SEARCH STUDENT RECORD ");
  printf("\n\n\t5.MODIFY STUDENT RECORD");
  printf("\n\n\t6.DELETE STUDENT RECORD");
  printf("\n\n\t7.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-7) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': clrscr();
          write_student();
          break;
    case '2' : multiple_add();break;
    case '3': display_all();break;
    case '4':  {
           int num;
           clrscr();
           printf("\n\n\tPlease Enter The Registration number ");
           scanf("%d",&num);
           display_sp(num);
           }
           break;
      case '5': modify_student();break;
      case '6': delete_student();break;
      case '7': break;
      default:printf("\a");entry_menu();
   }
}
//***************************************************************
//        THE MAIN FUNCTION OF PROGRAM
//****************************************************************
void main()
{
  char ch;
  intro();
  do
    {
      clrscr();
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. RESULT MENU");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
         case '1': clrscr();
               result();
               break;
          case '2': entry_menu();
                break;
          case '3':exit(0);
          default :printf("\a");
    }
    }while(ch!='3');
}
//***************************************************************
//                END OF PROJECT
//***************************************************************