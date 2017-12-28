//#define _GNU_SOURCE 
#include <stdio.h>
//#include <linux/kernel.h>
//#include <linux/sched.h>
#include <sys/syscall.h>
#include <unistd.h>
#define __NR_list_64 327  //64 bit
#define __NR_list_32 377 //32 bit
static inline long mysys_helloworld(void) { return syscall(__NR_list_64, NULL); }

int main(int argc, char**argv)
{  
    printf("Invoking 'listProcessInfoDFS' system call");
//    long int ret_status = syscall(377,NULL); // 377 is the syscall number 32 bit 
//    long int ret_status = syscall(377); // 377 is the syscall number 32 bit 
//    long int ret_status = syscall(326,NULL); // 326 is the syscall number 64 bit 
//    long int ret_status = syscall(326); // 326 is the syscall number 64 bit 
	
    long int ret_status =  mysys_helloworld();
    if(ret_status == 0) 
         printf("System call 'listProcessInfoDFS' executed correctly. Use dmesg to check processInfo\n");
    
    else 
         printf("System call 'listProcessInfoDFS' did not execute as expected %d\n",ret_status);
          
     return 0;
}
