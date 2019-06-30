//Graph coloring problem
#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
using namespace std;
int v;
void printsolution(int *color)
{
  for(int i=0;i<v;i++)
  {
    printf("%d",color[i]);
  }
  cout<<endl;
}
bool issafe(int **graph,int c,int *color,int V)
{
  for(int i=0;i<v;i++)
  {
    if(graph[V][i] && color[i]==c)
    {
      return false;
    }
  }
  return true;
}

bool graphcoloringuntil(int **graph,int m,int *color,int V)
{
  if(v==V)
  {
    printsolution(color);
    return false;
  }
  for(int c=1;c<=m;c++)
  {
    if(issafe(graph,c,color,V))
    {
      color[V]=c;
      if(graphcoloringuntil(graph,m,color,V+1)==true)
      return true;

      color[V]=0;
    }
  }
  return false;
}
bool graphcoloring(int **graph,int m,int *color)
{
  if(graphcoloringuntil(graph,m,color,0)==false)
  {
    //printf("Solution does not exist");
    return false;
  }
  else
  {
    printsolution(color);
    return true;
  }
}
int main()
{
  printf("Enter no of vertices");
  cin>>v;
  int **graph=(int **)malloc(v*sizeof(int *));
  for(int i=0;i<v;i++)
  {
    graph[i]=(int *)malloc(v*sizeof(int));
  }
  printf("Enter graph matrix");
  for(int i=0;i<v;i++)
  {
    for(int j=0;j<v;j++)
    {
      cin>>graph[i][j];
    }
  }
  int *color=(int *)malloc(v*sizeof(int));
  for(int i=0;i<v;i++)
    color[i]=0;
  int m;
  printf("Enter the number of colors");
  cin>>m;
  graphcoloring(graph,m,color);
  return 0;
}
