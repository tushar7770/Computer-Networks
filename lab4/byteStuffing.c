#include<stdio.h>
#include<string.h>

int main()
{
    char sender[30];
    printf("Enter the data :");
    scanf("%s",sender);

    int count=0;
     for(int j=strlen(sender)+1; j>0 ; j--)
    {
        sender[j]=sender[j-1];
    }
    sender[0]='F';

    for(int i=1;i<strlen(sender);i++)
    {
        if(sender[i]=='F'||sender[i]=='f'||sender[i]=='E'||sender[i]=='e')
        {
            for(int j=strlen(sender)+1; j>i ; j--)
            {
                sender[j]=sender[j-1];
            }
            if( i==0)
            {
                sender[i]='F';
            }
            else
            {
                sender[i]='E';
            }
            i++;
            
        }
    }
    char f='F';
    strncat(sender,&f,1);
    printf("Data after byte stuffing = %s\n",sender);

    char rec[30];
    printf("Enter data received by receiver :");
    scanf("%s",rec);


    for(int i=0;i<strlen(rec);i++)
    {
        if(rec[i]=='F'||rec[i]=='f'||rec[i]=='E'||rec[i]=='e' )
        {
            if(rec[i]=='F')
            {
                count=1;
            }
            else{
                count=0;
            }
            int x=strlen(rec);
            for(int j=i; j<x ; j++)
            {
                rec[j]=rec[j+1];
            }
            if(count)
            {
                i--;
            }
            
        }
    }


    printf("Data after removing stuffed bytes :%s",rec);


    return 0;
}