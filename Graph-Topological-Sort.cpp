//topological sorting of graphs
#include<iostream>
#include<stdio.h>
#include<conio.h>
#define max 10
int n,adj[max][max],front=-1,rear=-1,queue[max];
void create_graph(void);
void display(void);
int find_indeg(int);
void insert_queue(int);
int delete_queue(void);
int main()
{
  int node,indeg[max],topsort[max],delnode,j=0;
  create_graph();
  printf("\n Adjascency matrix is :-\n");
  display();
  for(node=1;node<=n;node++)
  {
    indeg[node]=find_indeg(node);
    if(indeg[node]==0)
    {
      insert_queue(node);
    }
  }
  while(front<=rear)
  {
    delnode=delete_queue();
    topsort[j]=delnode;
    j++;
    for(node=1;node<=n;node++)
    {
      if(adj[delnode][node]==1)
      {
        adj[delnode][node]=0;
        indeg[node]=indeg[node]-1;
        if(indeg[node]==0)
        {
          insert_queue(node);
        }
      }
    }
  }
  printf("\nThe topological sort of the entered graph is :-\n");
  for(node=0;node<j;node++)
  {
    printf("%3d",topsort[node]);
  }
  return 10;
}
void create_graph()
{
  int i,maxedges,org,dest;
  printf("\nEnter the number of vertices:- ");
  scanf("%d",&n);
  maxedges=n*(n-1);
  for(i=1;i<=maxedges;i++)
  {
    printf("\n Enter value of edge %d (0 to quit):-",i);
    scanf("%d%d",&org,&dest);
    if((org==0)&&(dest==0))
    break;
    if((org>n)||(dest>n)||(org<0)||(dest<0))
    {
      printf("\n Invalid Edges enter valid Edges");
      i--;
    }
    else
    {
      adj[org][dest]=1;
    }
  }
}
void display()
{
  int i,j;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      printf("%3d",adj[i][j]);
    }
    printf("\n");
  }
}
int find_indeg(int node)
{
  int i,indeg=0;
  for(i=1;i<=n;i++)
  {
    if(adj[i][node]==1)     
    {
      indeg++;
    }
  }
  return indeg;
}
void insert_queue(int node)
{
  if(rear==max-1)
  {
    printf("\n Queue id full cannot insert more nodes");
  }
  else
  {
    if(front==-1)
    front=0;
    queue[++rear]=node;
  }
}
int delete_queue()
{
  int delnode;
  if(front==-1 || front>rear)
  {
    printf("Already empty queue cannot delete more ");
    return -1;
  }
  else
  {
    delnode=queue[front++];
    return delnode;
  }
}
