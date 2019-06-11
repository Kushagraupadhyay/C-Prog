//Implementing differennt sorting algorithms
#include<iostream>
#include<stdio.h>
#include<bits/stdc++.h>
#define size 10
int n;
int arr[size];
void bubblesort(void);
void insertionsort(void);
void selectionsort(void);
void mergesort(int arr[],int,int);
void merge(int arr[],int,int,int);
void quicksort(int a[],int,int);
int partition(int a[],int,int);
void radixsort(void);
int largest(void);
void shellsort(void);
int main()
{

  int i;
  printf("\nEnter the size of the array list");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&arr[i]);
  }
  //bubblesort();
  //insertionsort();
  //selectionsort();
  //mergesort(arr,0,n-1);
  //quicksort(arr,0,n-1);
  shellsort();
  for(i=0;i<n;i++)
  {
    printf("%3d",arr[i]);
  }
  return 0;
}
void shellsort()
{
  int i,j,gapsize,temp,flag=1;
  gapsize=n;
  while(flag==1||gapsize>1)
  {
    flag=0;
    gapsize=(gapsize+1)/2;
    for(i=0;i<(n-gapsize);i++)
    {
      if(arr[i+gapsize]<arr[i])
      {
        temp=arr[i+gapsize];
        arr[i+gapsize]=arr[i];
        arr[i]=temp;
        flag=0;
      }
    }
  }
}
void radixsort()
{
  int bucket[size][size],bucketcount[size];
  int i,j,k,remainder,large,pass,nop=0,divisor=1;
  large=largest();
  while(large>0)
  {
    nop++;
    large/=10;

  }
  for(pass=0;pass<nop;pass++)
  {
    for(i=0;i<size;i++)
    bucketcount[i]=0;
    for(i=0;i<n;i++)
    {
      remainder=(arr[i]/divisor)%10;
      bucket[remainder][bucketcount[remainder]]=arr[i];
      bucketcount[remainder]++;
    }
    i=0;
    for(k=0;k<10;k++)
    {
      for(j=0;j<bucketcount[k];j++)
      {
        arr[i]=bucket[k][j];
        i++;
      }
    }
    divisor*=10;
  }
}
int largest()
{
  int large=arr[0],i;
  for(i=1;i<n;i++)
  {
    if(arr[i]>large)
    {
      large=arr[i];
    }
  }
  return large;
}
int partition(int a[],int beg,int end)
{
  int left,right,temp,loc,flag;
  loc=left=beg;
  right=end;
  flag=0;
  while(flag!=1)
  {
    while((a[loc]<=a[right])&&(loc!=right))
    {
    right--;
    }
    if(loc==right)
    {
    flag=1;
    }
    else if(a[loc]>a[right])
    {
      temp=a[loc];
      a[loc]=a[right];
      a[right]=temp;
      loc=right;
    }
    if(flag!=1)
    {
      while((a[left]>=a[loc])&&(left!=loc))
      {
      left++;
      }
      if(left==loc)
      {
      flag=1;
      }
      else if(a[loc]<a[left])
      {
        temp=a[loc];
        a[loc]=a[left];
        a[left]=temp;
        loc=left;
      }
    }
  }
  return loc;
}
void quicksort(int a[],int beg,int end)
{
  int loc;
  if(beg<end)
  {
    loc=partition(a,beg,end);
    quicksort(a,beg,loc-1);
    quicksort(a,loc+1,end);
  }
}
void merge(int arr[],int beg,int mid,int end)
{
  int i=beg,j=mid+1,index=beg,temp[size],k;
  while((i<=mid)&&(j<=end))
  {
    if(arr[i]<arr[j])
    {
      temp[index]=arr[i];
      i++;
    }
    else
    {
      temp[index]=arr[j];
      j++;
    }
    index++;
  }
  if(i>mid)
  {
    while(j<=end)
    {
      temp[index]=arr[j];
      j++;
      index++;
    }
  }
  else
  {
    while(i<=mid)
    {
      temp[index]=arr[i];
      i++;
      index++;
    }
  }
  for(k=beg;k<index;k++)
  {
    arr[k]=temp[k];
  }
}
void mergesort(int arr[],int beg,int end)
{
  int mid;
  if(beg<end)
  {
    mid=(beg+end)/2;
    mergesort(arr,beg,mid);
    mergesort(arr,mid+1,end);
    merge(arr,beg,mid,end);
  }
}
void selectionsort()
{
  int small,i,j,pos,temp,flag;
 for(i=0;i<=n-2;i++)
 {
   flag=0;
   small=arr[i];
   for(j=i+1;j<n;j++)
   {
     if(arr[j]<small)
     {
       small=arr[j];
       pos=j;
       flag=1;
     }
   }
   if(flag==1)
  {
   temp=arr[i];
   arr[i]=arr[pos];
   arr[pos]=temp;
 }
 }
}
void insertionsort()
{
  int i,j,temp;
  for(i=1;i<n;i++)
  {
    temp=arr[i];
    j=i-1;
    while((arr[j]>temp) && (j>=0))
    {
      arr[j+1]=arr[j];
      j--;
    }
    arr[j+1]=temp;
  }
}
void bubblesort()
{
  int i,j,temp;
  for(i=0;i<n;i++)
  {
    for(j=0;j<n-1-i;j++)
    {
      if(arr[j+1]<arr[j])
      {
        temp=arr[j];
        arr[j]=arr[j+1];
        arr[j+1]=temp;
      }
    }
  }
}
