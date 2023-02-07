#include <netinet/in.h> 
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> 
#include <sys/types.h>
  
int main()
{
    int server_sock = socket(AF_INET, SOCK_STREAM, 0);//socket creation : socket(domain:ipv4 ,ipv6 , communication time : tcp->reliable ,udp , protocol : 0 appear in protocol field in IP header  of file )
  
    char data[100] = "welocome to socket programming " ;
  
    struct sockaddr_in servAddr;
  
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5051);
    servAddr.sin_addr.s_addr = INADDR_ANY;
  
    bind(server_sock, (struct sockaddr*)&servAddr, sizeof(servAddr));//bind socket to address and port
  
    listen(server_sock, 1);//max length of q (means server respond to client)
  
    
    int clientSocket = accept(server_sock, NULL, NULL);//creating new sockety to hold client
  
    
    send(clientSocket, data, sizeof(data), 0);
  
    return 0;
}
