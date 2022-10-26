#include<stdio.h>

// Check if a number is Pallindrome or not

int main()
{
    int n, temp, sum = 0, rem = 0;
    printf("Enter any number: ");
    scanf("%d", &n);
    temp = n;
    
    while(n > 0)
    {  
        rem = n % 10;
        sum = sum * 10 + rem;
        n = n/ 10;
    }
    
    if(sum == temp)
    {
        printf("The number %d is a Palindrome Number!", sum);
    }
    else
    {
    printf ("The number %d is not a Palindrome Number!", sum);
    }
    
    return 0;
}
