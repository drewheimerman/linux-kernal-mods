#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    //signal(SIGPIPE, SIG_IGN);
    
    char rdbuff[80];
    char ackbuff[80];
    char wrbuff[80];
    
    char* modifierPipe = "/tmp/modpipe";
    char* ackPipe = "/tmp/ackpipe1";
    char* printerPipe = "/tmp/printpipe";
    char* ackPipe2 = "/tmp/ackpipe2";
    
    
    int fdMod;
    int fdAck1;
    int fdPrint;
    int fdAck2;
    
    //open data pipe
    if((fdMod = open(modifierPipe, O_RDONLY)) < 0){
        perror("opening");
    }else{
        printf("modifierPipe: ok\n");
    }
    
    if((fdAck1 = open(ackPipe, O_WRONLY)) < 0){
        perror("opening");
    }else{
        printf("ackPipe: ok\n");
    }
    
    if((fdPrint = open(printerPipe, O_WRONLY)) < 0){
        perror("opening");
    }else{
        printf("printerPipe: ok\n");
    }
    
    if((fdAck2 = open(ackPipe2, O_RDONLY)) < 0){
        perror("opening");
    }else{
        printf("ackPipe2: ok\n");
    }
    
    memset(rdbuff, 0, sizeof(rdbuff));
    memset(ackbuff, 0, sizeof(ackbuff));
    
    while(1){
        read(fdMod, rdbuff, sizeof(rdbuff));
        if(rdbuff[0]=='\0'){
            //printf("out");
            break;
        }
        write(fdAck1, "ack\0", strlen("ack\0"));
        
        //Change case
        for(int i =  0; i < 80; i++){
            if(rdbuff[i] == 0){
                break;
            }
            char c = rdbuff[i];
            if(c >= 'a' && c <= 'z'){
                rdbuff[i] = c-32;
            }else if(c >= 'A' && c <= 'Z'){
                rdbuff[i] = c+32;
            }
        }
        //printf("%s\n", rdbuff);
        
        write(fdPrint, rdbuff, sizeof(rdbuff));
        read(fdAck2, ackbuff, sizeof(ackbuff));
        //printf("%s\n", ackbuff);
        //printf("%s\n", rdbuff);
        
        memset(rdbuff, 0, sizeof(rdbuff));
        memset(ackbuff, 0, sizeof(ackbuff));
    }
        
    close(fdMod);
    close(fdAck1);
    close(fdPrint);
    close(fdAck2);
}