#include<stdio.h>
void main()
{
    int n;
    printf("enter size of array");
    scanf("%d",&n);
    int arr[n];
    int key;
    int found=0;
    for(int i=0;i<n;i++)
    {
        printf("enter element");
        scanf("%d",&arr[i]);
    }
    printf("enter key");
    scanf("%d",&key);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            found=1;
            printf("element found");
            return;
        }
    }
    if(found==0)
        printf("element not found");

}
