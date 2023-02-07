
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
	struct sockaddr_in servAddr, newAddr;
	char buffer[100];
	socklen_t addr_size;

	int frame_id=0;
	Frame frame_recv;
	Frame frame_send;	

	int client_sock = socket(AF_INET, SOCK_DGRAM, 0);
	
	memset(&servAddr, '\0', sizeof(servAddr));
	servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(5052);
    servAddr.sin_addr.s_addr = INADDR_ANY;

	bind(client_sock, (struct sockaddr*)&servAddr, sizeof(servAddr));
	addr_size = sizeof(newAddr);

	while(1)
    {
		int f_recv_size = recvfrom(client_sock, &frame_recv, sizeof(Frame), 0, (struct sockaddr*)&newAddr, &addr_size);//socket ,add buffer , size , flag , socket add , socket size
		if (f_recv_size > 0 && frame_recv.frame_kind == 1 && frame_recv.frame_no == frame_id)
        {
			printf("Frame Received: %s\n", frame_recv.packet.data);
			
			frame_send.frame_no = 0;
			frame_send.frame_kind = 0;
			frame_send.ack = frame_recv.frame_no + 1;
			sendto(client_sock, &frame_send, sizeof(frame_send), 0, (struct sockaddr*)&newAddr, addr_size);
			printf("Acknowledgement Send\n");
		}
        else
        {
			printf("Frame Not Received\n");
		}
		frame_id++;	
	}
	
	close(client_sock);
	return 0;
}