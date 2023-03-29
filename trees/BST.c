/*Insertion and deletion of a node in BST and tree traversals*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *left;
    struct node *right;
    int data;
} node;

int insertNode(node*, int);
node* deleteNode(node*, int);
void inorderTraversal(node*);
void preorderTraversal(node*);
void postorderTraversal(node*);
node* inorderPredecessor(node*);

int main()
{
    int i=0, val, ch=-1;
    char exit='n';
    printf("\nEnter the value of nodes in the BST.\nEnter 'e' to exit. \n");
    printf("\n Node %d : ", ++i);
    scanf("%d", &val);
    node* head=(node*)malloc(sizeof(node));
    head->data=val;
    head->left=NULL;
    head->right=NULL;
    do
    {
        printf("\n Node %d : ", ++i);
        scanf("%d", &val);
        if(insertNode(head, val))       // if insertion fails.
            i--;
        scanf("%c", &exit);
    } while (exit!='e');
    printf("\n\nBST created.\n");
    while(ch!=0)
    {
        printf("\nSelect an operation :\n 1. Insertion\n 2. Deletion\n 3. InOrder Traversan\n 4. PreOrder Traversasl\n 5. PostOrder Traveresal\n 0. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            printf("\nEnter Node Value to insert : ");
            scanf("%d", &val);
            insertNode(head, val);
            break;

        case 2 :
            printf("\nEnter Node Value to delete : ");
            scanf("%d", &val);
            deleteNode(head, val);
            break;
            
        case 3 :
            printf("\n\nIn Order Traversal : ");
            inorderTraversal(head);
            break;
            
        case 4 :
            printf("\n\nPre Order Traversal : ");
            preorderTraversal(head);
            break;
            
        case 5 :
            printf("\n\nPost Order Traversal : ");
            postorderTraversal(head);
            break;
        
        case 0 : 
            break;
        
        default:
            printf("\nWrong input.\n");
            break;
        }
    }
}

int insertNode(node* head, int val)
{
    if(head==NULL)
    {
        node* newnode=(node*)malloc(sizeof(node));
        newnode->data=val;
        newnode->left=NULL;
        newnode->right=NULL;
        head=newnode;
        return 0;
    }
    node* prev=(node*)malloc(sizeof(node));
    while(head!=NULL)
    {
        prev=head;
        if(head->data == val)
        {
            printf("\n%d is already present in the BST hence cannot be added.\n", val);
            return 1;
        }
        else if(head->data > val)
        {
            head=head->left;
        }
        else
        {
            head=head->right;
        }
    }
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->left=NULL;
    newnode->right=NULL;
    if(prev->data < val)
        prev->right=newnode;
    else
        prev->left=newnode;
    return 0;
}

node* deleteNode(node* head, int val)
{
    if(head==NULL)
        return NULL;
    if(head->left==NULL && head->right==NULL && head->data==val)
    {
        free(head);
        return NULL;    
    }
    if(head->data > val)
        head->left=deleteNode(head->left, val);
    else if(head->data < val)
        head->right=deleteNode(head->right, val);
    else
    {   
        node* iPre=(node*)malloc(sizeof(node));
        iPre=inorderPredecessor(head);
        head->data=iPre->data;
        head->left=deleteNode(head->left, iPre->data);
    }
    return head;
}

node* inorderPredecessor(node* head)
{
    head=head->left;
    while(head->right != NULL)
    {
        head=head->right;
    }
    return head;
}

void inorderTraversal(node* head)
{
    if(head!=NULL)
    {
        inorderTraversal(head->left);
        printf(" %d ", head->data);
        inorderTraversal(head->right);
    }
}

void preorderTraversal(node* head)
{
    if(head!=NULL)
    {
        printf(" %d ", head->data);
        preorderTraversal(head->left);
        preorderTraversal(head->right);
    }
}

void postorderTraversal(node* head)
{
    if(head!=NULL)
    {
        postorderTraversal(head->left);
        postorderTraversal(head->right);
        printf(" %d ", head->data);
    }
}