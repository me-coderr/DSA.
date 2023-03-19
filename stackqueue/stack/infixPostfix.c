/*Infix to postfix using link list stack.

(a+c-c)/(d*e+f) -> ac+c-de*f+/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack
{
    struct stack* next;
    char data;
    int precedence;
}node;

node* topStack=NULL;

void push(char);
char pop();
int precedenceOF(char);
int isOperator(char);
int isBracket(char);

int main()
{
    int size=100, i, j=0, countBrackets=0;;
    char* inf_exp=(char*)malloc(size*sizeof(char)), *postf_exp;
    printf("\nEnter the infix expression to be converted into postfix.\n");
    fgets(inf_exp, size, stdin);
    size=strlen(inf_exp);
    postf_exp=(char*)malloc(size*sizeof(char));
    for(i=0; i<size-1; i++)
    {
        
    printf("\n--\n");
        if(isBracket(inf_exp[i])!=0)
        {
            
    printf("\n-bracket-\n");
            ++countBrackets;
            if(isBracket(inf_exp[i])==1)
            {
                push(inf_exp[i]);
            }
            else
            {
                while(isBracket(topStack->data)!=1)
                {
                    postf_exp[j++]=pop();
                }
                pop();
                if(topStack!=NULL)
                {
                    postf_exp[j++]=pop();
                }
            }
        }
        else if(isOperator(inf_exp[i]))
        {
            
    printf("\n-operator-\n");
            if(topStack==NULL)
            {
                push(inf_exp[i]);
            }
            else
            {
                if((precedenceOF(inf_exp[i]) > topStack->precedence))
                {
                    push(inf_exp[i]);
                }
                else
                {
                    while((precedenceOF(inf_exp[i]) <= topStack->precedence) && (isBracket(topStack->data)==0))
                    {
                        postf_exp[j++]=pop();
                    }
                    push(inf_exp[i]);
                }
            }
        }
        else
        {
            
    printf("\n-operand-\n");
            postf_exp[j++]=inf_exp[i];
        }
    }
    printf("\n\nPostfix expression : ");
    for(i=0; i<size-1-countBrackets; i++)
    {
        printf(" %c", postf_exp[i]);
    }
    printf("\n\n");
}

void push(char ch)
{
    node* new=(node*)malloc(sizeof(node));
    new->data=ch;
    new->next=topStack;
    new->precedence=precedenceOF(ch);
    topStack=new;
}

char pop()
{
    int popped_data=topStack->data;
    topStack=topStack->next;
    return popped_data;
}

int isBracket(char ch)
{
    if(ch=='(' || ch=='{' || ch=='[')
        return 1;
    else if(ch==')' || ch=='}' || ch==']')
        return 2;
    else
        return 0;
}

int isOperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='%')
        return 1;
    else
        return 0;
}

int precedenceOF(char ch)
{
    if(ch=='+' || ch=='-')
        return 1;
    else if(ch=='*' || ch=='/' || ch=='%')
        return 2;
    else if(ch=='(' || ch=='{' || ch=='[')
        return 3;
}