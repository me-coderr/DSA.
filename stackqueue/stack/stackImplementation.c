/*WAP to convert an infix expression to its corresponding postfix operation, paranthesis matching, push, pop, peep*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int top;
    int size;
    int* arr;
}stack;

int push(stack**);
int pop(stack**);
int peep(stack*);
int isFull(stack*);
int isEmpty(stack*);
void paranthesisMatch(stack**);

int main()
{
    int ch;
    stack* s=(stack*)malloc(sizeof(stack));
    printf("\nEnter the size of stack : ");
    scanf("%d", &s->size); 
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    printf("\n--- Stack has been created successfully. At present it's empty. ---\n");
    do
    {    
        printf("\nPick an operation you wish to perform on the stack.\n 1. Push an element to the top of stack.\n 2. Pop an element from the stack.\n 3. Display the element at the top of stack.\n Any other number to exit.\n");
        scanf("%d", &ch);
        switch(ch)
        {
            case 1 : 
                push(&s);
                break;

            case 2 :
                pop(&s);
                break;

            case 3 :
                peep(s);
                break;

            default :
                printf("\nYou entered an invalid option.\n");
        }
    }while(ch>0 && ch<4);
}



int push(stack** s)
{
    if(isFull(*s))
    {
        printf("\nThe stack is full. Pop some element(s) first in order to perform push operation.\n");
        return 0;
    }
    else
    {
        ++(*s)->top;
        printf("\nEnter the element to push in stack : ");
        scanf("%d", &(*s)->arr[(*s)->top]);
        printf("\nElement %d pushed to the top of stack.\n", (*s)->arr[(*s)->top]);
        return (*s)->arr[(*s)->top];
    }
}

int pop(stack** s)
{
    if(isEmpty(*s))
    {
        printf("\nThe stack is empty. Push some element(s) first in order to perform pop operation.\n");
    }
    else
    {
        --(*s)->top;
        printf("\nElement %d poped out of the stack.\n", (*s)->arr[(*s)->top + 1]);
        return (*s)->arr[(*s)->top + 1];
    }
}

int peep(stack* s)
{
    if(isEmpty(s))
    {
        printf("\nThe stack is empty.\n");
        return 0;
    }
    else
    { 
        int val=s->arr[s->top];
        printf("\nThe element at the top of stack : %d\n", val);
        return val;
    }
}

int isFull(stack* s)
{
    if(s->top == s->size-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(stack* s)
{
    if(s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}