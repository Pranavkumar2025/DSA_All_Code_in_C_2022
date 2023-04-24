#include<stdio.h>
int size = 0;
void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;

}
void heapify(int array[], int size, int i)
{
  int largest = i;
  int l = 2 * i + 1;
  int r = 2 * i + 2;
  if(l < size && array[largest] < array[l])
  {
    largest = l;
  }
  if(r < size && array[largest] < array[r])
  {
    largest = r;
  }
  if(largest != i)
  {
    swap(&array[i], &array[largest]);
    heapify(array,size,largest);
  }
}
void insert(int array[], int data)
{
  if(size == 0)
  {
    array[size] = data;
    size = size +1;
  }
  else
  {
    array[size] = data;
    size = size + 1;
    for(int i = size/2 -1 ; i>=0 ; i--)
    {
      heapify(array,size,i);
    }
  }
}
void deleteRoot(int array[], int data)
{
  int i;
  for(i = 0; i< size ; i++)
  {
    if(data == array[i])
    {
      break;
    }
  }
  swap(&array[i], &array[size -1]);
  size = size -1;
  for(i = size/2 -1 ; i>= 0; i--)
  {
    heapify(array, size, i);
  }
}
void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[10];

  insert(array, 3);
  insert(array, 4);
  insert(array, 9);
  insert(array, 5);
  insert(array, 2);
  
  printf("\nHeap array of the list is : ");
  printArray(array,size);
  deleteRoot(array,4);
  printf("\nAfter the deletion on data: ");
  printArray(array,size);
}