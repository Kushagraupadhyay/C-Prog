#include<iostream>
#include<bits/stdc++.h>
#define max 10
int adj[max][max],n,tree[max][max];
void readmatrix(void);
int spanningtree(int);
void display(int);
int main()
{
  int source,treecost;
  readmatrix();
  printf("\nEnter the source :-");
  scanf("%d",&source);
  treecost=spanningtree(source);
  display(treecost);
  return 0;
}
int spanningtree(int src)
{
  int visited[max],parent[max],d[max];
  int i,j,k,min,u,v,cost;
  for(i=0;i<=n;i++)
  {
    visited[i]=0;
    d[i]=adj[src][i];
    parent[i]=src;
  }
  visited[src]=1;
  cost=0;
  k=1;
  for(i=0;i<=n;i++)
  {
    min=99999;
    for(j=1;j<=n;j++)
    {
      if(visited[j]==0 && d[j]<min)
      {
        min=d[j];
        u=j;
        cost+=d[u];
      }
    }
    visited[u]=1;
    //cost=cost+d[u]
    tree[k][1]=parent[u];
    for(v=1;v<=n;v++)
    {
      if(visited[v]==0 && (adj[u][v]<d[v]))
      {
        d[v]=adj[u][v];
        parent[v]=u;
      }
    }
  }
   return cost;
}
void display(int cost)
{
  int i;
  printf("\n The edge of the minimum spanning tree are :");
  for(i=1;i<=n;i++)
  {
    printf(" %d %d ",tree[i][1],tree[i][2]);
  }
  printf("\n The total cost of the minimum spanning tree is : %d",cost);
}
void readmatrix()
{
  int i,j;
  printf("\nEnter the number of vertices :");
  scanf("%d",&n);
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=n;j++)
    {
      scanf("%d",&adj[i][j]);
    }
  }
}
