#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(){
    
    sockaddr_in address;
    // socklen_t addrlen;
    socklen_t addrlen = sizeof(address);
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    address.sin_family = AF_INET;
    address.sin_port = htons(3490);
    address.sin_addr.s_addr = INADDR_ANY;
    bind(sock_fd,(struct sockaddr*)&address,sizeof(address));
    listen(sock_fd,3);
    int newfd = accept(sock_fd,(struct sockaddr*)&address, &addrlen);
    

    cout << "Hello\n";
    char msg[200] = "Akshat is here!";
    int len, bytes_sent;
    len = strlen(msg);
    send(newfd, msg, len, 0);

    close(sock_fd);

}
