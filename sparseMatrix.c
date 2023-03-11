/*WAP to convert a matrix into its sparse representation (triple format). Once represented in sparse format, do not revert back
to the matrix format any-more. Manipulate the sparse representation to find the transpose of the matrix (which should also 
be in sparse representation).
Calculate and find out whether using triple format for your example is advantageous or not.*/

#include<stdio.h>
#include<stdlib.h>

int isAdvantageous(int, int, int);   //nz->no. of non-zeros in matrix. r->no. of rows in matrix. c-> no. of columns in matrix.
void makeSparse(int***, int**, int, int, int);  //to make sparse matrix representation
int countNonZeros(int**, int, int);
void display(int**, int, int);

int main()
{
    int** arr, i, j, r, c, nzeros;
    printf("Enter no. of rows and column in matrix : \n");
    scanf("%d%d", &r, &c);
    arr=(int**)malloc(r*sizeof(int*));
    for(i=0; i<r; i++)
        arr[i]=(int*)malloc(c*sizeof(int));
    printf("Now, enter matrix elements.");
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("\n[%d][%d] : ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    nzeros=countNonZeros(arr, r, c);
    if(isAdvantageous(nzeros, r, c))   //isAdvantageous(...) returns 1 if sparse representation is advantageous.
    {
        int** spars=(int**)malloc((nzeros+1)*sizeof(int*));
        for(i=0; i<(nzeros+1); i++)
            spars[i]=(int*)malloc(3*sizeof(int));
        makeSparse(&spars, arr, r, c, nzeros);
        printf("\nThe matrix you entered : \n");
        display(arr, r, c);
        printf("\nSparse representation of the matrix : \n");
        display(spars, (nzeros+1), 3);
    }
    else
    {
        printf("\nMatrix not converted since sparse representation isn't advantageous.\n\nThe matrix you entered : \n");
        display(arr, r, c);
    }        
}

int countNonZeros(int** arr, int r, int c)
{
    int count=0, i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(arr[i][j]!=0)
                ++count;
        }
    }
    return count;
}

int isAdvantageous(int nz, int r, int c)
{
    if((nz+1)*3 < (r*c))
        return 1;
    else    
        return 0;
}

void makeSparse(int*** spars, int** arr, int r, int c, int count)
{
    int i, j, x=0;
    (*spars)[x][0]=r;
    (*spars)[x][1]=c;
    (*spars)[x++][2]=count;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            if(arr[i][j]!=0)
            {
                (*spars)[x][0]=i;
                (*spars)[x][1]=j;
                (*spars)[x++][2]=arr[i][j];
            }
        }
    }
}

void display(int** arr, int r, int c)
{
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf(" %d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}