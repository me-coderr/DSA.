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
void deSparsePrint(int**, int, int, int);
void add(int**, int**, int***, int, int, int, int);

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
        int** spars;
        makeSparse(&spars, arr, r, c, nzeros);
        printf("\nThe matrix you entered : \n");
        display(arr, r, c);
        printf("\nSparse representation of the matrix : \n");
        display(spars, (nzeros+1), 3);
        printf("\nThe original matrix derived from sparse representation : \n");
        deSparsePrint(spars, (nzeros+1), r, c);
    }
    else
    {
        printf("\nMatrix not converted since sparse representation isn't advantageous.\n\nThe matrix you entered : \n");
        display(arr, r, c);
    }

    //adding 2 matrix
    printf("\nDo you want to see adding 2 matrices using sparse representation? (y/n)\n");
    char ch;
    scanf("%c", &ch);
    scanf("%c", &ch);
    if(ch!='y')
    {
        printf("\nYou chose not to see matrix addition.\n");
    }
    else    
    {
        int** m1, **m2; 
        int **spars1, **spars2, **spars_res, c1, r1, n1, n2;
        printf("Enter no. of rows and columns for the 2 matrices you want to add. \n");
        scanf("%d%d", &r, &c);
        m1=(int**)malloc(r*sizeof(int*));
        m2=(int**)malloc(r*sizeof(int*));
        for(i=0; i<r; i++)
        {
            m1[i]=(int*)malloc(c*sizeof(int));
            m2[i]=(int*)malloc(c*sizeof(int));
        }
        printf("\nNow, enter matrix 1 elements.\n");
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                printf("\n[%d][%d] : ", i, j);
                scanf("%d", &m1[i][j]);
            }
        }
        printf("\nNow, enter matrix 2 elements.\n");
        for(i=0; i<r; i++)
        {
            for(j=0; j<c; j++)
            {
                printf("\n[%d][%d] : ", i, j);
                scanf("%d", &m2[i][j]);
            }
        }
        printf("\nThe matirces you entered : \n\nMatrix 1 :\n");
        display(m1, r, c);
        printf("\nMatrix 2 :\n");
        display(m2, r, c);
        makeSparse(&spars1, m1, r, c, (n1=countNonZeros(m1, r, c)));
        printf("\nSparse representation of Matrix 1 :\n");
        display(spars1, n1+1, 3);
        makeSparse(&spars2, m2, r, c, (n2=countNonZeros(m2, r, c)));
        printf("\nSparse representation of Matrix 2 :\n");
        display(spars2, n2+1, 3);
        printf("\nAfter addition :\n");
        add(spars1, spars2, &spars_res, n1, n2, r, c);
        deSparsePrint(spars_res, spars_res[0][2]+1, r, c);
        printf("\nIt's sparse representation :\n");
        display(spars_res, spars_res[0][2]+1, 3);
    }
    return 0;   
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
    (*spars)=(int**)malloc((count+1)*sizeof(int*));
    for(i=0; i<(count+1); i++)
        (*spars)[i]=(int*)malloc(3*sizeof(int));
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

void deSparsePrint(int** spar, int n, int r, int c)
{
    int i, j, x=1;
    for(i=0; i<r; i++)
    {
        for(j=0;j<c;j++)
        {
            if(x < n && i==spar[x][0] && j==spar[x][1])
                printf(" %d ", spar[x++][2]);
            else
                printf(" 0 ");
        }
        printf("\n");
    }
}

void add(int** m1, int** m2, int*** res, int n1, int n2, int r, int c)
{
    int i, j, x=0;
    (*res)=(int**)malloc((n1+n2+1)*sizeof(int*));
    for(i=0; i<n1+n2+1; i++)
    {
        (*res)[i]=(int*)calloc(3,sizeof(int));
    }
    (*res)[x][0]=r;
    (*res)[x][1]=c;
    (*res)[x++][2]=0;
    printf("\n\nkk\n\n");
    i=1, j=1;
    while(i<n1+1 && j<n2+1)
    {
        if(m1[i][0]==m2[j][0])
        {
            if(m1[i][1]==m2[j][1])
            {
                (*res)[x][0]=m2[j][0];
                (*res)[x][1]=m2[j][1];
                (*res)[x++][2]=m1[i][2] + m2[j][2];
                i++;
                j++;

            }
            else if(m1[i][1] > m2[j][1])
            {
                (*res)[x][0]=m2[j][0];
                (*res)[x][1]=m2[j][1];
                (*res)[x++][2]=m2[j][2];
                j++;
            }
            else
            {
                (*res)[x][0]=m1[i][0];
                (*res)[x][1]=m1[i][1];
                (*res)[x++][2]=m1[i][2];
                i++;
            }
        }
        else if(m1[i][0] > m2[j][0])
        {
            (*res)[x][0]=m2[j][0];
            (*res)[x][1]=m2[j][1];
            (*res)[x++][2]=m2[j][2];
            j++;
        }
        else
        {
            (*res)[x][0]=m1[i][0];
            (*res)[x][1]=m1[i][1];
            (*res)[x++][2]=m1[i][2];
            i++;
        }
    }
    while(i<n1+1)
    {
        (*res)[x][0]=m1[i][0];
        (*res)[x][1]=m1[i][1];
        (*res)[x++][2]=m1[i][2];
        i++;
    }
    while(j<n2+1)
    {
        (*res)[x][0]=m2[j][0];
        (*res)[x][1]=m2[j][1];
        (*res)[x++][2]=m2[j][2];
        j++;
    }
    (*res)[0][2]=x-1;
}