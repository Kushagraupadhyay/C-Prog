//N-Queens problem
#include<iostream>
#include<conio.h>
#include<malloc.h>
#include<stdio.h>
using namespace std;
int n;
void printsolution(int **board)
{
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      printf("%d",board[i][j]);
    }
    cout<<endl;
  }
}
bool issafe(int **board,int row,int col)
{
  int i, j; /* Check this row on left side */
  for (i = 0; i < col; i++)
  {
    if (board[row][i])
    return false;
  }

  for (i = row, j = col; j >= 0 && i < n; i++, j--)
  {
    if (board[i][j])
      return false;
  }
  for (i = row, j = col; i >= 0 && j < n; i--, j++)
  {
    if (board[i][j])
      return false;
  }
  for (i = row, j = col; j <n && i < n; i++, j++)
  {
    if (board[i][j])
      return false;
  }
  for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
  {
    if (board[i][j])
      return false;
  }
return true;
}
bool solvenquntil(int **board,int col)
{
  if(col>=n)
  {
    printsolution(board);
    cout<<endl;
    return false;
  }

  for(int i=0;i<n;i++)
  {
    if(issafe(board,i,col))
    {
      board[i][col]=1;
      if(solvenquntil(board,col+1))
      return true;
      board[i][col]=0;
    }
  }
  return false;
}
bool solvenq(int **board)
{
  if(solvenquntil(board,0)==false)
  {
    //printf("Solution does not exist");
    return false;
  }
  else
  {
    printsolution(board);
    return true;
  }
}
int main()
{
  cin>>n;
  int **board=(int **)malloc(n*sizeof(int *));
  for(int i=0;i<n;i++)
    board[i]=(int *)malloc(n*sizeof(int));

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      board[i][j]=0;
    }
  }
  solvenq(board);
  return 0;
}
