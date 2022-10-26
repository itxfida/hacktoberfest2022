#include <stdio.h>
 
// Finding minimum and maximun element in an array

int main()
{
    int array[100], n, min, max;
   
    printf("Enter the number of elements in an array : ");
    scanf("%d",&n);
 
    printf("Enter the array elements: ");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
 
    min = max = array[0];

    for(int i=1; i<n; i++)
    {
      if(min > array[i])
        {
		    min = array[i];
        }

	  if(max < array[i])
        {
		    max = array[i];
        }  
    }

    printf("The minimum element of array is: %d \n", min);
    printf("The maximum element of array is: %d",max);

    return 0;
}
