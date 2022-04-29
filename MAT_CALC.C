#include<stdio.h>
#include<conio.h>
int a[5][5],b[5][5],c[5][5];
int x=2,y=2,z=2;
void zero()
{
 int i,j;
 for(i=0;i<5;i++)
  {
   for (j=0;j<5;j++)
   {
    a[i][j]=0;
    b[i][j]=0;
    c[i][j]=0;
   }
  }
}
void menu()
{
 gotoxy(20,3);
 printf("Enter A to add two matrices");
 gotoxy(20,6);
 printf("Enter B to subtract two matrices");
 gotoxy(20,9);
 printf("Enter C to multiply two square matrices");
 gotoxy(20,12);
 printf("Enter D to get transpose of a matrix");
 gotoxy(20,15);
 printf("Enter E to exit\n");
 gotoxy(20,18);
}
void input1()
{
 int i,j;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   printf("Enter A[%d][%d]\n",i+1,j+1);
   scanf("%d",&a[i][j]);
  }
 }
}
void input2()
{
 int i,j;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   printf("Enter B[%d][%d]\n",i+1,j+1);
   scanf("%d",&b[i][j]);
  }
 }

}
void add()
{
 int i,j;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   c[i][j]=a[i][j]+b[i][j];
  }
 }
}
void subtract()
{
 int i,j;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   c[i][j]=a[i][j]-b[i][j];
  }
 }
}
void mul()
{
 int i,j,k;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   for(k=0;k<z;k++)
   {
    c[i][j]+=a[i][k]*b[k][j];
   }
  }
 }
 y=z;
}
void trans()
{
 int i,j;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   c[j][i]=a[i][j];
  }
 }
 x=x+y;
 y=x-y;
 x=x-y;
}
void print()
{
 int i,j;
 for(i=0;i<x;i++)
 {
  for(j=0;j<y;j++)
  {
   printf("%d\t",c[i][j]);
  }
  printf("\n");
 }
}

void main()
{
 char loop='N',key=0;
 int buffer;
 do{
  clrscr();
  zero();
  menu();
  fflush(stdin);
  scanf("%c",&key);
  clrscr();
  switch(key)
  {
   case 'A':
    printf("Adding two matrices\n");
    printf("Enter the size of the matrices\n");
    scanf("%d %d",&x,&y);
    input1();
    input2();
    add();
    print();
    break;
   case 'B':
    printf("Subtracting two matrices\n");
    printf("Enter the size of the matrices\n");
    scanf("%d %d",&x,&y);
    input1();
    input2();
    subtract();
    print();
    break;
   case 'C':
    printf("Multiplying two square matrices\n");
    printf("Enter the size of the matrices\n");
    scanf("%d",&x);
    y=x;
    z=y;
    input1();
    input2();
    mul();
    print();
    break;
   case 'D':
    printf("Transpose of a matrix\n");
    printf("Enter the size of the matrix\n");
    scanf("%d %d",&x,&y);
    input1();
    trans();
    print();
    break;
   case 'E':
    return;
   default:
    printf("Incorrect value entered, please retry\n");
  }
  printf("Perform another function? Y/N\n");
  fflush(stdin);
  scanf("%c",&loop);
 }while(loop=='Y');
}
