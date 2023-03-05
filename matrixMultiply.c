/*

Create three different matrices matrixOne, matrixTwo and result-Matrix, using dynamic memory allocation. 
Initialize matrixOne and matrixTwo by using rand() or srand() function, limit the values from 0 to 9. Multiply matrixOne 
and matrixTwo into resultMatrix.
While execution, open another terminal and use top command to see the usage of memory by the process. Calculate the time 
taken for the execution of the program.
Repeat the same exercise for 100,000 x 100,000matrices.

*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

long** multiply(long**, long**, long**, int, int);          //for multication of matrices.
long** fill(long**, int, int);            //to fill the matrix.  
void display(long**, int, int);

int main()
{
    srand(time(0));
    int rowA, columnA, columnB, rowB, rowC, columnC, j;
    long** A;
    long** B;
    long** res;
    while(1)
    {
        printf("\nEnter the number of rows and columns in matrix A :\n");
        scanf("%d%d", &rowA, &columnA);
        printf("\nEnter the number of rows and columns in matrix B :\n");
        scanf("%d%d", &rowB, &columnB);
        printf("\n");
        if(columnA != rowB)             //check if inputs are valid
        {
            printf("\nThe inputs are invalid. Try again.\n\n");
            
        }
        else
        {
            rowC=rowA;
            columnC=columnB;
            A=fill(A, rowA, columnA);
            display(A, rowA, columnA);
            B=fill(B, rowB, columnB);
            display(B, rowB, columnB);
            res=(long**)malloc(rowC*sizeof(long*));
            for(j=0; j<columnC; j++)
            {
                res[j]=(long*)malloc(columnC*sizeof(long));
            }
            res=multiply(A, B, res, rowC, columnC);
            display(res, rowC, columnC);
            return 0;
        }
    }
}

void display(long** mat, int r, int c)
{
    int i, j;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            printf("%lu  ", mat[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

long** fill(long** mat, int r, int c)
{
    int i, j;
    mat=(long**)malloc(r*sizeof(long*));
    for(j=0; j<c; j++)
    {
        mat[j]=(long*)malloc(c*sizeof(long));
    }
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            mat[i][j]=rand()%10;
        }
    }
    return mat;
}

long** multiply(long** mat1, long** mat2, long** res, int r, int c)
{
    int i, j, k;
    for(i=0; i<r; i++)
    {
        for(j=0; j<c; j++)
        {
            res[i][j]=0;
            for(k=0; k<c; k++)
            {
                res[i][j]+=mat1[i][k]*mat2[k][j];
            }        
        }
    }
    return res;
}