//sum of subsets
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
bool issubset(int a[],int n,int sum)
{
  if(sum==0)
  return true;
  if(n==0 && sum!=0)
  return false;
  if (a[n-1]>sum)
  return issubset(a,n-1,sum);
  return (issubset(a,n-1,sum)||issubset(a,n-1,sum-a[n-1]));
}
bool issubsetusingdynamicprogramming(int a[],int n,int sum)
{
  int i,j;
  bool subset[n+1][sum+1];
  for(i=0;i<=n;i++)
  subset[i][0]=true;
  for(i=1;i<=sum;i++)
  subset[0][i]=false;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=sum;j++)
    {
      if(j<a[i-1])
      subset[i][j]=subset[i-1][j];
      if(j>=a[i-1])
      subset[i][j]=subset[i-1][j]||subset[i-1][j-a[i-1]];
    }
  }
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= sum; j++)
       printf ("%4d", subset[i][j]);
    printf("\n");
  }
return subset[n][sum];
}
int main()
{
  int n,sum;
  printf("Enter the number of elements in the set\n");
  cin>>n;
  int *a=(int *)malloc(n*sizeof(int));
  printf("Enter elements\n");
  for(int i=0;i<n;i++)
  cin>>a[i];
  printf("Enter the value of sum\n");
  cin>>sum;
  // if(issubset(a,n,sum)==true)   // without using dynamic programming
  // cout<<"Yes";
  // else
  // cout<<"False";
  if(issubsetusingdynamicprogramming(a,n,sum)==true)
  cout<<"Yes";
  else
  cout<<"NO";

  return 0;
}
