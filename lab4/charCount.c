#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char sender[30];
    int n;
    printf("Enter the data :");
    scanf("%s",sender);
    printf("Enter the no of Frames : ");
    scanf("%d",&n);

    int quot=strlen(sender)/n , rem=strlen(sender)%n;
    

    int count=0 , temp=0;

    for(int i=0;i<strlen(sender);i++)
    {
        count++;
       
        if((count==quot+1 || i==0) && temp<n)
        {
            temp++;
            for(int j=strlen(sender)+1; j>i ; j--)
            {
                sender[j]=sender[j-1];
            }
            if(temp<n)
            {
                sender[i]=quot+1+'0';
            }
            else
            {
                sender[i]=quot+rem+1+'0';
            }
            
            count=0;
        }

    }
    printf("Data after character count = %s\n",sender);

    char rec[30];
    printf("Enter data received by receiver :");
    scanf("%s",rec);

    count=0;
    char ctemp=rec[0];
    int x=ctemp-'0';

    for(int i=0;i<strlen(rec); i++ )
    {
        if(rec[i]==ctemp)
        {
            if(strlen(rec)-i-x < x && strlen(rec)-i-x !=0)
            {
                count=1;
                break;
            }
            i=i+x-1;
        }
        else{
            int y = rec[i]-'0';
            if(x<y)
            {
                if(i+y > strlen(rec) || i+y < strlen(rec))
                {
                
                    count=1;
                    break;
                }
                i=i+y-1;
            }
            else{
                count=1;
                break;
            }
        }
        
    }
    if(count==0)
    {
        printf("\nData transfered to receiver without error");
    }
    else{
        printf("\nData transfered to receiver has error");
    }

    return 0;
}