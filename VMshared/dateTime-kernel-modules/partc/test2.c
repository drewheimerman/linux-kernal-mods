#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <time.h>
#define __NR_list_64 328  //64 bit
//#define __NR_list_32 377 //32 bit

static inline long mysys_dateTime(void* user_tm) { return syscall(__NR_list_64, user_tm); }

struct date_time{
	int hour;
	int min;
	int sec;
	int day;
	int month;
	int year;
};


int main(int argc, char**argv)
{  

    struct date_time *dt = (struct date_time *)malloc(sizeof(struct date_time));
    printf("Invoking 'dateTime' system call");
//    long int ret_status = syscall(377,NULL); // 377 is the syscall number 32 bit 
//    long int ret_status = syscall(377); // 377 is the syscall number 32 bit 
//    long int ret_status = syscall(326,NULL); // 326 is the syscall number 64 bit 
//    long int ret_status = syscall(326); // 326 is the syscall number 64 bit 
    long int ret_status =  mysys_dateTime(dt);
    if(ret_status == 0) {
        printf("System call 'dateTime' executed correctly. Use 'dmesg' to check kernel prints to verify against information passed to user.\n\n\
Printing received information:\n\n\
Time: %02d:%02d:%02d UTC\n\
Day:  %02d \n\
Month: %02d\n\
Year: %d\n", dt->hour, dt->min, dt->sec, dt->day, dt->month, dt->year);
}
    else {
         printf("System call 'dateTime' did not execute as expected %ld\n",ret_status);
     }

	free(dt);
     return 0;
}
