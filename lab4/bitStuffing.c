#include<stdio.h>
#include<string.h>

int main()
{
    char sender[30];
    printf("Enter the data :");
    scanf("%s",sender);

    int count=0;

    for(int i=0;i<strlen(sender);i++)
    {
        if(sender[i]=='1')
        {
            count++;
        }
        else
        {
            count=0;
        }

        if(count==5)
        {
            for(int j=strlen(sender)+1; j>i ; j--)
            {
                sender[j]=sender[j-1];
            }
            sender[i+1]='0';
            count=0;
        }
    }
    printf("Data after bit stuffing = %s\n",sender);

    char rec[30];
    printf("Enter data received by receiver :");
    scanf("%s",rec);

    count=0;

    for(int i=0;i<strlen(rec);i++)
    {
        if(rec[i]=='1')
        {
            count++;
        }
        else
        {
            count=0;
        }

        if(count==5)
        {
            for(int j=i+1; j<strlen(rec) ; j++)
            {
                rec[j]=rec[j+1];
            }
            count=0;
        }
    }

    printf("Data after removing stuffed bits :%s",rec);



    

    return 0;
}