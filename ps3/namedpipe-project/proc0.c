#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(){
    char* modifierPipe = "/tmp/modpipe";
    char* ackPipe1 = "/tmp/ackpipe1";
    char* printerPipe = "/tmp/printpipe";
    char* ackPipe2 = "/tmp/ackpipe2";
    char* notifierPipe = "/tmp/notifypipe";
    
    int res;
    res = mkfifo(modifierPipe, 0666);
    if(res<0){
        perror("failure to mkfifo: 1");
    }
    res = mkfifo(ackPipe1, 0666);
    if(res<0){
        perror("failure to mkfifo: 4");
    }
    res = mkfifo(ackPipe2, 0666);
    if(res<0){
        perror("failure to mkfifo: 5");
    }
    res = mkfifo(printerPipe, 0666);
    if(res<0){
        perror("failure to mkfifo: 2");
    }
    res = mkfifo(notifierPipe, 0666);
    if(res<0){
        perror("failure to mkfifo: 3");
    }
    
    char ackbuff[10];
    int fd;
    
    if((fd = open(notifierPipe, O_RDONLY)) < 0){
        perror("opening3");
    }else{
        printf("ackPipe: ok\n");
    }
    read(fd, ackbuff, sizeof(ackbuff));
    
    close(fd);
    
    unlink(modifierPipe);
    unlink(ackPipe1);
    unlink(ackPipe2);
    unlink(printerPipe);
    unlink(notifierPipe);
}