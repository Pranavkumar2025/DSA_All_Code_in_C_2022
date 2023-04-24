#include<stdio.h>
int creatarray(int n,int *arr)
{
    printf("Enter the elements of array: \n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
int traversalofArray(int n,int *arr)
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
int main()
{
    int n,i,c,j,ptr;
    printf("enter the no of elements in the array:");
    scanf("%d",&n);
    int arr[n];
    creatarray(n,arr);
    printf("\nArray is : ");
    traversalofArray(n,arr);
    for(i=0;i<n-1;i++)
    {
        c=0;   
        for(j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                ptr=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=ptr;
                c++;
            }
        }
        if(c==0)
        {
            printf("\nalready sorted at position %d",i+1);
            break;
        }
    }
    printf("\nNew array is :");
    traversalofArray(n,arr);
}