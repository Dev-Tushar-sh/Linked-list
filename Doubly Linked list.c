#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *m;
    struct node *n;
};
typedef struct node node;
node *start=NULL;
node* create_node()
{
    node *p;
    p=(node *)malloc(sizeof(node));
    return(p);
}
node *create_node();
void insertfront();
void insertmiddle();
void insertend();
void count();
void traverse();
int searchinunsort();
int searchinsort();
void sort();
void showlist();
void deleteend();
void deletemiddle();
void deletefront();
void reverselist();
void main()
{
    while(1)
    {
        system("cls");
    int menu;
    printf("This is a Doubly Linked list Program\n");
    printf("Choices\n");
    printf(" 1->Insert node at front\n");
    printf(" 2->Insert node in middle\n");
    printf(" 3->Insert node at end\n");
    printf(" 4->Delete node at Front\n");
    printf(" 5->Delete at middle\n");
    printf(" 6->Delete the end\n");
    printf(" 7->Show the list\n");
    printf(" 8->Sort The list\n");
    printf(" 9->Search in sorted list\n");
    printf("10->Search in unsorted list\n");
    printf("11->Traverse The list\n");
    printf("12->Reverse List\n");
    printf("13->Count The list\n");
    printf("14->Exit\n\n");

    printf("Enter your Choice-> ");
    scanf("%d",&menu);
switch(menu)
{
    case 1: insertfront();
             break;
    case 2: insertmiddle();
             break;
    case 3: insertend();
             break;
    case 4: deletefront();
             break;
    case 5: deletemiddle();
             break;
    case 6: deleteend();
             break;
    case 7: showlist();
             break;
    case 8: sort();
              break;
    case 9: searchinsort();
              break;
    case 10: searchinunsort();
              break;
    case 11: traverse();
              break;
    case 12: reverselist();
              break;
    case 13: count();
              break;
    case 14: exit(0);
    default:
        {
            printf("Phichle program me smjaya tha andhe mtt bano \noption dekh k dallo prr nahi ham tho andhe he hai\n ja phir se dekh k option bhar");
            getch();
        }
}
    }
}
void insertfront()
{
    node *temp;
    if(start==NULL)
    {
    temp=create_node();
    printf("Enter the value:");
    scanf("%d",&temp->data);
    start=temp;
    temp->n=NULL;
    temp->m=NULL;
    }
    else
    {
       temp=create_node();
       printf("Enter the value:");
       scanf("%d",&temp->data);

       temp->n=start;
       start->m=temp;
       start=temp;
    }
    showlist();
}
void insertend()
{
    node *temp,*t;
    temp=create_node();
    printf("Enter the number: ");
    scanf("%d",&temp->data);
      temp->n=NULL;
   if(start==NULL)
   {
     start=temp;
   }
   else
    {
        t=start;//hum chate hai t me start assign ho na ki
        while(t->n!=NULL)// start me t kyoki t tho default garbage haina
        {
            t=t->n;
        }
        t->n=temp;
        temp->m=t;
        }
    showlist();
}
void insertmiddle()
{
    if(start==NULL)
        printf("List is Empty");
    else
    {
        int i,b,o=1;
        node *temp=create_node();
        printf("Enter the element you want to insert- ");
        scanf("%d",&temp->data);
        printf("Enter the position - ");
        scanf("%d",&b);


        node *y=start,*u;
        while(o<=b)
        {
            if(o==b)
            {
                u=y;
                u=y->m;
                u->n=temp;
                y->m=temp;
                temp->n=y;
                temp->m=u;
                printf("Element added");
                showlist();
                break;//loop ki wajah se loop kabhi null nahi hoga abb;

            }
            else
            {
              y=y->n;
              o++;
            }

       }
    }
}
void count()
{
    int i=0;
    if(start==NULL)
        printf("The List is Empty");
    else
    {
        node *temp;
        temp=start;
        while(temp!=NULL)
        {
            i++;
            temp=temp->n;
        }
    printf("Total number of element in list are %d",i);

    }
    getch();
}
void traverse()
{
    int b;
    if(start==NULL)
        printf("List is Empty");
    else
    {
        node *temp;
        temp=start;
        printf("Enter the value to add or subtract:\n");
        scanf("%d",&b);
      while(temp!=NULL)
      {
          temp->data=temp->data+b;
          temp=temp->n;
      }

    }
    showlist();

}
int searchinunsort()
{
    int b,i=0,j=0;
    node *temp;
  if(start==NULL)
    printf("The list is Empty");
  else
   {
       printf("Enter the element you want to search- ");
       scanf("%d",&b);
       temp=start;
       while(temp!=NULL)
       {
           i++;
           if(temp->data==b)
            {
                j++;
              printf("Element Found!!-%d\nposition is %d\n",temp->data,i);
              showlist();
               getch();
               break;
            }
           else
            {
              temp=temp->n;
            }
        }
        if(j==0)
        {
          printf("Element not found!!!");
          getch();
        }
    }
}
int searchinsort()
{
    int b,i=0;
    node *temp;
  if(start==NULL)
    printf("The list is empty");
  else
  {
      printf("Enter the element you want to search- ");
      scanf("%d",&b);
      temp=start;

      while(temp!=NULL)
      {  i++;
          if(temp->data>b)
          {
              printf("Element not found!!");

              break;
          }
          else
          {
              if(temp->data==b)
              {
                  printf("Element found!!!- %d\nPosition is - %d\n",temp->data,i);
                  break;
              }
              else
                {
                    temp=temp->n;
                }

          }
        }
  }
  getch();
}
void sort()
{
  if(start==NULL)
  printf("List is empty");
  else
  {
      node *temp,*t;
      temp=start;
      t=start;
      int tp;
      printf("Sorting the list....");//using selection sort
       while(temp!=NULL)
       {
           t=temp;
       while(t!=NULL)
       {
           if(temp->data>t->data)
           {//swapping

             tp=t->data;
             t->data=temp->data;
             temp->data=tp;
           }
           t=t->n;
       }
       temp=temp->n;
       }
       showlist();
  }
}
void showlist()
{
    if(start==NULL)
    {
        printf("List is Empty");
        getch();
    }
    else
    {
        node *temp;
        temp=start;
        while(temp!=NULL)
        {
          printf(" %d",temp->data);
          temp=temp->n;
        }
         getch();
    }
}
void deleteend()
{
  if(start==NULL)
  {
     printf("List is Empty");
     getch();
  }
  else
  {
     node *temp,*t;
     temp=start;
     while(temp->n!=NULL)
        temp=temp->n;
        t=temp;
        temp=temp->m;
        temp->n=NULL;
        free(t);
        printf("element deleted");
        getch();
  }
}
void deletemiddle()
{
    int i,b=0;
    if(start==NULL)
        printf("List is Empty");
    else
    {
        printf("Enter the element\nyou want to delete - ");
        scanf("%d",&i);
        node *temp=start;
        node *t=temp;
        node *o=temp;
        while(temp!=NULL)
        {
            if(temp->data==i)
            {
                b++;
                t=temp->m;
                o=temp->n;
                t->n=o;
                o->m=t;
                temp->m=NULL;
                free(temp);
                break;
            }
            else
            {
                temp=temp->n;
            }
        }
        if(b==0)
            printf("Element not found!!!");
            showlist();

    }
}
void deletefront()
{
    if(start==NULL)
    {
        printf("List is Empty");
        getch();
    }
    else
    {
        node *temp;
        temp=start;
        start=temp->n;
        free(temp);
    }

}
void reverselist()
{
  if(start==NULL)
  {
      printf("List is Empty");
  }
  else
  {
      node *temp;
      temp=start;
      while(temp->n!=NULL)
        temp=temp->n;

      while(temp!=start)
      {
          printf(" %d ",temp->data);
          temp=temp->m;
      }
      printf(" %d ",temp->data);
   getch();
  }
}
