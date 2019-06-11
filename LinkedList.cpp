//linked list
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<bits/stdc++.h>
struct node
{
  int data;
  struct node *next;
};
struct node *start=NULL;
struct node *create(struct node *);
struct node *display(struct node *);
// struct node *insertatbeg(struct node *);
// struct node *insertatend(struct node *);
// struct node *insertafter(struct node *);
// struct node *insertbefore(struct node *);
// struct node *sortlist(struct node *);
int main()
{
  start=create(start);
  start=display(start);
  // start=insertatbeg(start);
  // printf("\n");
  //   start=display(start);
  // start=insertatend(start);
  // printf("\n");
  //   start=display(start);
  // start=insertafter(start);
  // printf("\n");
  //   start=display(start);
  // start=insertbefore(start);
  // printf("\n");
  //   start=display(start);
  // start=sortlist(start);
  // printf("\n");
  //   start=display(start);
}
struct node *create(struct node *start)
{
  printf("Enter -1 to exit else enter values");
  struct node *newnode,*ptr;
  int num;
  printf("Enter data:-");
  scanf("%d",&num);
  while(num != -1)
  {
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    if(start==NULL)
    {
      newnode->next=NULL;
      start=newnode;
    }
    else
    {
      ptr=start;
      while(ptr->next != NULL)
      {
        ptr=ptr->next;
      }
      ptr->next=newnode;
      newnode->next=NULL;
    }
    printf("Enter the data:-");
    scanf("%d",&num);
  }
  return start;
}
struct node *display(struct node *start)
{
  struct node *ptr;
  ptr=start;
  while(ptr != NULL)
  {
    printf("-%d-",ptr->data);
    ptr=ptr->next;
  }

  return start;
}
struct node *insertatbeg(struct node *start)
{
  struct node *newnode;
  int num;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("insert at beginning \n Enter data:-");
  scanf("%d",&num);
  newnode->data=num;
  newnode->next=start;
  start=newnode;
  return start;
}
struct node *insertatend(struct node *start)
{
  struct node *ptr,*newnode;
  int num;
  newnode=(struct node*)malloc(sizeof(struct node));
  printf("Insert at end \n Enter data");
  scanf("%d",&num);
  newnode->next=NULL;
  newnode->data=num;
  ptr=start;
  while(ptr->next!=NULL)
  {
    ptr=ptr->next;
  }
  ptr->next=newnode;

  return start;
}
struct node *insertafter(struct node *start)
{
  struct node *ptr,*preptr,*newnode;
  int num,val;
  ptr=start;
  preptr=ptr;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter value for after insert");
  scanf("%d",&val);
  printf("\nEnter value tobe inserted");
  scanf("%d",&num);
  newnode->data=num;
  while(preptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=newnode;
  newnode->next=ptr;
  return start;
}
struct node *insertbefore(struct node *start)
{
  struct node *ptr,*preptr,*newnode;
  int num,val;
  ptr=start;
  preptr=ptr;
  newnode=(struct node *)malloc(sizeof(struct node));
  printf("Enter value for after insert");
  scanf("%d",&val);
  printf("\nEnter value tobe inserted");
  scanf("%d",&num);
  newnode->data=num;
  while(ptr->data!=val)
  {
    preptr=ptr;
    ptr=ptr->next;
  }
  preptr->next=newnode;
  newnode->next=ptr;
  return start;
}
struct node *sortlist(struct node *start)
{
  struct node *ptr1,*ptr2;
  int temp;
  ptr1=start;
  while(ptr1->next!=NULL)
  {
    ptr2=ptr1->next;
    while(ptr2->next!=NULL)
    {
      if(ptr1->data>ptr2->data)
      {
        temp=ptr1->data;
        ptr1->data=ptr2->data;
        ptr2->data=temp;
      }
      ptr2=ptr2->next;
    }
    ptr1=ptr1->next;
  }
  return start;
}
