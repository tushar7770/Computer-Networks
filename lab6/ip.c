#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void decToBinary(int n)
{
    int arr[8];
    int i = 0;
    while (n > 0) {
        arr[i] = n % 2;
        n = n / 2;
        i++;
    }
     for (int j = i - 1; j >= 0; j--)
        printf("%d", arr[j]);
    
    if(n==0)
    {
        printf("%d",n);
    }

}

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
    decToBinary(b1);printf(".");
    decToBinary(b2);printf(".");
    decToBinary(b3);printf(".");
    decToBinary(b4);

    if(b1>=0 && b1<=127)
    {
        printf("\nClass --> A");

    }
    else if(b1>=128 && b1<=191)
    {
        printf("\nClass --> B");
    }
    else if(b1>=192 && b1<=223)
    {
        printf("\nClass --> C");
    }
    else if(b1>=224 && b1<=239)
    {
        printf("\nClass --> D");
    }
    else if(b1>=240 && b1<=255)
    {
        printf("\nClass --> E");
    }

    return 0;
}