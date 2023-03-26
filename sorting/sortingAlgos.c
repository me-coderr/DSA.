/*
All sorting algorithms :
    Selection Sort  //O(n^2)
    Bubble Sort     //O(n^2)
    Insertion Sort  //O(n^2) - not sure
    Quick Sort      //O(nlogn) best case and O(n^2) worst case.
    Merge Sort      //O(nlogn) everytime.
    Heap Sort       //O(nlogn)
*/

#include "Sort.h"

int main()
{
    int ch, size, *arr;
    printf("\nEnter the size of the array.\n");
    scanf("%d", &size);
    arr=(int*)malloc(sizeof(int)*size);
    do
    {
        printf("\n\nwhich sorting technique do you wish to implement?\n 1. Selection Sort\n 2. Bubble Sort.\n 3. Insertion Sort\n 4. Quick Sort.\n 5. Merge Sort.\n 0. To Exit.\n");
        scanf("%d", &ch);
        printf("\n");
        switch (ch)
        {
        case 1: 
            arr=randFillMat(arr, size);
            display(arr, size);
            selectionSort(arr, size);
            display(arr, size);
            break;
        
        case 2:  
            arr=randFillMat(arr, size);
            display(arr, size);
            bubbleSort(arr, size);
            display(arr, size);
            break;
        
        case 3:  
            arr=randFillMat(arr, size);
            display(arr, size);
            insertionSort(arr, size);
            display(arr, size);
            break;
        
        case 4: 
            arr=randFillMat(arr, size);
            display(arr, size);
            quickSort(&arr, 0, size-1);
            display(arr, size);
            break;
        
        case 5:  
            arr=randFillMat(arr, size);
            display(arr, size);
            mergeSort(&arr, 0, size-1);
            display(arr, size);
            break;

        case 0 :
            break;

        default:
            printf("\nEnter number between 1 and 5\n");
            break;
        }
    } while (ch!=0);
}
