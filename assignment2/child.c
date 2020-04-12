#include <unistd.h> 
#include <stdio.h> 
#include <sys/socket.h> 
#include <stdlib.h> 
#include <netinet/in.h> 
#include <string.h> 
#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

int main(int argc, char const *argv[],char const *envp[]) 
{   
    int sent_socket, valread;
    char buffer[1024] = {0}; 
    uid_t uid = 65534;
    char *hello = "Hello from server"; 
    
    sent_socket = atoi(argv[1]);
    if(setuid(uid)<0){
        printf("Error in set uid\n");
        exit(EXIT_FAILURE);
    }

        valread = read( sent_socket , buffer, 1024); 
        printf("%s\n",buffer ); 
        send(sent_socket , hello , strlen(hello) , 0 ); 
        printf("Hello message sent\n"); 
    
    return 0;
}