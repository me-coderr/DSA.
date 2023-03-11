/*WAP to add and multiply two polynomials using array.*/

#include<stdio.h>
#include<stdlib.h>

void multiplyPolynomial(int**, int**, int**, int, int);
void addPolynomial(int**, int**, int**, int, int);
void displayPolynomial(int*, int);

int main()
{
    int deg1, deg2, size_res, *arr1, *arr2, *res, i;
    printf("\n\nNote : Polynomial Input Format : a0 x^0 + a1 x^1 + a1 x^2 + ..... + an x^n. \nENter all values including zero if ai doesnt exist (i belongs to 1 - n).\n");
    printf("\nEnter the highest degree of x in polynomial 1 : ");
    scanf("%d", &deg1);
    arr1=(int*)malloc(deg1*sizeof(int));
    printf("\nEnter values for polynomial 1. \n");
    for(i=0; i<deg1; i++)
    {
        printf("a%d : ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\nEnter the highest degree of x in polynomial 2 : ");
    scanf("%d", &deg2);
    arr2=(int*)malloc(deg2*sizeof(int));
    printf("\nEnter values for polynomial 2. \n");
    for(i=0; i<deg2; i++)
    {
        printf("a%d : ", i);
        scanf("%d", &arr2[i]);
    }
    printf("\nPolynomial 1 : ");
    displayPolynomial(arr1, deg1);
    printf("\nPolynomial 2 : ");
    displayPolynomial(arr2, deg2);
    addPolynomial(&arr1, &arr2, &res,deg1, deg2);
    printf("\nResultant Polynomial after addition : ");
    displayPolynomial(res, ((deg1>deg2)?deg1:deg2));
    multiplyPolynomial(&arr1, &arr2, &res, deg1, deg2);
    printf("\nResultant Polynomial after multiplication : ");
    displayPolynomial(res, deg1+deg2);
}

void addPolynomial(int** arr1, int** arr2, int** res, int deg1, int deg2)
{
    int size=((deg1>deg2)?deg1:deg2);
    *res=(int*)malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
    {
        if(i<deg1 && i<deg2)
            (*res)[i]=(*arr1)[i]+(*arr2)[i];
        else if(i<deg1)
            (*res)[i]=(*arr1)[i];
        else
            (*res)[i]=(*arr2)[i];
    }
}

void multiplyPolynomial(int** arr1, int** arr2, int** res, int deg1, int deg2)
{
    int size=deg1+deg2, i, j, pow;
    *res=(int*)calloc(size,sizeof(int));
    for(i=0; i<deg1; i++)
    {
        for(j=0; j<deg2; j++)
        {
            pow=i+j;
            (*res)[pow]+=(*arr1)[i]*(*arr2)[j];
        }
    }
}

void displayPolynomial(int* arr, int size)
{
    int i;
    for(i=size-1; i>=0; i--)
    {
        if(arr[i]==0)
            continue;
        if(arr[i]==1)
        {
            if(i==0)
                printf(" %d ", arr[i]);
            else if(i==1)
                printf(" x + ");
            else if(i==0)
                printf(" x^%d\n", i);
            else if(i==1 && arr[0]==0)
                printf(" %dx^%d\n", arr[i], i);
            else
                printf(" x^%d + ", i);
        }
        else
        {
            if(i==0)
                printf(" %d ", arr[i]);
            else if(i==1)
                printf(" %dx + ", arr[i]);
            else if(i==0)
                printf(" %dx^%d\n", arr[i], i);
            else if(i==1 && arr[0]==0)
                printf(" %dx^%d\n", arr[i], i);
            else
                printf(" %dx^%d + ", arr[i], i);
        }
    }
}