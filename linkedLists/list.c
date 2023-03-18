/*Write a menu driven program to implement a singly linked list with the operations:
i)create the list ii)insert any element in any given position (front, end or intermediate)
iii)delete an element from any given position(front, end or intermediate) iv)display the list v)count the number of nodes*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}list;

list* head=NULL;

void createList();
void insertNode();
void deleteNode();
void displayList();
int countNodes();

int main()
{
    int i, ch=-1;
    printf("\nCreate a list first.\n");
    createList();
    printf("\nList creation successful.\n");
    do
    {
        printf("\nPick an operation you wish to perform.\n 1. Insertion of a node at an index 'i'.\n 2. Deletion of a node from an index 'i'.\n 3. Display the list at present.\n 4. Count the total number of nodes present in the list.\nAny other number to exit.\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 :
                insertNode();
                break;
            case 2 :
                deleteNode();
                break;
            case 3 :
                displayList();
                break;
            case 4 :
                printf("\nNumber of nodes present in the list : %d\n\n", countNodes());
                break;
        }
    } while (ch>=1 && ch<=4);
    printf("\n\nProgram terminated.\n\n");
}

void createList()
{
    int n, i;
    list* temp=head, *newnode;
    printf("\nHow many nodes to you want to initialise the list with?\n");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        newnode=(list*)malloc(sizeof(list));
        printf("\nEnter the value of %dth node : ", i+1);
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=newnode;
        }
        temp=head;
    }
}

void displayList()
{
    list* temp=head;
    if(head==NULL)
        printf("\nThe list is empty.\n");
    else
    {
        printf("\nYour list at present : \n");
        while(temp!=NULL)
        {
            printf(" %d ", temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void insertNode()
{
    list* temp=head, *newnode=(list*)malloc(sizeof(list));
    int idx, i;
    printf("\nEnter the position at which you want to add the new node : ");
    scanf("%d", &idx);
    --idx;
    if(idx<0 || idx > countNodes())
    {
        printf("\nYou entered an invalid position.\n Causes : Either the entered value is less than 1 or no node is present behind the entered position.\nEnter a valid positon the this time.\n");
        insertNode();
    }
    else
    {
        printf("\nNow enter the value of newnode : ");
        scanf("%d", &newnode->data);
        newnode->next=NULL;
        if(temp==NULL)
        {
            head=newnode;
        }
        else
        {
            if(idx==0)
            {
                newnode->next=head;;
                head=newnode;
            }
            else
            {
                for(i=0; i<idx-1; i++)
                {
                    temp=temp->next;
                }
                if(idx < countNodes())
                {
                    newnode->next=temp->next;
                }
                temp->next=newnode;
            }
        }
        printf("\nNode Data : %d added at position : %d\n\n", newnode->data, idx+1);
    }
}

void deleteNode()
{
    if(head==NULL)
    {
        printf("\nList Underflow.\n\n");
    }
    else
    {
        list* temp=head;
        int idx, i, deleted;
        printf("\nEnter the position at which you want to delete a node : ");
        scanf("%d", &idx);
        if(--idx<0 || idx>countNodes()-1)
        {
            printf("\nYou entered an invalid position.\n Causes : Either the entered value is less than 1 or no node is present at the entered position.\nEnter a valid positon this time.\n");
            deleteNode();
        }
        else
        {
            if(idx==0)
            {
                
                deleted=temp->data;
                head=head->next;
            }
            else
            {
                for(i=0; i<idx-1; i++)
                {
                    temp=temp->next;
                }
                deleted=temp->next->data;
                if(idx==countNodes()-1)
                {
                    temp->next=NULL;
                }
                else
                {
                    temp->next=temp->next->next;
                }
            }
            printf("\nNode Data : %d deleted from position : %d\n", deleted, idx+1);
        }
    }
}

int countNodes()
{
    list* temp=head;
    int count=0;
    while(temp!=NULL)
    {
        ++count;
        temp=temp->next;
    }
    return count;
}