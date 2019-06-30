//longest common subsequence
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
char a[100],b[100];
int arr[100][100];
int lcsusingrecursion(int i,int j) // can reduce time complexity using memoisation;
{
  if(a[i]=='\0' || b[j]=='\0')
  return 0;
  else if(a[i]==b[j])
  return (1+lcsusingrecursion(i+1,j+1));
  else
  return max(lcsusingrecursion(i+1,j),lcsusingrecursion(i,j+1));
}
int lcsusingdynamicprogrammingiteration(int m,int n)
{
  int i,j;
  for(i=0;i<=m;i++)
  {
    for(j=0;j<=n;j++)
    {
      if(i==0 || j==0)
      arr[i][j]= 0;
      else if(a[i-1]==b[j-1])
      arr[i][j]=1+arr[i-1][j-1];
      else
      arr[i][j]=max(arr[i][j-1],arr[i-1][j]);
    }
  }
 return arr[m][n];
}
void printsubsequence(int m,int n)
{
  int i,j,count=0;
  char ansarr[100];
  while(arr[m][n]!=0)
  {
    if(arr[m][n]==arr[m][n-1])
    {
      n--;
    }
    else
    {
      ansarr[count]=b[n-1];
      count++;
      m--;
      n--;
    }
  }
  cout<<"Subsequence is :-";
  for(i=count-1;i>=0;i--)
  {
    cout<<ansarr[i];
  }
}
int main()
{
    cin>>a;
    cin>>b;
    //int ans=lcsusingrecursion(0,0);
    //cout<<ans;
    int ans2=lcsusingdynamicprogrammingiteration(strlen(a),strlen(b));
    cout<<"Length of subsequence is :-"<<ans2<<endl;
    printsubsequence(strlen(a),strlen(b));
    return 0;
}
