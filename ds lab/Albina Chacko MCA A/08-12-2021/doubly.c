#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head;

void beginsert ();
void lastinsert ();
void randominsert();
void begin_delete();
void last_delete();
void random_delete();
void display();
void search();
void main ()
{
    int choice =0;
    while(choice != 9)
    {

        printf("\n MENU DRIVEN \n");
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random location\n4.Delete from Beginning\n5.Delete from last\n6.Delete node after specified location\n7.Search\n8.Display\n9.Exit\n");
        printf("\nEnter choice\n");
        printf("\n**************************************************************\n");
        scanf("\n%d",&choice);
        switch(choice)
        {
            case 1:
            beginsert();
            break;
            case 2:
            lastinsert();
            break;
            case 3:
            randominsert();
            break;
            case 4:
            begin_delete();
            break;
            case 5:
           last_delete();
            break;
            case 6:
           random_delete();
            break;
            case 7:
            search();
            break;
            case 8:
            display();
            break;
            case 9:
            exit(0);
            break;
            default:
            printf("Invalid..");
        }
        }
        }
void beginsert()
       {
    struct node *newnode;
    int value;
    newnode = (struct node *) malloc(sizeof(struct node *));

        printf("\nEnter value\n");
        scanf("%d",&value);
        newnode->data = value;
        newnode-> prev = NULL;
        if (head == NULL)
        {
        newnode->next=NULL;
        head=newnode;
        }
        else
        {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
        }
        printf("\n Inserted node");
        }


void lastinsert()
       {
     struct node *newnode,*temp;
   int value;
   newnode = (struct node *) malloc(sizeof(struct node));
       printf("\nEnter value");
       scanf("%d",&value);
        newnode->data=value;
       if(head == NULL)
       {
           newnode->next = NULL;
           newnode->prev = NULL;
           head = newnode;

       }
       else
       {
          temp = head;
          while(temp->next!=NULL)
          {
              temp = temp->next;
          }
          temp->next = newnode;
          newnode ->prev=temp;
          newnode->next = NULL;
          }
     printf("\nnode inserted\n");
    }


void randominsert()
{
     struct node *newnode,*temp;
       int value,key;
       newnode = (struct node *)malloc(sizeof(struct node));
       printf("\nEnter the node after to insert");
       scanf("%d",&key);
        printf("\nEnter value");
       scanf("%d",&value);
        newnode->data=value;
       if (head == NULL)
       {
   newnode -> prev = NULL;
    newnode -> next=NULL;
     head=newnode;
       }
       else
       {
        temp=head;
       while(temp->data!=key)
       {
           if(temp->next==NULL)
           {
             printf("Node not Found");
           }
        else
        {
         temp=temp->next;
        }
       }
         newnode->next = temp->next;
           newnode -> prev = temp;
           temp->next = newnode;
           temp->next->prev=newnode;
        }

       printf("\nnode inserted\n");
    }

void begin_delete()
       {
           struct node *newnode,*temp;
         if(head==NULL)
        {
            printf("List is Empty!!! Deletion is not possible");
        }else
        {
        temp=head;
        printf("the deleted element is %d\n",temp->data);
        if(temp->prev==NULL&&temp->next==NULL)
        {
            head=NULL;
            free(temp);
        }else
        {
            head=temp->next;
            head->prev=NULL;
            free(temp);
        }
        printf("delete sucessfully");
        }

}
void last_delete()
{
    struct node *temp;
    temp=head;
         if(temp==NULL)
        {
            printf("List is Empty!!! Deletion is not possible");
        }
        else if(temp->prev==NULL&&temp->next==NULL)
        {
            head=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
           printf("the deleted element is %d\n",temp->data);
           temp -> prev -> next = NULL;
            free(temp);

        }
        printf("delete succefully");
          }
void random_delete()
{
     struct node *ptr, *temp;
        int val;
        printf("\n Enter the node after to deleted : ");
        scanf("%d", &val);
        ptr = head;
        if(head==NULL)
        {
            printf("deletion is not possible");
        }
        while(ptr -> data != val)
        ptr = ptr -> next;
        if(ptr -> next == NULL)
        {
            printf("\nCan't delete\n");
        }
        else if(ptr -> next -> next == NULL)
        {
            ptr ->next = NULL;
        }
        else
        {
            temp = ptr -> next;
            ptr -> next = temp -> next;
            temp -> next -> prev = ptr;
            free(temp);
            printf("\nnode deleted\n");
        }
}
void search()
{
     struct node *temp;
        int item,i=0,flag;
        temp = head;
        if(temp == NULL)
        {
            printf("\nEmpty List\n");
        }
        else
        {
            printf("\nEnter item which you want to search?\n");
            scanf("%d",&item);
            while (temp!=NULL)
            {
                if(temp->data == item)
                {
                    printf("\nitem found at location %d ",i+1);
                    flag=0;
                    break;
                }
                else
                {
                    flag=1;
                }
                i++;
                temp = temp -> next;
            }
            if(flag==1)
            {
                printf("\nItem not found\n");
            }
        }

          }

void display()
{
    struct node *temp;
    temp = head;
    if(temp == NULL)
    {
        printf("empty");
    }
    else
    {
        printf("\n print values\n");
        printf("NULL-->");
        while (temp->next!=NULL)
        {
            printf("%d-->",temp->data);
            temp = temp -> next;
        }
        printf("%d-->NULL",temp->data);
    }

}



