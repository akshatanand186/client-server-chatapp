#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

using namespace std;

#define MYPORT "3490"

int main()
{
    int sockfd, new_fd;
    struct sockaddr_storage their_addr;
    socklen_t addr_size;
    struct addrinfo hints, *res;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    // hints.ai_flags = AI_PASSIVE;

    getaddrinfo("127.0.0.1", MYPORT, &hints, &res);

    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    bind(sockfd, res->ai_addr, res->ai_addrlen);
    listen(sockfd, 10);

    addr_size = sizeof their_addr;
    new_fd = accept(sockfd, (struct sockaddr *)&their_addr, &addr_size);
    char str[] = "hey there how u";
    send(new_fd, str, sizeof(str), 0);
    char buf[1000];

    while (1)
    {
        int numbytes = recv(new_fd, buf, 1000, 0);
        if (numbytes == 0)
        {
            cout << "Disconnected\n";
            close(new_fd);
        }
        for(int i=0;i<numbytes;i++){
            cout << buf[i] << " ";
        }
        cout << endl;
    }
    close(sockfd);
}