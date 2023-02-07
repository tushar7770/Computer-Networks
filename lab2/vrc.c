#include<stdio.h>
#include<string.h>

int main()
{
    int m,n ;
    printf("Enter the no. of bits in data :");
    scanf("%d",&m);
    printf("Enter the no segments : ");
    scanf("%d",&n);

    int x=m/n;

    int senderdata[n][x+1] ,count = 0;
    printf("Enter data :\n");

    for(int i=0; i<n ; i++)
    {
        count=0;
        for(int j=0; j<x ; j++)
        {
            scanf("%1d",&senderdata[i][j]);
            if(senderdata[i][j]==1)
            {
                count++;
            }
        }
        if(count%2==0)
        {
            senderdata[i][x]=0;
        }
        else
        {
            senderdata[i][x]=1;
        }
    }

    printf("Sender data with vertical parity bit :\n");
    for(int i=0; i<n ; i++)
    {
        for(int j=0; j<=x ; j++)
        printf("%d ",senderdata[i][j]);
        
        printf("\n");

    }

    int receiverdata[n][x+1] , vrc = 0;

    printf("Enter the receiver side 16 bit input :\n");
    for(int i=0; i<n ; i++)
    {
        count=0;
        for(int j=0; j<x ; j++)
        {
            scanf("%1d",&receiverdata[i][j]);
            if(receiverdata[i][j]==1)
            {
                count++;
            }
        }
        if(count%2==0)
        {
            receiverdata[i][x]=0;
        }
        else
        {
            receiverdata[i][x]=1;
        }

        if(receiverdata[i][x] == senderdata[i][x])
        {
            vrc++;
        }

    }
    if(vrc == n)
    {
        printf("\nData is accepted");
    }
    else{
        printf("\nData is Invalid ask sender to send again");
    }

    return 0;

}