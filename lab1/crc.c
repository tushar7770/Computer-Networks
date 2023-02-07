#include<stdio.h>
#include<string.h>

int main()
{
    int divisorLen , dataLen ;
    char divisor[30], data[50] , temp[30] , divisorcpy[30] , quot[10],rem[10] , receiverData[30];

    printf("Enter data block : "); // getting datablock from user
    gets(data);

    printf("Enter divisor    : ");// getting  divisor from user
    gets(divisor);

    divisorLen=strlen(divisor);// calculating divisor length
    dataLen=strlen(data);// calculating datablock length

    for(int  i=0 ; i<divisorLen-1 ;i++)// loop  for adding divisorlength - 1 zeros to datablock
    {
        data[dataLen+i]= '0';
    }

    for(int i=0 ; i<divisorLen ; i++) //loop for getting first L(divisor length ) bits for divison
    {
        temp[i]=data[i];
    }

    strcpy(divisorcpy,divisor); //extra copy of divisor to restore it 

    for(int i=0; i<dataLen ; i++)
    {
        quot[i]=temp[0]; //checking first bit and storing it to quotient

        for(int j=0; j<divisorLen ;j++)
        {
             if(quot[i]=='0') // so if it is 0 than we make all divisor bit 0's
            {
                divisor[j]='0';
            }
            else
            {
                divisor[j]=divisorcpy[j]; // if it is 1 all bit remain same
            }  
        }

        for(int j=divisorLen-1; j>0 ; j--)// loop for performing xor
        {
            if(temp[j]==divisor[j])//if digits are same than 0
            {
                rem[j-1]='0';
            }
            else // if digit are different tha 1
            {
                rem[j-1]='1';
            }
        }
        rem[divisorLen-1]=data[divisorLen+i];//carrying down next bit for operation
        
        strcpy(temp,rem);//now the rem will again go for same process

    }

    printf("\nMessage sent from sender : ");
    for(int i=0; i<dataLen ;i++)
    {
        printf("%c",data[i]);
    }
    for(int i=0; i<divisorLen-1;i++)
    {
        printf("%c",rem[i]);
    }

    printf("\n\nEnter receiverdata       : ");
    gets(receiverData);

//same loops as above the only difference is here we use receiverdata instead of sender data
    for(int i=0 ; i<divisorLen ; i++)
    {
        temp[i]=receiverData[i];
    }

    for(int i=0; i<dataLen ; i++)
    {
        quot[i]=temp[0];

        for(int j=0; j<divisorLen ;j++)
        {
             if(quot[i]=='0')
            {
                divisor[j]='0';
            }
            else
            {
                divisor[j]=divisorcpy[j];
            }  
        }

        for(int j=divisorLen-1; j>0 ; j--)
        {
            if(temp[j]==divisor[j])
            {
                rem[j-1]='0';
            }
            else
            {
                rem[j-1]='1';
            }
        }
        rem[divisorLen-1]=receiverData[divisorLen+i];
        strcpy(temp,rem);

    }

    int count=0;
    for(int i=0; i<divisorLen-1; i++)
    {
        if(rem[i]=='0')
        {
            count++;
        }
    }

    if(count==divisorLen-1)
    {
        printf("\nMessage is treansmitted without loss\n");
    }
    else{
        printf("\nData lost during transmission\n");
    }
    return 0;
}