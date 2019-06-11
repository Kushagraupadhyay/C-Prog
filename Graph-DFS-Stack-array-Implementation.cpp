// Depth First Search using stack array implementation
#include<iostream>
#include<stdio.h>
#define max 5
void dfs(int adj[][max],int visited[],int start)
{
  int stack[max],top=-1,i;
  printf("%c->",start+65);
  stack[++top]=start;
  visited[start]=i;
  while(top!=-1)
  {
    start=stack[top];
    for(i=0;i<max;i++)
    {
      if(adj[start][i]==1 && visited[i]==0)
      {
        stack[++top]=i;
        printf("%c->` `",i+65);
        visited[i]=1;
        break;//important step
      }
    }
    if(i==max)
    top--;
  }
}
int main()
{
  int adj[max][max],visited[max]={0},i,j;
  printf("\n Enter the adjascency list ");
  for(i=0;i<max;i++)
  {
    for(j=0;j<max;j++)
    {
      scanf("%d",&adj[i][j]);
    }
  }
  printf("\n DFS Traversal :-");
  dfs(adj,visited,0);
  printf("\n");
  return 0;
}
