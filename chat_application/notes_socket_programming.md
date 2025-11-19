/*
socket programming basics --> 
    it is a way for how application communicate on internet
    socket1 (node1, application layer1) <--> socket2 (node2, application layer2)



server machine                                                                                   client machine
socket(domain {ipv4,ipv6}, type {sock_dgram, sock_stream}, protocol {0})                             socket()
bind()  {socket address association { ip_add+port_num} }
listen() {passive mode, waiting for next command, backlog{pending request queue}}      <---         connect()  {server_socket_add}
accept() {communication establised}
send()                                                                                 --->         recieve()
revieve()                                                                              <---         send()
close()                                                                                             close()


Windows           -> macOS/Linux
winsock2.h        -> sys/socket.h
ws2tcpip.h        -> netinet/in.h, arpa/inet.h
closesocket()     -> close()
SOCKET            -> int
WSAGetLastError() -> errno
WSAStartup()      -> (not needed)


Winsock is not active by default.
    implements sockets as a separate subsystem

macOS uses POSIX/BSD sockets, where:
    Sockets are part of the OS kernel
    The socket API is available immediately
    So macOS = no need for startup.
    

| Windows          | macOS/Linux |
| ---------------- | ----------- |
| `SOCKET`         | `int`       |
| `INVALID_SOCKET` | `-1`        |
| `closesocket()`  | `close()`   |




Blocking call
    Waits until the task is finished
    The program stops and waits
    Example: recv() waits until data arrives
    ➡ Good for simple programs
    ➡ Bad if you need to handle many clients (it freezes)

Non-blocking call
    Returns immediately, even if it can't do the task
    The program keeps running
    Example: recv() returns right away with "no data yet"
    ➡ Good for servers and fast applications
    ➡ More complex to handle





*/
