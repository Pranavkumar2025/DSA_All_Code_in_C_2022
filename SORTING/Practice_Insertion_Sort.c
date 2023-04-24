#include<stdio.h>
int creatarray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
}
int traversalofArray(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d  ",arr[i]);
    }
}
int insertionsort(int *arr,int n)
{
    int i,j,k;
    for(i=1;i<n;i++)
    {
        k=arr[i];
        for(j=i-1; j>=0 && k<arr[j]; j--)
        {
            arr[j+1]=arr[j];
        }
        arr[j+1]=k;
    }
}
int main()
{
    int n;
    printf("Enter the no of element in the Arrray: ");
    scanf("%d",&n);
    int arr[n];
    creatarray(arr,n);
    printf("\nArray is : ");
    traversalofArray(arr,n);
    insertionsort(arr,n);
    printf("\nAfter insertion of an Array: ");
    traversalofArray(arr,n);
}