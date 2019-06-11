//array implementation of stack
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define max 10

int s[max],top=-1;
void push(int s[],int val);
int pop(int s[]);
int peek(int s[]);
void display(int s[]);

int main()
{
  int n,i,val,y;
  printf("Enter the number of values to enter in the stack\n");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    scanf("%d",&val);
    push(s,val);
  }
  display(s);
  y=pop(s);
  printf("\n");
  printf("popvalue=%d",y);
  printf("\n");
  display(s);
  y=peek(s);
  printf("\npeekvalue %d\n",y);
  display(s);
  return 0;
}
void push(int st[],int val)
{
  if(top==max-1)
  {
    printf("Stack Overflow");
  }
  else
  {
    top++;
    s[top]=val;
  }
}
void display(int a[])
{
  int i;
  if(top==-1)
  {
    printf("Stack is empty");
  }
  else
  {
    for(i=top;i>=0;i--)
    {
      printf("-%d",s[i]);
    }
  }
}
int pop(int s[])
{
  int x;
  if(top==-1)
  {
    printf("Stack Underflow");
  }
  else
  {
    x=s[top];
    top--;
    return x;
  }
}

int peek(int s[])
{
  int z;
  if(top==-1)
  {
    printf("Empty Stack");
  }
  else
  {
    z=s[top];
    return z;
  }
}
