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