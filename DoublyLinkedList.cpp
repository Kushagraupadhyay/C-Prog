#include<iostream>
#include<conio.h>
#include<malloc.h>
struct node{
  struct node *prev;
  int data;
  struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
struct node *insertbeg(struct node *);
int main()
{
  start=create(start);
  start=display(start);
  start=insertbeg(start);
  start=display(start);
}
struct node *create(struct node *start)
{
  struct node *newnode,*ptr;
  int num;
  printf("Enter data");
  scanf("%d",&num);
  while(num!=-1)
  {

    if(start==NULL)
    {
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=num;
      start=newnode;
      newnode->prev=NULL;
      newnode->next=NULL;
      // newnode->data=num;
    }
    else
    {
      ptr=start;
      newnode=(struct node *)malloc(sizeof(struct node));
      newnode->data=num;
      while(ptr->next!=NULL)
      {
        ptr=ptr->next;
      }
      ptr->next=newnode;
      newnode->prev=ptr;
      newnode->next=NULL;
      // newnode->data=num;

    }
    printf("Enter data:-");
    scanf("%d",&num);
  }
  return start;
}
struct node *display(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr!=NULL)
  {
    printf("-%d-",ptr->data);
    ptr=ptr->next;
  }
  //printf("--%d-",ptr->data);
  return start;
}
struct node *insertbeg(struct node *start)
{
  struct node *newnode,*ptr;
  int num;
  printf("\nEnter num:-");
  scanf("%d",&num);
  newnode=(struct node *)malloc(sizeof(struct node));
  newnode->data=num;
  start->prev=newnode;
  newnode->next=start;
  newnode->prev=NULL;
  start=newnode;
  return start;
}
