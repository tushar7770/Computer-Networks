#include <stdio.h> 
#include <stdlib.h> 
#include <unistd.h> 
#include <string.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <netinet/in.h> 

int main() 
{ 
    int sockfd; 
    char msg[256] = "hello UDP"; 
    struct sockaddr_in  servaddr,other; 
    
    
    if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) // Creating socket
    { 
        perror("socket creation failed"); 
        exit(0); 
    } 
    
    memset(&servaddr, 0, sizeof(servaddr)); 
        
    servaddr.sin_family = AF_INET; 
    servaddr.sin_port = htons(8080); 
    servaddr.sin_addr.s_addr = INADDR_ANY; 
        
    socklen_t ad;
    ad =sizeof(other);
        
    sendto(sockfd,msg, sizeof(msg),0, (const struct sockaddr *) &servaddr,sizeof(servaddr)); 
    printf("\nMSG sent");
    
    close(sockfd); 
    return 0; 
}