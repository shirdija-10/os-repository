#include<stdio.h>
void main()
{
    int n;
    printf("enter size of array");
    scanf("%d",&n);
    int arr[n];
     int min;
     int index=0;
    for(int i=0;i<n;i++)
    {
        printf("enter element");
        scanf("%d",&arr[i]);
    }
    min=arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            index=i;
        }
    }
    printf("minimum ele:%d at index %d",min,index);
}
