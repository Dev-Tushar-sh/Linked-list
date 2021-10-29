#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node *createnode();
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

void main()
{
    int menu;
    while(1)
    {
        system("cls");
        printf("CHOICES\n");
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
printf("12->Count The list\n");
printf("13->Exit\n\n");

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
    case 12: count();
              break;
    case 13: exit(0);
    default:
        {
            printf("yarr choices tho dekh lo\nandho ki tarah kuch bhi likh denge hattt \nja phir se dekh k type krr");
            getch();
        }
}
}
}
struct node
{
   int data;
   struct node *n;
};
struct node *start=NULL;
struct node *createnode()
{
    struct node *n;
    n=(struct node *)malloc(sizeof(struct node));
    return(n);
};
void insertfront()
{
    struct node *temp;
    temp=createnode();
    temp->n=NULL;
    printf("Enter the Number");
    scanf("%d",&temp->data);
    temp->n=start;
    start=temp;
}

void insertmiddle()
{

    int m,pos;
    struct node *temp,*t;
    temp=createnode();
    printf("Enter the Position ");
    scanf("%d",&pos);
    printf("Enter the Number ");
    scanf("%d",&temp->data);
    t=start;
    if(start==NULL)
    {
        temp=start;
        temp->n=NULL;
    }
    else

            if(t==NULL)
            {
                printf("An error occured");
                return;
            }
           else
           {
               for(m=1;m<pos-1;m++)
           {
            t=t->n;
           }
              temp->n=t->n;
              t->n=temp;
           }
}
void insertend()
{
    struct node *temp,*t;
    temp=createnode();
    printf("Enter the Number ");
    scanf("%d",&temp->data);
    temp->n=NULL;
    if(start==NULL)
    {
        start=temp;
    }
else
    {
        t=start;
        while(t->n!=NULL)
        {
            t=t->n;
        }
        t->n=temp;
    }
}
void deletefront()
{
  struct node *temp;
  if(start==NULL)
  {
    printf("List is empty");
     getch();
  }
  else
  {
      temp=start;
      start=start->n;
      free(temp);
  }

}
void deletemiddle()
{
    int i,pos;
    struct node *temp,*t;
    printf("Enter the position");
    scanf("%d",&pos);
    if(start==NULL)
        printf("The list is Empty");
    else
        {
            temp=start;
            t=start;
            for(i=1;i<pos-1;i++)
            {
                temp=temp->n;
                t=t->n;
            }
            t=t->n;
            temp->n=t->n;
            free(t);

        }
}
void deleteend()
{
    struct node *t=start,*p=start;
        if(start==NULL)
        {
            printf("list is empty");
        }
        else if(start->n==NULL)
        {
            free(start);
            start==NULL;
        }
        else
        {
            while(t->n!=NULL)
            {
            p=t;
            t=t->n;
            }
              p->n=NULL;
              free(t);
        }
}
void showlist()
{
    struct node *temp;
    if(start==NULL)
      printf("List is empty");

      else
        {
            temp=start;
            while(temp!=NULL)
            {
                printf("%d ",temp->data);
                temp=temp->n;
            }
        }
        getch();
}
void sort()
{
    int temp;
    struct node *p,*t;
    t=start;
    while(t->n!=NULL)
    {
        p=t->n;
        while(p!=NULL)
        {
            if(t->data>p->data)
            {
                temp=t->data;
                t->data=p->data;
                p->data=temp;
            }
            p=p->n;
        }
        t=t->n;
    }
}
int searchinsort()
{
    int m=1,v;
    struct node *temp=start;
    printf("Enter the Number You want to search");
    scanf("%d",&v);
    while(temp!=NULL)
    {
        if(temp->data==v)
        {
            printf("Element Found\n");
            printf("Position is %d\n",m);
            showlist();
            return(0);
        }
        else
            {
                if(temp->data>v)
                {
                    printf("Search Element Not Found");
                    getch();
                    return(0);
                }
                else
                    {
                        temp=temp->n;

                    }

            }
    m++;
    }
}
int searchinunsort()
{
     int v,m=1;
    struct node *temp;
    temp=start;
    printf("Enter the Element You want to search");
    scanf("%d",&v);
    while(temp!=NULL)
    {

       if(temp->data==v)
       {

           printf("Search element found\n");
           printf("position is->%d\n",m);
           showlist();
           return(0);
       }
       else
       {
           temp=temp->n;
       }
       m++;
    }
}
void traverse()
{
    int v;
    struct node *temp;
    printf("Enter the number ");
    scanf("%d",&v);
    temp=start;
    if(start==NULL)
    {
        printf("List is Empty");
        getch();
    }
    else
    {
    while(temp!=NULL)
    {
        temp->data=temp->data+v;
        temp=temp->n;
    }
    printf("Now the list is->  ");
    showlist();
    }
}
void count()
{
    struct node *temp=start;
    int v=0;
   if(start==NULL)
   {
    printf("List is Empty");
    getch();
   }
   else
    {
        while(temp!=NULL)
        {
            v++;
            temp=temp->n;
        }
        printf("Total Number of Element %d",v);
        getch();
    }
}
