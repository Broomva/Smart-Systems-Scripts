
#include<stdio.h>
#include<conio.h>
//#include<math.h>
#include<stdlib.h> //abs value function for ints

int a[30],count=0;
//row=index and column=value

int place(int pos)
{
 int i;
 for(i=1;i<pos;i++)
 {
  if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
   return 0;
 }
 return 1;
}
void print_sol(int n)
{
 int i,j;
 count++;
 printf("\n\nSolution #%d:\n",count);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==j)
    printf("Q\t");
   else
    printf("*\t");
  }
  printf("\n");
 }
}


void queen(int n)
{
 int k=1; //queen itself, flag counter
 a[k]=0;
 while(k!=0)
 {
  do
  {
	a[k]++;
  }while((a[k]<=n)&&!place(k));
  if(a[k]<=n)
  {
   if(k==n)
    print_sol(n);
   else
   {
    k++;
    a[k]=0;
   }
  }
  else
   k--;
 }
}
void main()
{
 int n;
 printf("Enter matrix dimension: \n"); //N dimension for n queens, stored in n
 scanf("%d",&n);
 queen(n); //calls queen function inserting n value (number on queens)
 printf("\nTotal solutions=%d",count);
}
