/*Mutliple paranthesis/brackets matching using stack.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int top;
    int size;
    char* arr;
}stack;

int push(stack**, char c);
int pop(stack**);
int peep(stack*);
int isFull(stack*);
int isEmpty(stack*);
int paranthesisMatch(stack**);

int main()
{
    stack* s=(stack*)malloc(sizeof(stack));
    paranthesisMatch(&s);
    return 0;
}

int paranthesisMatch(stack** s)
{
    int length=30, i;
    char* exp=(char*)malloc(sizeof(char)*length);
    (*s)->size=10;
    (*s)->top=-1;
    printf("\nEnter the expression where paranthesis needs to be matched.\nPlease Note : The expression must be less than %d characters.\n", length);
    fgets(exp, length, stdin);
    length=strlen(exp);
    (*s)->size=length;
    (*s)->arr=(char*)malloc((*s)->size*sizeof(char));
    for(i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
        {
            push(&(*s), exp[i]);
        }
        if(exp[i]==')'|| exp[i]=='}' || exp[i]==']')
        {
            int popped=pop(&(*s));
            if((popped=='(' && exp[i]==')') || (popped=='{' && exp[i]=='}') || (popped=='[' && exp[i]==']')){}
            else
            {
                printf("\nParanthesis on the entered expression do not match.");
                return 1; //failed
            }
        }
    }
    if(isEmpty(*s))
    {
        printf("\nParanthesis on the entered expression are properly matched.\n");
    }
    else
    {
        printf("\nParanthesis on the entered expression do not match. There are more opening brackets than there are closing brackets.\n");
    }
    return 0;
}

int push(stack** s, char ch)
{
    ++(*s)->top;
    (*s)->arr[(*s)->top]=ch;
}

int pop(stack** s)
{
    if(isEmpty(*s))
    {
        printf("\nParanthesis on the entered expression do not match. There are more closing brackets than there are opening brackets.\n");
        return 0;
    }
    else
    {
        --(*s)->top;
        return (*s)->arr[(*s)->top + 1];
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