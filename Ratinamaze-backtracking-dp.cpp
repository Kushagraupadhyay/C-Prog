// Rat in a maze using dp and backtracking
#include<stdio.h>
#include<malloc.h>
#include<iostream>
using namespace std;
int n;
void printSolution(int **sol)
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}
bool isSafe(int **a, int x, int y)
{
	if (x >= 0 && x < n && y >= 0 && y < n && a[x][y] == 1)
		return true;

	return false;
}
bool solveMazeUtil(int **a, int x, int y, int **sol)
{
	if (x == n - 1 && y == n - 1) {
		sol[x][y] = 1;
    printSolution(sol);
		cout<<endl;
    sol[x][y]=0;
		return false;
	}
	if (isSafe(a, x, y) == true) {
		sol[x][y] = 1;

		if (solveMazeUtil(a, x + 1, y, sol) == true)
			return true;

		if (solveMazeUtil(a, x, y + 1, sol) == true)
			return true;

		sol[x][y] = 0;
		return false;
	}
	return false;
}
bool solveMaze(int **a,int **sol)
{

	if (solveMazeUtil(a, 0, 0, sol) == false) {
		return false;
	}

	printSolution(sol);
	return true;
}
int main()
{
  int i,j;
  printf("Enter the size of the matrix\n");
  scanf("%d",&n);
  int **a=(int **)malloc(n*sizeof(int *));
  for(i=0;i<n;i++)
   a[i]=(int *)malloc(n*sizeof(int));

  printf("Enter the values of the matrix\n");
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      scanf("%d",&a[i][j]);
    }
  }
  int **sol=(int **)malloc(n*sizeof(int *));
  for(i=0;i<n;i++)
   sol[i]=(int *)malloc(n*sizeof(int));

  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      sol[i][j]=0;
    }
  }
  solveMaze(a,sol);

  return 0;
}
