//Sudoku
#include<iostream> 
#include<stdio.h>
#include<conio.h>
#include<bits/stdc++.h>
using namespace std;
int N;
void printgrid(int **grid)
{
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      cout<<grid[i][j]<<" ";
    }
    cout<<endl;
  }
}
bool findunassignedlocation(int **grid,int &row,int &col)
{
  for(row=0;row<N;row++)
  {
    for(col=0;col<N;col++)
    {
      if(grid[row][col]==0)
      {
        return true;
      }
    }
  }
  return false;
}
bool usedinrow(int **grid,int row,int num)
{
  for(int i=0;i<N;i++)
  {
    if(grid[row][i]==num)
    return true;
  }
  return false;
}
bool usedincol(int **grid,int col,int num)
{
   for(int i=0;i<N;i++)
   {
     if(grid[i][col]==num)
     return true;
   }
   return false;
}
bool usedinbox(int **grid,int boxstartrow,int boxstartcol,int num)
{
  for(int i=0;i<3;i++)
  {
    for(int j=0;j<3;j++)
    {
      if(grid[boxstartrow+i][boxstartcol+j]==num)
      return true;
    }
  }
  return false;
}
bool issafe(int **grid,int row,int col,int num)
{
  return !usedinrow(grid,row,num)&&!usedincol(grid,col,num)&&!usedinbox(grid,row-row%3,col-col%3,num)&&grid[row][col]==0;
}
bool solvesudoku(int **grid)
{
  int row,col;
  if(!findunassignedlocation(grid,row,col))
  return true;
  for(int i=1;i<=9;i++)
  {
    if(issafe(grid,row,col,i))
    {
      grid[row][col]=i;
      if(solvesudoku(grid))
      return true;
      grid[row][col]=0;
    }
  }
 return false;
}
int main()
{
  cin>>N;
  int **grid=new int*[N];
  for(int i=0;i<N;i++)
    grid[i]=new int[N];
  printf("Enter the value of sudoku");
  for(int i=0;i<N;i++)
  {
    for(int j=0;j<N;j++)
    {
      cin>>grid[i][j];
    }
  }
  if(solvesudoku(grid)==true)
     printgrid(grid);
  else
  cout<<"No solution exists";
  return 0;
}
