#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    signal(SIGPIPE, SIG_IGN);
    char rdbuff[80];
    char ackbuff[10];
    char* modifierPipe = "/tmp/modpipe";
    char* ackPipe = "/tmp/ackpipe1";
    
    int fdMod;
    int fdAck;
    
    //open data pipe
    if((fdMod = open(modifierPipe, O_WRONLY)) < 0){
        perror("opening");
    }else{
        printf("modifierPipe: ok\n");
    }
    //open ackPipe
    if((fdAck = open(ackPipe, O_RDONLY)) < 0){
        perror("opening");
    }else{
        printf("ackPipe: ok\n");
    }
    
    memset(rdbuff, 0, sizeof(rdbuff));
    memset(ackbuff, 0, sizeof(ackbuff));
    
    while( fgets(rdbuff, sizeof(rdbuff), stdin) != NULL){
        write(fdMod, rdbuff, strlen(rdbuff));
        read(fdAck, ackbuff, sizeof(ackbuff));
        //printf("%s\n", ackbuff);
        
        memset(rdbuff, 0, sizeof(rdbuff));
        memset(ackbuff, 0, sizeof(ackbuff));
    }
    
    close(fdMod);
    close(fdAck);
}