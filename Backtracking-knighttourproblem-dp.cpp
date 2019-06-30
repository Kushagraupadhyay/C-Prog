//Knight tour problem 
#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
int n;
bool issafe(int x,int y,int **sol)
{
	if(x>=0 && y>=0  && x<n && y<n && sol[x][y]==-1)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void printsolution(int **sol)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf(" %2d ",sol[i][j]);
		}
		cout<<endl;
	}
}
int solvektuntil(int x,int y,int movei,int **sol,int *xmove,int *ymove)
{
	int i,nextx,nexty;
	if(movei==n*n)
	return true;

	for(i=0;i<8;i++)
	{
		nextx=x+xmove[i];
		nexty=y+ymove[i];
		if(issafe(nextx,nexty,sol))
		{
			sol[nextx][nexty]=movei;
			if(solvektuntil(nextx,nexty,movei+1,sol,xmove,ymove)==true)
			  return true;
			else
			   sol[nextx][nexty]=-1;
		}
	}
	return false;
}
bool solvekt(int **sol)
{
	int xmove[8]={2,1,-1,-2,-2,-1,1,2};
	int ymove[8]={1,2,2,1,-1,-2,-2,-1};

	sol[0][0]=0;
	if(solvektuntil(0,0,1,sol,xmove,ymove)==false)
	{
		printf("Solution does not exist");
		return false;
	}
	else
	    printsolution(sol);
	return true;
}
int main()
{
	 cin>>n;
	 int **sol=(int **)malloc(n*sizeof(int *));
	 for(int i=0;i<n;i++)
	  sol[i]=(int *)malloc(n*(sizeof(int)));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			sol[i][j]=-1;
		}
	}
		solvekt(sol);
	return 0;
}
