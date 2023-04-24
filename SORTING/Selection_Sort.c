#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX],i,j,n,temp,min;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    for(i=0;i<n; i++)
    {
        printf("Enter elements %d :",i+1);
        scanf("%d",&arr[i]);
    }
    //Selection Sort
    
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(arr[min] > arr[j]);
            min=j;
        }
        if(i != min)
        {
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("Sorted list is : \n");
    for(i=0;i<n;i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}