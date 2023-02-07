#include<iostream>
#include<stdio.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>

struct frame
{
 int packet[40];
};

struct ack
{
 int acknowledge[40];
};

int main()
{
    int serversocket;
    sockaddr_in serveraddr,clientaddr;

    socklen_t len;

    int windowsize,totalpackets,totalframes,framessend=0,i=0,j=0,k,l,m,n,repacket[40];

    ack acknowledgement;
    frame f1;

    char req[50];

    serversocket=socket(AF_INET,SOCK_DGRAM,0); //socket creation
    bzero((char*)&serveraddr,sizeof(serveraddr));

    serveraddr.sin_family=AF_INET;
    serveraddr.sin_port=htons(7070);
    serveraddr.sin_addr.s_addr=INADDR_ANY;

    bind(serversocket,(sockaddr*)&serveraddr,sizeof(serveraddr));

    bzero((char*)&clientaddr,sizeof(clientaddr));

    len=sizeof(clientaddr);
    
    //connection establishment.
    recvfrom(serversocket,req,sizeof(req),0,(sockaddr*)&clientaddr,&len);

    //sending request for windowsize.
    sendto(serversocket,”REQUEST FOR WINDOWSIZE.”,sizeof(“REQUEST FOR WINDOWSIZE.”),0,(sockaddr*)&clientaddr,sizeof(clientaddr));

    //obtaining windowsize.
    recvfrom(serversocket,(char*)&windowsize,sizeof(windowsize),0,(sockaddr*)&clientaddr,&len);

   //sending details to client.
    sendto(serversocket,(char*)&totalpackets,sizeof(totalpackets),0,(sockaddr*)&clientaddr,sizeof(clientaddr));

    recvfrom(serversocket,req,sizeof(req),0,(sockaddr*)&clientaddr,&len);

    sendto(serversocket,(char*)&totalframes,sizeof(totalframes),0,(sockaddr*)&clientaddr,sizeof(clientaddr));

    recvfrom(serversocket,req,sizeof(req),0,(sockaddr*)&clientaddr,&len);
   

    printf(“\nPRESS ENTER TO START THE PROCESS.\n”);

    fgets(req,2,stdin);
    




 




 

   //starting the process of sending
   j=0,l=0;
    while(l<totalpackets)
    {
        bzero((char*)&f1,sizeof(f1));

        for(m=0;m<j;m++)
        {
            printf(“%d  “,repacket[m]);

            f1.packet[m]=repacket[m];

        }

        while(j<windowsize && i<totalpackets)
        {
             printf(“%d  “,i);

            f1.packet[j]=i;

            i++;

            j++;

        }
        printf(“\nSending frame %d\n”,framessend);
        sendto(serversocket,(char*)&f1,sizeof(f1),0,(sockaddr*)&clientaddr,sizeof(clientaddr));
        recvfrom(serversocket,(char*)&acknowledgement,sizeof(acknowledgement),0,(sockaddr*)&clientaddr,&len);

        while(m<windowsize && n<totalpackets)
        {
            if(acknowledgement.acknowledge[m]==-1)
            {
                printf(“\nNegative acknowledgement received for packet: %d\n”,f1.packet[m]);

                k=1;

                repacket[j]=f1.packet[m];

                j++;

            }
            else{
                l++;
            }
            m++;
            n++;

        }
        if(k==0)
        {

            printf(“\nPositive acknowledgement received for all packets within the frame: %d\n”,framessend);

        }

        framessend++;

        printf(“\nPRESS ENTER TO PROCEED……\n”);

        fgets(req,2,stdin);
            
    }

 printf(“\nAll frames send successfully.\n\nClosing connection with the client.\n”);

 close(serversocket);

}