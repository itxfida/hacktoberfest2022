#include<stdio.h>
main()
{
int i,j,a[20],key,n;
printf("enter the numbers of input\n");
scanf("%d",&n);
printf("enter the values\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=1;i<n;i++)
{
    key=a[i];
j=i-1;
while(j>=0 && a[j]>key)
{
a[j+1]=a[j];
j=j-1;
a[j+1]=key;
}
}
printf("the arrangement are:\n");
for(i=0;i<n;i++)
    printf("%d\n",a[i]);
}
