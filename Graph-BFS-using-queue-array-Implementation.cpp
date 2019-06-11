// Breadth First Search usng queue array implementation
#include<iostream>
#include<conio.h>
#include<stdio.h>
#define max 10

void bfs(int adj[][5],int visited[],int start)
{
  int queue[max],front=-1,rear=-1,i;
  queue[++rear]=start;
  visited[start]=1;
  while(front!=rear)
  {
    start=queue[++front];
    //if(start==4)
    // printf("5 \t");
    // else
    printf("%c \t",start+65);
    for(i=0;i<5;i++)
    {
      if(adj[start][i]==1 && visited[i]==0)
      {
        queue[++rear]=i;
        visited[i]=1;
      }
    }
  }
}
int main()
{
  int visited[max]={0};
  int adj[5][5],i,j;
  printf("\nEnter the adjascency matrix");
  for(i=0;i<5;i++)
  {
    for(j=0;j<5;j++)
    {
      scanf("%d",&adj[i][j]);
    }
  }
  bfs(adj,visited,0);
  return 0;
}
