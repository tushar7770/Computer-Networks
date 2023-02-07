#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <unistd.h>

#define W 5

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
    int socketFd;
    struct sockaddr_in server_addr;

    // socket creation
    socketFd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFd == -1)
    {
        printf("socket creation failed\n");
        exit(1);
    }
    else
        printf("socket : %d\n", socketFd);

    // connect
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = 8080;
    if (connect(socketFd, (struct sockaddr *)&server_addr, sizeof(server_addr)) != 0)
    {
        printf("failed to connect\n");
        exit(1);
    }
    else
        printf("connected\n");

    // read/write
    int frame, wl, c = 1, x, i = 0, j, p = 0, e = 0;
    char a[10], b[10];
    printf("\nEnter the number of Frames: ");
    scanf("%d", &frame);
    int2str(frame, a);
    write(socketFd, a, sizeof(a));
    strcpy(b, "Time Out ");
    while (1)
    {
        for (i = 0; i < W; i++)
        {
            int2str(c, a);
            write(socketFd, a, sizeof(a));
            if (c <= frame)
            {
                printf("\nFrame %d Sent", c);
                c++;
            }
        }
        i = 0;
        wl = W;
        while (i < W)
        {
            read(socketFd, a, sizeof(a));
            p = atoi(a);
            if (strcmp(a, b) == 0)
            {
                e = c - wl;
                if (e < frame)
                {
                    printf("\nTime Out, Resent Frame %d onwards", e);
                }
                break;
            }
            else
            {
                if (p <= frame)
                {
                    printf("\nFrame %s Acknowledged", a);
                    wl--;
                }
                else
                {
                    break;
                }
            }
            if (p > frame)
            {
                break;
            }
            i++;
        }
        if (wl == 0 && c > frame)
        {
            write(socketFd, b, sizeof(b));
            break;
        }
        else
        {
            c = c - wl;
            wl = W;
        }
    }

    // close
    close(socketFd);
    printf("\nsocket closed\n");
    return 0;
}
