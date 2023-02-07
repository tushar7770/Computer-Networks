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
    char msg[256];
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
        
    socklen_t add;
    bind(sockfd,(struct sockaddr *) &servaddr,sizeof(servaddr));
    add =sizeof(other);
        
    recvfrom(sockfd,msg, sizeof(msg),0, (struct sockaddr *) &other,&add); 
    printf("msg received : %s",msg);
    
    close(sockfd); 
    return 0; 
}