# Chat Application 

A basic chat application having client-server architecture, developed using multi-threaded socket programming.

### **Overview**

- Single multi-threaded server to handle multiple clients.
- A client can talk to another client during a session if the requested client is free.
- All messages are sent through TCP socket.

### **Setup and use locally**


1. Compile the `server.cpp` and `client.cpp` files

```
g++ server.cpp -o server
g++ client.cpp -o client 
```

2. Run the server

```
./server <port_no> // Provide the Port Number to bind the socket to this Port. 
```

5. Run the clients


```
./client <host_ip> <port_no>
```


### **Commands Supported**
- GET - lists all the clients and their status.
- CONNECT $id$ - connects the client with other client with $id$
- #GOODBYE# - disconnects the Client with connected client.
- #CLOSE# - disconects the client from the server
