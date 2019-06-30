//Hamilton cycle using backtracking
#include<iostream>// You can generate permutations with it also by making all matrix entries as 1
#include<conio.h>
#include<stdio.h>
using namespace std;
int V;
void printsolution(int *path)
{
  for(int i=0;i<V;i++)
  cout<<path[i];

  cout<<path[0]<<endl;
}
bool issafe(int **graph,int *path,int pos,int v)
{
  if(graph[path[pos-1]][v]==0)
  return false;
  for(int i=0;i<pos;i++)
   {
     if(path[i]==v)
     {
       return false;
     }
   }
   return true;
}
bool hamiltoncycleuntil(int **graph,int *path,int pos)
{
  if(pos==V)
  {
    if(graph[path[pos-1]][path[0]]==1)
    {
      printsolution(path);
      return false;
    }
      else
      return false;
  }
  for(int i=1;i<V;i++)
  {
    if(issafe(graph,path,pos,i)==true)
    {
      path[pos]=i;
      if(hamiltoncycleuntil(graph,path,pos+1)==true)
      return true;
      path[pos]=-1;
    }
    path[pos]=-1;
  }
  return false;
}
bool hamiltoncycle(int **graph,int *path)
{
  path[0]=0;
  if(hamiltoncycleuntil(graph,path,1)==false)
  {
    //printf("Solution does not exist");
    return false;
  }
  else
  printsolution(path);
  return true;
}
int main()
{
  printf("Enter the number of vertices");
  cin>>V;
  int **graph=new int*[V];
  for(int i=0;i<V;i++)
    graph[i]=new int[V];
  printf("\n Enter the graph matrix");
  for(int i=0;i<V;i++)
  {
    for(int j=0;j<V;j++)
    {
      cin>>graph[i][j];
    }
  }
  int *path=new int[V];
  for(int i=0;i<V;i++)
    path[i]=-1;
  hamiltoncycle(graph,path);
  return 0;
}
