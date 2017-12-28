#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    char rdbuff[80];
    char ackbuff[10];
    
    char* printerPipe = "/tmp/printpipe";
    char* ackPipe2 = "/tmp/ackpipe2";
    char* notifierPipe = "/tmp/notifypipe";
    
    int fdPrint;
    int fdAck;
    int fdNotify;
    
    //open data pipe
    if((fdPrint = open(printerPipe, O_RDONLY)) < 0){
        perror("opening1");
    }else{
        printf("printerPipe: ok\n");
    }
    //open ackPipe
    if((fdAck = open(ackPipe2, O_WRONLY)) < 0){
        perror("opening2");
    }else{
        printf("ackPipe2: ok\n");
    }
    if((fdNotify = open(notifierPipe, O_WRONLY)) < 0){
        perror("opening3");
    }else{
        printf("notifierPipe: ok\n");
    }
    
    FILE* outputFile;
    
    if((outputFile = fopen("output.txt", "a")) < 0){
        perror("opening file");
    }else{
        printf("file: ok\n");
    }
    
    memset(rdbuff, 0, sizeof(rdbuff));
    memset(ackbuff, 0, sizeof(ackbuff));
    while(1){
        read(fdPrint, rdbuff, sizeof(rdbuff));
        if(rdbuff[0]=='\0'){
            //printf("out");
            break;
        }
        //printf("got it");
        
        //fputs(rdbuff, outputFile);
        write(fdAck, rdbuff, sizeof(10));
        fputs(rdbuff, outputFile);
        memset(rdbuff, 0, sizeof(rdbuff));
        memset(ackbuff, 0, sizeof(ackbuff));
        
    }
    //printf("%s", rdbuff);
    
    
    fputs(rdbuff, outputFile);
    memset(rdbuff, 0, sizeof(rdbuff));
    memset(ackbuff, 0, sizeof(ackbuff));
    
    fclose(outputFile);
    
    write(fdNotify, "ack_finish", strlen("ack_finish"));
    
    close(fdPrint);
    close(fdAck);
    close(fdNotify);
}