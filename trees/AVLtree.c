/*
AVL tree.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    int height;
    struct node* left;
    struct node* right;
}node;

node* leftRotate(node*);
node* rightRotate(node*);
int getHeight(node*);
int balanceFactor(node*);
node* insertNode(node*, int);
node* deleteNode(node*, int);
node* inorderPredecessor(node*);
node* createNode(int val);
node* inorderTraversal(node*);
node* preorderTraversal(node*);
node* postorderTraversal(node*);

int main()
{
    node* root=(node*)malloc(sizeof(node));
    root=NULL;
    int i=0, val, ch=-1;
    char exit='n';
    printf("\nEnter the value of nodes in the BST.\nEnter 'e' to exit. \n");
    do
    {
        printf("\n Node %d : ", ++i);
        scanf("%d", &val);
        scanf("%c", &exit);
        if(exit=='e') break;
        root=insertNode(root, val);
                        /*if(insertNode(root, val))       // if insertion fails.
                            i--;*/
    } while (exit!='e');
    printf("\n\nAVL Tree Created.\n");
    while(ch!=0)
    {
        printf("\nSelect an operation :\n 1. Insertion\n 2. Deletion\n 3. InOrder Traversan\n 4. PreOrder Traversasl\n 5. PostOrder Traveresal\n 0. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1 :
            printf("\nEnter Node Value to insert : ");
            scanf("%d", &val);
            root=insertNode(root, val);
            break;

        case 2 :
            printf("\nEnter Node Value to delete : ");
            scanf("%d", &val);
            deleteNode(root, val);
            break;
            
        case 3 :
            printf("\n\nIn Order Traversal : ");
            inorderTraversal(root);
            printf("\n");
            break;
            
        case 4 :
            printf("\n\nPre Order Traversal : ");
            preorderTraversal(root);
            printf("\n");
            break;
            
        case 5 :
            printf("\n\nPost Order Traversal : ");
            postorderTraversal(root);
            printf("\n");
            break;
        
        case 0 : 
            break;
        
        default:
            printf("\nWrong input.\n");
            break;
        }
    }
}

node* createNode(int val)
{
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->height=1;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}

node* inorderPredecessor(node* root)
{
    root=root->left;
    while(root->right != NULL)
        root=root->right;
    return root;
}

node* leftRotate(node* x)
{
    node* y=x->right;
    node* t2=y->left;

    y->left=x;
    x->right=t2;

    x->height=(getHeight(x->left) > getHeight(x->right))? getHeight(x->left) +1 : getHeight(x->right) + 1;
    y->height=(getHeight(y->left) > getHeight(y->right))? getHeight(y->left) +1 : getHeight(y->right) + 1;

    return y;
}

node* rightRotate(node* y)
{
    node* x=y->left;
    node* t2=x->right;

    x->right=y;
    y->left=t2;

    x->height=(getHeight(x->left) > getHeight(x->right))? getHeight(x->left) +1 : getHeight(x->right) + 1;
    y->height=(getHeight(y->left) > getHeight(y->right))? getHeight(y->left) +1 : getHeight(y->right) + 1;

    return x;
}

node* insertNode(node* root, int val)
{
    if(root==NULL)
        return createNode(val);
    if(root->data < val)
        root->right=insertNode(root->right, val);
    else if(root->data > val)
        root->left=insertNode(root->left, val);

    root->height=(getHeight(root->left) > getHeight(root->right))? getHeight(root->left) +1 : getHeight(root->right) + 1;
    
    int BF=balanceFactor(root);
    if(BF < -1 && val > root->right->data)
    {
        return leftRotate(root);
    }
    else if(BF > 1 && val < root->left->data)
    {
        return rightRotate(root);
    }
    else if(BF < -1 && val < root->right->data)
    {
        root->right=rightRotate(root->right);
        return leftRotate(root);
    }
    else if(BF > -1 && val > root->left->data)
    {
        root->left=leftRotate(root->left);
        return rightRotate(root);
    }
    return root;
}

node* deleteNode(node* root, int val)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->right==NULL && root->left==NULL && root->data==val)
    {
        free(root);
        return NULL;
    }
    if(root->data < val)
        root->right=deleteNode(root->right, val);
    else if(root->data > val)
        root->left=deleteNode(root->left, val);
    else
    {
        node* iPre=(node*)malloc(sizeof(node));
        iPre=inorderPredecessor(root);
        root->data=iPre->data;
        root->left=deleteNode(root->left, root->data);
    }
    return root;
}

int getHeight(node* n)
{
    if(n==NULL)
        return 0;
    else
        return n->height;
}

int balanceFactor(node* n)
{
    if(n==NULL) return 0;
    return (getHeight(n->left) - getHeight(n->right));
}

node* inorderTraversal(node* root)
{
    if(root!=NULL)
    {
        inorderTraversal(root->left);
        printf(" %d ", root->data);
        inorderTraversal(root->right);
    }
}

node* preorderTraversal(node* root)
{
    if(root!=NULL)
    {
        printf(" %d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

node* postorderTraversal(node* root)
{
    if(root!=NULL)
    {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf(" %d ", root->data);
    }
}