#include <stdio.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <iostream>

using namespace std;


int main(){
    
    sockaddr_in serv_addr;

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(3490);
    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);
    connect(sock_fd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

    

}
