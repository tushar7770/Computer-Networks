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
    int sendarr[n+1][x] , carry=0 , arr[x] , sum = 0;
    for(int i=0 ;i<x ; i++)
    {
        sendarr[n][i] = 0;
    }

    printf("Enter data :\n");

    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<x ; j++)
        {
            scanf("%1d",&sendarr[i][j]);
        }
    }

    for(int i=1 ; i<n ; i++)
    {
        
        for(int j=x-1 ; j>=0 ; j--)
        {
            if(i==1)
            {
                sum = sendarr[i][j]+sendarr[i-1][j]+carry;
    
            }
            else
            {
                sum = arr[j]+sendarr[i][j]+carry;
            }
            
            if( sum == 0)
            {
                carry = 0;
                arr[j] = 0;
            }
            else if(sum == 1)
            {
                carry=0;
                arr[j]=1;
            }
            else if(sum == 2)
            {
                carry = 1;
                arr[j]= 0;
            }
            else
            {
                carry=1;
                arr[j]=1;
            }
        }
        
        if(carry == 1)
        {
            for(int k=x-1 ; k>=0 ; k--)
            {
                sum = arr[k]+carry;
                if( sum == 0)
                {
                    carry = 0;
                    arr[k] = 0;
                }
                else if(sum == 1)
                {
                    carry=0;
                    arr[k]=1;
                }
                else
                {
                    carry = 1;
                    arr[k]= 0;
                }
            }

        }

    }
    for(int i=0 ;i<x ; i++)
    {
        if(arr[i]==0)
            sendarr[n][i] = 1 ;
        else
            sendarr[n][i] = 0 ;

    }

    printf("\nData sended using check sum : \n");

    for(int i=0 ; i<=n ; i++)
    {
        for(int j=0 ;j<x ; j++)
        {
            printf("%d ",sendarr[i][j]);
        }
        printf("\n");
    }

    int receiverdata[n+1][x] , rarr[x];
    printf("Enter receiver data :\n");
    for(int i=0 ; i<n ; i++)
    {
        for(int j=0 ; j<x ; j++)
        {
            scanf("%1d",&receiverdata[i][j]);
        }
    }

    for(int i=1 ; i<n ; i++)
    {
        
        for(int j=x-1 ; j>=0 ; j--)
        {
            if(i==1)
            {
                sum = receiverdata[i][j]+receiverdata[i-1][j]+carry;
    
            }
            else
            {
                sum = rarr[j]+receiverdata[i][j]+carry;
            }
            
            if( sum == 0)
            {
                carry = 0;
                rarr[j] = 0;
            }
            else if(sum == 1)
            {
                carry=0;
                rarr[j]=1;
            }
            else if(sum == 2)
            {
                carry = 1;
                rarr[j]= 0;
            }
            else
            {
                carry=1;
                rarr[j]=1;
            }
        }
        
        if(carry == 1)
        {
            for(int k=x-1 ; k>=0 ; k--)
            {
                sum = rarr[k]+carry;
                if( sum == 0)
                {
                    carry = 0;
                    rarr[k] = 0;
                }
                else if(sum == 1)
                {
                    carry=0;
                    rarr[k]=1;
                }
                else
                {
                    carry = 1;
                    rarr[k]= 0;
                }
            }

        }

    }

    sum=0;
    int temp=0;
    for(int i=0 ; i<x ; i++)
    {
        temp = sendarr[n][i] + rarr[i];
        if(temp==1)
            sum++;
    }

    if(sum == x)
    {
        printf("\nData is accepted");
    }
    else{
        printf("\nData is Invalid ask sender to send again");
    }
    
    return 0;
}