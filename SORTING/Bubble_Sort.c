#include<stdio.h>
#define MAX 100
int main()
{
    int arr[MAX],i,j,temp,n,xchanges;
    printf("Enter the number of the Elements: ");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Enter element %d : ", i+1);
        scanf("%d",&arr[i]);
    }
    
    for(i=0;i<n-1; i++)
    {
        xchanges = 0;
        for(j=0; j<n-1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                xchanges++;
            }
        }
        if(xchanges ==0)
        {
            break;
        }
    }
    printf("Sorted list is : \n");
    for(i=0; i<n; i++)
    {
        printf("%d  ",arr[i]);
    }
    printf("\n");
}
