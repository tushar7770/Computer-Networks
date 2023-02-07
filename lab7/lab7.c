#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char ip[20];
    printf("\nEnter the IP address : ");
    scanf("%s",ip);

    char a1[5]="\0",a2[5]="\0",a3[5]="\0",a4[5]="\0";
    int b1=0,b2=0,b3=0,b4=0,m=10,r=1;
    int bn1[9],bn2[9],bn3[9],bn4[0];
    int count=1;
    for(int i=0,j=0;i<strlen(ip);i++)
    {
        char a=ip[i];
        if(a!='.')
        {
            switch (count)
            {
                case 1:
                    strncat(a1,&a,1);
                    b1 = b1*m+(a1[j++]-'0');
                    break;
                case 2:
                    strncat(a2,&a,1);
                    b2 = b2*m+(a2[j++]-'0');
                    break;
                
                case 3:
                    strncat(a3,&a,1);
                    b3 = b3*m+(a3[j++]-'0');
                    break;
                
                case 4:
                    strncat(a4,&a,1);
                    b4 = b4*m+(a4[j++]-'0');
                    break;

                default:
                    count=5;
                    break;
            }

        }
        else
        {
            count++;
            j=0;
        }
        
    }
        
    if(b1>255||b1<0||b2>255||b2<0||b3>255||b3<0||b4>255||b4<0||count>4)
    {
        printf("\nINVALID IP\n");
        exit(0);
    }
    int d;
    printf("\nEnter in how many parts you want to divide network : ");
    scanf("%d",&d);

    if(ceil(log2(d)) != floor(log2(d)))
    {
        printf("\nINVALID DIVISION OF NETWORK\n");
        exit(0);
    }

    if(b1>=0 && b1<=127)
    {
        printf("\nClass --> A");
        printf("\nTotal no of ip address (2^24)  : %0.f",pow(2,24));
        printf("\nTotal no of host address in one subnet (excluding Subnet id &  Direct Broadcast id): %0.f",pow(2,24)/d - 2);
        printf("\nTotal no of host address (2^24 - n*2)(excluding Subnet id &  Direct Broadcast id): %0.f",pow(2,24)-d*2);

        for(int i=0;i<d;i++)
        {
            
            if(d<=pow(2,8))
            {
                printf("\n=====================================\n");
                printf("\nSubnet -> %d",i+1);
                printf("\nsubnet id -> %d.%0.f.%d.%d",b1,i*pow(2,8)/d,0,0);
                printf("\nRange -> %d.%0.f.%d.%d to %d.%0.f.%0.f.%0.f",b1,i*pow(2,8)/d,0,1,b1,(i+1)*pow(2,8)/d-1,pow(2,8)-1,pow(2,8)-2);
                printf("\nDirect broadcast address -> %d.%0.f.%0.f.%0.f",b1,(i+1)*pow(2,8)/d-1,pow(2,8)-1,pow(2,8)-1);
                printf("\nLimited broadcast : 255.255.255.255");
            }
            else
            {

            }
            
        }
        printf("\n=====================================\n");
        printf("\n       ------Routing Table------\n");
        printf("\nSubnet ID\tSubnet Mask\tInterface");
        for(int i=0;i<d;i++)
        {
            printf("\n%d.%0.f.0.0\t255.%0.f.0.0\tI%d",b1,i*pow(2,8)/d,(d-1)*pow(2,8)/d,i+1);
        }


    }
    else if(b1>=128 && b1<=191)
    {
        printf("\nClass --> B");
        printf("\nTotal no of ip address (2^16)  : %0.f",pow(2,16));
        printf("\nTotal no of host address in one subnet (excluding Subnet id &  Direct Broadcast id): %0.f",pow(2,16)/d - 2);
        printf("\nTotal no of host address (2^16 - n*2) (excluding Subnet id &  Direct Broadcast id): %0.f",pow(2,16)-d*2);
        for(int i=0;i<d;i++)
        {
            if(d<=pow(2,8))
            {
                printf("\n=====================================\n");
                printf("\nSubnet -> %d",i+1);
                printf("\nsubnet id -> %d.%d.%0.f.%d",b1,b2,i*pow(2,8)/d,0);
                printf("\nRange -> %d.%d.%0.f.%d to %d.%d.%0.f.%0.f",b1,b2,i*pow(2,8)/d,1,b1,b2,(i+1)*pow(2,8)/d-1,pow(2,8)-2);
                printf("\nDirect broadcast address -> %d.%d.%0.f.%0.f",b1,b2,(i+1)*pow(2,8)/d-1,pow(2,8)-1);
                printf("\nLimited broadcast : 255.255.255.255");
            }
            else
            {

            }
            
        }
        printf("\n=====================================\n");
        printf("\n       ------Routing Table------\n");
        printf("\nSubnet ID\tSubnet Mask\tInterface");
        for(int i=0;i<d;i++)
        {
            printf("\n%d.%d.%0.f.0\t255.255.%0.f.0\tI%d",b1,b2,i*pow(2,8)/d,(d-1)*pow(2,8)/d,i+1);
        }
    }
    else if(b1>=192 && b1<=223)
    {
        printf("\nClass --> C");
        printf("\nTotal no of ip address  (2^8) : %0.f",pow(2,8));
        printf("\nTotal no of host address in one subnet (excluding Subnet id &  Direct Broadcast id): %0.f",pow(2,8)/d - 2);
        printf("\nTotal no of host address (2^8 - n*2)(excluding Subnet id &  Direct Broadcast id): %0.f",pow(2,8)-d*2);
        for(int i=0;i<d;i++)
        {
            if(d<=pow(2,7))
            {
                printf("\n=====================================\n");
                 printf("\nSubnet -> %d",i+1);
                printf("\nsubnet id -> %d.%d.%d.%0.f",b1,b2,b3,i*pow(2,8)/d);
                printf("\nRange -> %d.%d.%d.%0.f to %d.%d.%d.%0.f",b1,b2,b3,i*pow(2,8)/d+1,b1,b2,b3,(i+1)*pow(2,8)/d-2);
                printf("\nDirect broadcast address -> %d.%d.%d.%0.f",b1,b2,b3,(i+1)*pow(2,8)/d-1);
                printf("\nLimited broadcast : 255.255.255.255");
            }
            else
            {
                printf("\nNOT POSSIBLE");
            }
            
        }
        printf("\n=====================================\n");
        printf("\n       ------Routing Table------\n");
        printf("\nSubnet ID\tSubnet Mask\tInterface");
        for(int i=0;i<d;i++)
        {
            printf("\n%d.%d.%d.%0.f\t255.255.255.%0.f\tI%d",b1,b2,b3,i*pow(2,8)/d,(d-1)*pow(2,8)/d,i+1);
        }
    }
    else if(b1>=224 && b1<=239)
    {
        printf("\nClass --> D");
        printf("\nNOT POSSIBLE");
    }
    else if(b1>=240 && b1<=255)
    {
        printf("\nClass --> E");
        printf("\nNOT POSSIBLE");
    }

    return 0;
}