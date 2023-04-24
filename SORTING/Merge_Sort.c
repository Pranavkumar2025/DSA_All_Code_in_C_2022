#include <stdio.h>

void Merge(int * , int , int , int );

void MergeSort(int *array, int left, int right)
{
    int middle = (left+right)/2;
    /* We have to sort only when left<right because when left=right it is anyhow sorted*/
    if(left<right)
    {
        /* Sort the left part */
        MergeSort(array, left, middle);
        /* Sort the right part */
        MergeSort(array, middle + 1, right);
        /* Merge the two sorted parts */
        Merge(array, left, middle, right);
    }
}
/* Merge functions merges the two sorted parts */
void Merge(int *array, int left, int middle, int right)
{
    /*to store sorted array*/
    int tmp[right - left + 1];
    int pos = 0, leftposition = left, rightposition = middle + 1;
    while (leftposition <= middle && rightposition <= right)
    {
        if (array[leftposition] < array[rightposition])
        {
            tmp[pos++] = array[leftposition++];
        }
        else
        {
            tmp[pos++] = array[rightposition++];
        }
    }
    while (leftposition <= middle)
        tmp[pos++] = array[leftposition++];
    while (rightposition <= right)
        tmp[pos++] = array[rightposition++];
    int i;
    /* Copy back the sorted array to the original array */
    for (i = 0; i < pos; i++)
    {
        array[i + left] = tmp[i];
    }
    return;
}
int main()
{
    int size;
    printf("Enter the size of an array :: ");
    scanf("%d", &size);
    int array[size];
    int i, j, k;
    printf("\nEnter the array elements :: \n");
    for (i = 0; i < size; i++)
    {
        printf("\nEnter %d array element :: ",i+1);
        scanf("%d", &array[i]);
    }
    /* Calling this functions sorts the array */
    MergeSort(array, 0, size - 1);
    printf("\nAfter Merge Sort :: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
