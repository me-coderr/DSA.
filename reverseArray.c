#include<stdio.h>

int size=10;

int main()
{
    int arr[size], rev[size], i;
    for(i=0; i<size; i++)
    {
        printf("\nEnter array element %d : ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nEntered array is :  ");
    for(i=0; i<size; i++)
    {
        printf("%d\t : \t", arr[i]);
    }
    printf("\n");
    for(i=0; i < size; i++)
    {
        rev[i]=arr[size-i-1];
    }
    printf("\nReversed Array is : ");
    for(i=0; i < size; i++)
    {
        printf("%d\t : ", rev[i]);
    }
    printf("\n");
    printf("\n");
}