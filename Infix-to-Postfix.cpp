//infix to postfix
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#define max 10
char s[max],st[max];
int top=-1;
void push(int s[],int);
char pop(int s[]);
void itop(char s[],char []);
int getpriority(char);
int evaluate(char [],char []);
int main()
{
  char infix[100],postfix[100],ans[100];
  printf("Enter the infix expression");
  gets(infix);
  strcpy(postfix,"");
  itop(infix,postfix);
  printf("The corresponding postfix expression is");
  puts(postfix);
  strcpy(ans,"");
  evaluate(postfix,ans);
  puts(ans);
  return 0;
}
void evaluate(char postfix[],char ans[])
{

}
void push(char s[],char val)
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
char pop(char s[])
{
  char x;
  if(top==-1)
  {
    printf("Stack underflow");
  }
  else
  {
    x=s[top];
    top--;
  }
  return x;
}
int getpriority(char op)
{
  if(op=='/' || op=='*' || op=='%')
  {
    return 1;
  }
  else if(op=='+' || op=='-')
  {
    return 0;
  }
}
void itop(char infix[],char postfix[])
{
  int i=0,j=0;
  char temp;
  strcpy(postfix,"");
  while(infix[i]!='\0')
  {
    if(infix[i]=='(')
    {
      push(s,infix[i]);
      i++;
    }
    else if(infix[i]==')')
    {
      while((top!=-1) && (s[top]!='('))
      {
        postfix[j]=pop(s);
        j++;
      }
      if(top==-1)
      {
        printf("Incorrrect expression");
      }
      temp=pop(s); //removal of bracket
      i++;
    }
    else if(isdigit(infix[i])||isalpha(infix[i]))
    {
      postfix[j]=infix[i];
      j++;
      i++;
    }
    else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' )
    {
      while((top!=-1)&&(top!='(')&&(getpriority(s[top])>=getpriority(infix[i])))
      {
        postfix[j]=pop(s);
        j++;
      }
      push(s,infix[i]);
      i++;
    }
    else
    {
      printf("\n Incorrect element in the expression");
      exit(1);
    }
  }
  while((top!=-1)&&(s[top]!='('))
  {
    postfix[j]=pop(s);
    j++;
  }
  postfix[j]='\0';
}
