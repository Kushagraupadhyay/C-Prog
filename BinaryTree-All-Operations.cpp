// binary tree with all operations
#include<iostream>
#include<stdio.h>
#include<malloc.h>
#include<conio.h>
struct node{
  int data;
  struct node *left;
  struct node *right;
};
struct node *tree=NULL,*start;
struct node *insert_elements(int);
void preordert(struct node *);
void inorder(struct node *);
void postorder(struct node *);
int smallestelement(struct node *);
int largestelemet(struct node *);
int totalnodes(struct node *tree);
int tin(struct node *tree);
int ten(struct node *tree);
int height(struct node *tree);
struct node *delete_element(struct node *,int val);
int main()
{
  int i,n,val,x;
  printf("Enter the number of values that you want to insert");
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
    printf("\n Enter value %d :-",i+1);
    scanf("%d",&val);
    insert_elements(val);
  }
  if(tree==NULL)
  {
    printf("Null tree");
  }

  printf("\npreorder:-");
  preordert(tree);
  printf("\n Inorder :-");
  inorder(tree);
  printf("\n postorder :-");
  postorder(tree);
  x=smallestelement(tree);
  printf("\n The smallest elemsnt is %d ",x);
  x=largestelemet(tree);
  printf("\n The largest element is %d\n",x);
  printf("Enter the value of element to be deleted");
  scanf("%d",&val);
  delete_element(tree,val);
  printf("\npreorder:-");
  preordert(tree);
  printf("\n Inorder :-");
  inorder(tree);
  printf("\n postorder :-");
  postorder(tree);
  x=totalnodes(tree);
  printf("\nThe total nodes are %d",x);
  x=tin(tree);
  printf("\n Total number of iternal nodes are %d",x);
  x=ten(tree);
  printf("\n Total number of external nodes are %d",x);
  x=height(tree);
  printf("\n Height of the tree is %d",x);
  return 0;
}
int height(struct node *tree)
{
  int lh,rh;
  if(tree==NULL)
  {
    return 0;
  }
  else
  {
    lh=height(tree->left);
    rh=height(tree->right);
    if(lh>rh)
    {
      return (lh+1);
    }
    else
    {
      return (rh+1);
    }
  }
}
int tin(struct node *tree)
{
  if(tree==NULL || tree->left==NULL && tree->right==NULL)
  {
    return 0;
  }
  else
  {
    return (tin(tree->left)+tin(tree->right)+1);
  }
}
int ten(struct node *tree)
{
  if(tree==NULL)
  {
    return 0;
  }
  else if(tree->left==NULL && tree->right==NULL)
  return 1;
  else
  return (ten(tree->left)+ten(tree->right));
}
int totalnodes(struct node *tree)
{
  if(tree==NULL)
  {
    return 0;
  }
  else
  {
    return (totalnodes(tree->left)+totalnodes(tree->right)+1);
  }
}
struct node *delete_element(struct node *tree,int val)
{
  struct node *parent,*cur;
  if(tree==NULL)
  {
    printf("Tree is empty");
    return tree;
  }
  else
  {
  parent=tree;
  cur=tree;
  while(cur->data!=val && cur!=NULL)
  {

    if(val<cur->data)
    {
      parent=cur;
     cur=cur->left;
    }
     else
    {
      parent=cur;
     cur=cur->right;
    }
    if(cur==NULL)
    break;
  }
  if(cur==NULL)
  {
    printf("\n The value which is to be deleted is not present in the tree");
    return tree;
  }
  else
  {
  if(cur->left==NULL && cur->right==NULL)
  {
    if(parent->left==cur)
    {
      parent->left=NULL;
    }
    else
    {
      parent->right=NULL;
    }
    return tree;
  }
  else if(cur->left==NULL && cur->right!=NULL)
  {
    if(parent->left==cur)
    {
      parent->left=cur->right;
      return tree;
    }
    else
    {
      parent->right=cur->right;
      return tree;
    }
  }
  else if(cur->left!=NULL && cur->right==NULL)
  {
    if(parent->left==cur)
    {
      parent->left=cur->left;
      return tree;
    }
    else
    {
      parent->right=cur->left;
      return tree;
    }
  }
  else if(cur->left!=NULL && cur->right!=NULL)
  {
    struct node *suc,*sucp;
    int y,flag;
    suc=cur;
    sucp=cur;
    suc=suc->left;
    flag=0;
    while(suc->right!=NULL)
    {
      flag=1;
      sucp=suc;
      suc=suc->right;
    }
    y=suc->data;
    printf("The data that should be replacesd is %d",y);
    if(flag==0)
    sucp->left=NULL;
    else
    sucp->right=NULL;

    cur->data=y;
    return tree;

  }
 }
}
}
struct node *insert_elements(int val)
{
  struct node *ptr,*nodeptr,*parentptr;
  ptr=(struct node *)malloc(sizeof(struct node));
  ptr->data=val;
  ptr->left=NULL;
  ptr->right=NULL;
  if(tree==NULL)
  {
    tree=ptr;
    tree->left=NULL;
    tree->right=NULL;
  }
  else
  {
    parentptr=NULL;
    nodeptr=tree;
    while(nodeptr!=NULL)
    {
      parentptr=nodeptr;
      if(val<nodeptr->data)
      {
        nodeptr=nodeptr->left;
      }
      else
      {
        nodeptr=nodeptr->right;
      }
    }
    if(val<parentptr->data)
    {
      parentptr->left=ptr;
    }
    else
    {
      parentptr->right=ptr;
    }
  }
  printf("Insertion done");
  return tree;
}
void preordert(struct node *tree)
{
  if(tree!=NULL)
  {
    printf("-%d-",tree->data);
    preordert(tree->left);
    preordert(tree->right);
  }
}
void inorder(struct node *tree)
{
  if(tree!=NULL)
  {
    inorder(tree->left);
    printf("-%d-",tree->data);
    inorder(tree->right);
  }
}
void postorder(struct node *tree)
{
  if(tree!=NULL)
  {
    postorder(tree->left);
    postorder(tree->right);
    printf("-%d-",tree->data);
  }
}
int smallestelement(struct node *tree)
{
  int x;
  if(tree==NULL)
  {
    return 0;
  }
  start=tree;
  while(start->left!=NULL)
  {
    start=start->left;
  }
  x=start->data;
  return x;
}
int largestelemet(struct node *tree)
{
  int x;
  if(tree==NULL)
  {
    return 0;
  }
  start=tree;
  while(start->right!=NULL)
  {
    start=start->right;
  }
  x=start->data;
  return x;
}
