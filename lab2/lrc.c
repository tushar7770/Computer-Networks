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
    
    int sendarr[n+1][x] ;
    for(int i=0 ;i<x ; i++)
    {
        sendarr[n][i] = 0;
    }

    printf("Enter data :\n");

    for(int i=0 ; i<=n ; i++)
    {

        for(int j=0 ; j<x ; j++)
        {
            if(i<n)
            {
                scanf("%1d",&sendarr[i][j]);
                sendarr[n][j]+=sendarr[i][j];
            }
            else
            {
                if(sendarr[i][j]%2 == 0)
                {
                    sendarr[i][j]=0;
                }
                else
                {
                    sendarr[i][j]=1;
                }
            }
        }
    }

    printf("\nData sended with longitudnal parity bit : \n");

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ;j<x ; j++)
        {
            printf("%d ",sendarr[i][j]);
        }
        printf("\n");
    }

    int receiverdata[n+1][x] ,lrc = 0;
    for(int i=0 ;i<x ; i++)
    {
        receiverdata[n][i] = 0;
    }

    printf("Enter receiver data :\n");
    for(int i=0 ; i<=n ; i++)
    {

        for(int j=0 ; j<x ; j++)
        {
            if(i<n)
            {
                scanf("%1d",&receiverdata[i][j]);
                receiverdata[n][j]+=receiverdata[i][j];
            }
            else
            {
                if(receiverdata[i][j]%2 == 0)
                {
                    receiverdata[i][j]=0;
                }
                else
                {
                    receiverdata[i][j]=1;
                }

                if(sendarr[i][j]==receiverdata[i][j])
                {
                    lrc ++;
                }
            }

        }
    }

    if(lrc == x)
    {
        printf("\nData is accepted");
    }
    else{
        printf("\nData is Invalid ask sender to send again");
    }

    return 0;
}