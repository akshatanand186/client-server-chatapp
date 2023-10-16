#include <bits/stdc++.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>

using namespace std;

#define MYPORT "3490"
#define MAXDATASIZE 100

void *get_in_addr(struct sockaddr *sa)
{
    if (sa->sa_family == AF_INET)
    {
        return &(((struct sockaddr_in *)sa)->sin_addr);
    }

    return &(((struct sockaddr_in6 *)sa)->sin6_addr);
}

int main()
{
    int sockfd, numbytes;
    char buf[MAXDATASIZE];
    struct addrinfo hints, *servinfo, *p;
    char s[INET6_ADDRSTRLEN];
    int rv;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo("127.0.0.1", MYPORT, &hints, &servinfo);
    p = servinfo;
    sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
    connect(sockfd, p->ai_addr, p->ai_addrlen);
    inet_ntop(p->ai_family, get_in_addr((struct sockaddr *)p->ai_addr), s, sizeof s);
    printf("client: connecting to %s\n", s);
    freeaddrinfo(servinfo);

    numbytes = recv(sockfd, buf, MAXDATASIZE - 1, 0);
    buf[numbytes] = '\0';
    printf("client: received '%s'\n", buf);

    close(sockfd);
}