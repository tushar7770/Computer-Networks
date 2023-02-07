#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>

typedef struct packet{
    char data[200];
}Packet;

typedef struct frame{
    int frame_kind; 
    int frame_no;
    int ack;
    Packet packet;
}Frame;

int main()
{
	struct sockaddr_in servAddr;
	char buffer[100];
	socklen_t addr_size;

	int frame_id=0;
	Frame frame_recv;
	Frame frame_send;
    int ack_recv = 1;

	int server_sock = socket(AF_INET, SOCK_DGRAM, 0);//socket creation
	
	memset(&servAddr, '\0', sizeof(servAddr));
	servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5052);
    servAddr.sin_addr.s_addr = INADDR_ANY;

	while(1){
		
		if(ack_recv == 1){
			frame_send.frame_no = frame_id;
			frame_send.frame_kind = 1;
			frame_send.ack = 0;		
	
			printf("Enter Data: ");
			scanf("%s", buffer);
			strcpy(frame_send.packet.data, buffer);
			sendto(server_sock, &frame_send, sizeof(Frame), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));
			printf("Frame Send\n");
		}
		int addr_size = sizeof(servAddr);
		int f_recv_size = recvfrom(server_sock, &frame_recv, sizeof(frame_recv), 0 ,(struct sockaddr*)&servAddr, &addr_size);
		
		if( f_recv_size > 0 && frame_recv.frame_no == 0 && frame_recv.ack == frame_id+1){
			printf("Acknowledgement Received\n");
			ack_recv = 1;
		}else{
			printf("Acknowledgement Not Received\n");
			ack_recv = 0;
		}	
  			
		frame_id++;		
	}
	
	close(server_sock);
	return 0;
}