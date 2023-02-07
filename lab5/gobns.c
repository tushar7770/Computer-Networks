#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define W 5
#define P1 50
#define P2 10

// function to convert integer to string
void int2str(int n, char *s)
{
    int i = 0;
    while (n > 0)
    {
        s[i++] = n % 10 + '0';
        n /= 10;
    }
    s[i] = '\0';
    int j = 0;
    char temp;
    while (j < i / 2)
    {
        temp = s[j];
        s[j] = s[i - j - 1];
        s[i - j - 1] = temp;
        j++;
    }
}

int main()
{
    // variables
    int server_socketFd, client_socketFd;
    struct sockaddr_in server_addr, client_addr;
    int client_addr_size;

    // socket creation
    server_socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socketFd == -1)
    {
        printf("socket creation failed\n");
        exit(1);
    }
    else
        printf("socket : %d\n", server_socketFd);

    // bind
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = 8080;
    if (bind(server_socketFd, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0)
    {
        printf("bind failed\n");
        exit(1);
    }
    else
        printf("bound\n");

    // listen
    if (listen(server_socketFd, 1) != 0)
    {
        printf("listen failed\n");
        exit(1);
    }
    else
        printf("listening...\n");

    // accept
    bzero(&client_addr, sizeof(client_addr));
    client_socketFd = accept(server_socketFd, (struct sockaddr *)&client_addr, &client_addr_size);
    if (client_socketFd == -1)
    {
        printf("failed to accept\n");
        exit(1);
    }
    else
        printf("accepted\n");

    // read/write
    int i, j, c = 1, frame;
    char a[10], b[10];
    srand(time(NULL));
    strcpy(b, "Time Out ");
    read(client_socketFd, a, sizeof(a));
    frame = atoi(a);
    while (1)
    {
        for (i = 0; i < W; i++)
        {
            read(client_socketFd, a, sizeof(a));
            if (strcmp(a, b) == 0)
                break;
        }
        i = 0;
        while (i < W)
        {
            j = rand() % P1;
            if (j < P2)
            {
                write(client_socketFd, b, sizeof(b));
                break;
            }
            else
            {
                int2str(c, a);
                if (c <= frame)
                {
                    printf("\nFrame %s Received ", a);
                    write(client_socketFd, a, sizeof(a));
                }
                else
                {
                    break;
                }
                c++;
            }
            if (c > frame)
            {
                break;
            }
            i++;
        }
        if (c > frame)
        {
            break;
        }
    }

    // close
    close(client_socketFd);
    printf("\nclient socket closed\n");
    close(server_socketFd);
    printf("server socket closed\n");
    return 0;
}

// string to integer
