#include<stdio.h>
#include <netinet/in.h> 
#include <stdlib.h>
#include <sys/socket.h> 
#include <sys/types.h>
  
int main()
{
    int client_sock = socket(AF_INET, SOCK_STREAM, 0);//socket creation
  
    struct sockaddr_in servAddr;
  
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5051); 
    servAddr.sin_addr.s_addr = INADDR_ANY;
  
    int connectStatus = connect(client_sock, (struct sockaddr*)&servAddr,sizeof(servAddr));//connect to socket refered by file descriptor
  
    if (connectStatus == -1) 
    {
        printf("Error no server found\n");
    }
  
    else 
    {
        char data[100];
  
        recv(client_sock, data, sizeof(data), 0);
  
        printf("Message: %s\n", data);
    }
  
    return 0;
}