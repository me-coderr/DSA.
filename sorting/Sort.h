
#include<stdio.h>
#include<malloc.h>
#include<time.h>

void swap(int* a, int* b)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int* randFillMat(int* arr, int n)
{
    srand(time(0));
    for(int i=0; i<n; i++)
        arr[i]=rand()%10; 
    return arr;
}

void display(int* arr, int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        printf(" %d ", arr[i]);
    }
    printf("\n");
}

int partition(int** arr, int low, int high)
{
    int i=low, j=i-1;
    int pivot=high;
    for(; i<high; i++)
    {
        if((*arr)[i] < (*arr)[pivot])
        {
            swap(&(*arr)[++j], &(*arr)[i]);
        }
    }
    swap(&(*arr)[++j], &(*arr)[pivot]);
    return j;
}

void merge(int** arr, int low, int mid, int high)
{
    int i, j, k;
    int n1=(mid-low+1);
    int n2=(high-mid);
    int L[n1];
    int R[n2];
    for(i=0; i<n1; i++)
        L[i]=(*arr)[low+i];
    for(i=0; i<n2; i++)
        R[i]=(*arr)[mid+1+i];
    i=0;
    j=0;
    k=low;
    while(i<n1 && j<n2)
    {
        if(L[i] > R[j])
            (*arr)[k++]=R[j++];
        else
            (*arr)[k++]=L[i++];
    }
    while(i<n1)
        (*arr)[k++]=L[i++];
    while(j<n2)
        (*arr)[k++]=R[j++];
}

int* selectionSort(int* arr, int n)
{
    int i, j, min_idx;
    for(i=0; i<n; i++)
    {
        min_idx=i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j]>arr[min_idx])
            {
                min_idx=j;
            }
        }
        if(min_idx != i)
            swap(&arr[i], &arr[min_idx]);
    }
    return arr;
}

int* bubbleSort(int* arr, int n)
{
    int i, j, flag;
    for(i=0; i<n-1; i++)
    {
        flag=1;
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                flag=0;
                swap(&arr[j], &arr[j+1]);
            }
        }
        if(flag)
        {
            break;
        }
    }
    return arr;
}

int* insertionSort(int* arr, int n)
{
    int i, j, k=0;
    for(i=1; i<n; i++)
    {
        k=arr[i];
        j=i-1;
        while(arr[j]>k && j>=0)
        {
            arr[j+1]=arr[j];
            --j;
        }
        arr[j+1]=k;
    }
    return arr;
}

void quickSort(int** arr, int low, int high)
{
    if(low<high)
    {
        int pivotIdx=partition(arr, low, high);
        quickSort(arr, low, pivotIdx-1);
        quickSort(arr, pivotIdx+1, high);
    }
}

void mergeSort(int** arr, int low, int high)
{
    int mid;
    if(high>low)
    {
        mid=(high+low)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }
}