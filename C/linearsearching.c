#include <stdio.h>

// Linear Searching in C Language

int main() 
{
    int a[100], n, i, item;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
  
    printf("Enter the element of the array: ");
    for(i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    
    printf("Enter the item to be searched: ");
    scanf("%d", &item);
  
    for (i = 0; i < n; i++)
    {
    if (a[i] == item)
    {
      printf("Item is present!!");
      break;
    }
    }

    if (i == n)
    printf("Item is not found!!");
}
