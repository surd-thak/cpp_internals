#include<iostream>
using namespace std;


#include <sys/socket.h>   // Provides core socket functions like socket(), bind(), connect(), accept(), send(), recv()
#include <arpa/inet.h>    // Provides functions for IP address conversion like inet_pton(), inet_ntoa(), and sockaddr_in
#include <unistd.h>       // Provides POSIX functions like close() used to close sockets and file descriptors




/*
Structure -->

Server Code

    0. initialize sys/socket.h library {not need in macOS} 
    1. create a socket {done}
    2. get ip and port 
    3. bind the ip/port with the socket
    4. listen to the socket
    5. accept (blocking for now)
    6. recv and send
    7. close the socket
    8. clean up 

*/




int main(){
    cout << "server_program\n";


    // step 1. create socket

    int listenSocket = socket(AF_INET, SOCK_STREAM, 0); //address family, protocol, protocol depending on stream (0 : let service provider decide)

    //everytime you create an api; you have to always check if it is perfoming as expected
    if(listenSocket == -1){
        cout << "socket creation failed\n";
        return 1;
    }

    //step 2. get ip and port 

    




    return 0;
}