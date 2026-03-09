#include<stdio.h>
void main()
{
    int n;
     printf("shirdija");
    printf("enter no.of process");
    scanf("%d",&n);
    int p[n];
    int a[n];
    int b[n];
    int completion[n];
    int tat[n];
    int wt[n];
    int curr_time=0;
    for(int i=0;i<n;i++)
    {
        printf("enter arrival time");
        scanf("%d",&a[i]);
        printf("enter brust time");
        scanf("%d",&b[i]);
        p[i]=i;

    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
            {
                int temp=a[i];
                a[j]=a[i];
                temp=a[i];
                int temp1=b[i];
                b[j]=b[i];
                temp1=b[i];
                 int temp2=p[i];
                p[j]=p[i];
                temp2=p[i];

            }
        }
    }
    for(int i=0;i<n;i++)
    {
       if(curr_time<a[i])
       {
           curr_time=a[i];
       }
       completion[i]=curr_time+b[i];
       tat[i]=completion[i]-a[i];
       wt[i]=tat[i]-b[i];
       curr_time=completion[i];
    }
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        i, a[i], b[i], completion[i], tat[i], wt[i]);
    }

}




