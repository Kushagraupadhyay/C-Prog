// graph adjscency list representation
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
#define max 10
struct node
{
  int vertex;
  struct node *next;
};
struct node *gnode;
void creategraph(struct node *adj[],int);
void displaygraph(struct node *adj[],int);
void deletegraph(struct node *adj[],int);
int main()
{
  struct node *adj[max];
  int i,non;
  printf("\n Enter the number of nodes in the graph");
  scanf("%d",&non);
  for(i=0;i<non;i++)
  {
    adj[i]=NULL;
  }
  creategraph(adj,non);
  printf("\nThe graph is ");
  displaygraph(adj,non);
  deletegraph(adj,non);
  return 0;
}
void creategraph(struct node *adj[],int non)
{
      struct node *newnode,*last;
      int i,j,n,val;
      for(i=0;i<non;i++)
      {
        last=NULL;
        printf("\nEnter the number of neighbours of %d :- ",i);
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
          printf("\n Enter the %d neighbour of %d :-",j,i);
          scanf("%d",&val);
          newnode=(struct node *)malloc(sizeof(struct node));
          newnode->vertex=val;
          newnode->next=NULL;
          if(adj[i]==NULL)
          {
            adj[i]=newnode;
          }
          else
          {
            last->next=newnode;
          }
          last=newnode;
          }
        }
}
void displaygraph(struct node *adj[],int non)
{
  struct node *ptr;
  int i;
  for(i=0;i<non;i++)
  {
    ptr=adj[i];
    printf("\nThe neighbours of node %d are :",i);
    while(ptr!=NULL)
    {
      printf("\t%d",ptr->vertex);
      ptr=ptr->next;
    }
  }
}
void deletegraph(struct node *adj[],int non)
{
  int i;
  struct node *ptr,*temp;
  for(i=0;i<non;i++)
  {
    ptr=adj[i];
    while(ptr!=NULL)
    {
      temp=ptr;
      ptr=ptr->next;
      free(temp);
    }
    adj[i]=NULL;
  }
}
