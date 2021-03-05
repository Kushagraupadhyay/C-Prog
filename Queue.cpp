##### Please tech me this program

#include<stdio.h>
#include<conio.h>
#define max 10

int a[max];
int front=-1,rear=-1;

 void insert(int);
 int deletee(void);
 void display(void);
 //int peek(int[a]);

 int main()
 {
   int i,n,val,x;
   printf("Enter the number of elements you want to enter in the queue\n");
   scanf("%d",&n);
   for(i=0;i<n;i++)
   {
     printf("Enter value:-");
     scanf("%d",&val);
     insert(val);
   }
   display();
   x=deletee();
   printf("\nDeleted element is  -%d\n",x);
   display();
   return 0;
 }


void insert(int val)
{
  if(rear==max-1)
  {
    printf("Queue Overflow");
  }
  else if(front==-1 && rear==-1)
  {
    front=rear=0;
    a[rear]=val;
  }
  else
  {
    rear++;
    a[rear]=val;
  }
}
void display()
{
  int i;
  if(front==-1||front>rear)
  {
    printf("Empty queue");
  }
  else
{

  for(i=front;i<=rear;i++)
  {
    // printf("front is at %d \n",front);
    // printf("The front element is %d\n",a[front]);
    printf("-%d-",a[i]);
  }
}
}
int deletee()
{
  int x;
  if(front==-1 || front>rear)
  {
    printf("\nEmpty queue");
    return -1;
  }
  else
  {
    x=a[front];
    //printf("front is at %d \n",front);
    //printf("The front element is %d\n",x);
    front=front+1;;
    //printf("The changed front is %d\n",front);
    if(front>rear)
    {
      front=rear=-1;
    }
    return x;
  }
}
