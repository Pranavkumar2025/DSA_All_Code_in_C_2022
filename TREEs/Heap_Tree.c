// Max-Heap data structure in C
#include <stdio.h>
#include <stdlib.h>
void insert(int array[], int newNum);
void deleteRoot(int array[], int num);
void heapify(int array[],int size, int i);
void swap(int *a, int *b);
void printArray(int array[], int size);
int size = 0;

int main()
{
  int array[100];
  int i,data;
  
  while(1)
  {
    printf("\n1.Insert \n");
    printf("2.Delete Root\n");
    printf("3.Display \n");
    printf("4.Exit \n");

    printf("Enter your choice: ");
    scanf("%d",&data);

    switch(data)
    {
      case 1:
        printf("Enter the data: ");
        scanf("%d",&data);
        insert(array,data);
        break;
      case 2:
        printf("Enter the data to be Deleted: ");
        scanf("%d", &data);
        deleteRoot(array,data);
        break;
      case 3:
        printf("MAX heap Array is : ");
        printArray(array,size);
        break;
      case 4:
        exit(1);
      
    }

  }
}
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}
void heapify(int array[], int size, int i)
{
  if (size == 1)
  {
    printf("Single element in the heap");
  }
  else
  {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && array[l] > array[largest])
      largest = l;
    if (r < size && array[r] > array[largest])
      largest = r;
    if (largest != i)
    {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
}
void insert(int array[], int newNum)
{
	int i;
  if (size == 0)
  {
    array[0] = newNum;
    size += 1;
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (i = size / 2 - 1; i >= 0; i--)
    {
      heapify(array, size, i);
    }
  }
}
void deleteRoot(int array[], int num)
{
  int i;
  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }

  swap(&array[i], &array[size - 1]);
  size -= 1;
  for (i = size / 2 - 1; i >= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
	int i;         
  for (i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
// int main()
// {
//   int array[10];

//   insert(array, 3);
//   insert(array, 4);
//   insert(array, 9);
//   insert(array, 5);
//   insert(array, 2);

//   printf("Max-Heap array: ");
//   printArray(array, size);

//   deleteRoot(array, 4);

//   printf("After deleting an element: ");

//   printArray(array,size);
// }
