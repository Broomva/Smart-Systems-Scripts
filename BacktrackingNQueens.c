#include<stdio.h>
#include<conio.h>
#include<stdlib.h> //abs value lib for ints
#include<math.h>
#define N 100
 //max matrix dimension

int a[N], count=0; //row=vector index: c, column=vector value: a[c]
int n=0, c=0, i=0, j=0; //variable init cleanse

//Functions init
void root(int);
int accept(int);
void output(int);

//main
void main()
{
  int n; //store matrix dimension to run the code with
  printf("Enter matrix dimension (square): ");
  scanf("%d", &n); //input to int n
  root(n); //calls function to start the tree
  printf("\n Total solutions found: %d", count);
}

void root(int n) //Begin partial candidates tree and prints solutions
{
  int c=1; //the first candidate, first row
  a[c]=0; //will go to vector position 0, zero column

  while(c!=0)
  {
    do //only while the position still in boundary and accept procedure met
    {
      a[c]++; //first(n,c), on firt run, will place queen in 1,1
    }
    while((a[c]<=n)&&!accept(c)); //a[c] will increase (next column) while being within n
                                  //AND not in an already positioned c (branch).
                                  //will keep runing do cicle until cannot place a candidate,
                                  //that is, incrementing to the next column
    if(a[c]<=n) //still in boundary?
    {
      if(c==n) //boundary reached, max row. if will only run when a[c]==n
      {
        output(n); //print solution
      }
      else //while in the boundary
      {
        c++; //goes to next row
        a[c]=0; //resets columns
      }
    }
    else
    {
      c--; //if not a single constraint is satisfied, bactrack to previous candidate
    }
  }
}

int accept(int pos)
{
  for(int i=1; i<pos; i++)  //runs all positions in matrix
  {
    if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos)))) //reject(i, pos))//if vector a in i is equal to a in pos,
                                                        //that is a in column candidate, then there
                                                        //would be a queen already in that vector position
                                                        //OR the abs of both positions difference being equal
                                                        //to the difference of each value (actual matrix posistion
                                                        //run vs actual candidate branch position).
                                                        //if any of the rejection position constraints are met,
                                                        //then that matrix position is empty and will cross
                                                        //in neither diagonals nor straigth lines
    {
      return 0;
    }
  }
  return 1;
}

void output(int n)
{
  int i, j;
  count++; //solution finded, solution counter increases
  printf("\n Solution no: %d\n", count); //prints actual solution number
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)  //matrix run
    {
      if(a[i]==j) //if stored vector pos i equals j, stored candidate printed
      {
        printf("1 ");
      }
      else
      {
        printf("0 ");
      }
    }
    printf("\n");
  }
}

/*
int reject(int i, pos)
{
  if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
*/
