#include<stdio.h>
void main()
{
    int n;
    printf("enter size of array");
    scanf("%d",&n);
    int arr[n];
    int key;
    int found=0;
    int beg=0;
    int last=n-1;
    for(int i=0;i<n;i++)
    {
        printf("enter element");
        scanf("%d",&arr[i]);
    }
    printf("enter key");
    scanf("%d",&key);
    while(beg<=last)
    {
        int mid=(beg+last)/2;
        if(arr[mid]==key)
        {
            found=1;
            printf("element found");
            return;
        }
        else if(arr[mid]>key)
        {
            last=mid-1;
        }
        else
            beg=mid+1;
    }
    if(found==0)
        printf("element is not found");
}
