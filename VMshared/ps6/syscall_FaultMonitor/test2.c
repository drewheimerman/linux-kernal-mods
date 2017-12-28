#include <stdio.h>
#include <stdlib.h>
#include <sys/syscall.h>
#include <unistd.h>
//#include <time.h>
#include <sched.h>
//#include <pid.h>
#define __NR_list_64 329  //64 bit
//#define __NR_list_32 377 //32 bit

static inline long mysys_faultMonitor(void* p_list) { return syscall(__NR_list_64, p_list); }

struct pid_list{
	pid_t pid;
	long int sys_time;
	long int usr_time;
	long int min_flt;
	long int maj_flt;
	long int hiwater_rss;
	long int rss;
	long int accumulated_rss;
	long int vm_size;
	long int accumulated_vm;
	long int page_count;
	struct pid_list* next_pid;
};

int main(int argc, char**argv)
{  

        struct pid_list *p1 = (struct pid_list *)malloc(sizeof(struct pid_list));
	 struct pid_list *p2 = (struct pid_list *)malloc(sizeof(struct pid_list));
	struct pid_list *p3 = (struct pid_list *)malloc(sizeof(struct pid_list));
	struct pid_list *p4 = (struct pid_list *)malloc(sizeof(struct pid_list));
	struct pid_list *p5 = (struct pid_list *)malloc(sizeof(struct pid_list));
	struct pid_list *p6 = (struct pid_list *)malloc(sizeof(struct pid_list));	
	struct pid_list *p7 = (struct pid_list *)malloc(sizeof(struct pid_list));	
	struct pid_list *p8 = (struct pid_list *)malloc(sizeof(struct pid_list));	
	struct pid_list *p9 = (struct pid_list *)malloc(sizeof(struct pid_list));	
	struct pid_list *p10 = (struct pid_list *)malloc(sizeof(struct pid_list));	

	//printf("%d", strtol(argv[1]));
	//printf("%d", (int)*argv[10]);
	p1->pid = atoi(argv[1]);
	p2->pid = atoi(argv[2]);
	p3->pid = atoi(argv[3]);
	p4->pid = atoi(argv[4]);
	p5->pid = atoi(argv[5]);
	p6->pid = atoi(argv[6]);
	p7->pid = atoi(argv[7]);
	p8->pid = atoi(argv[8]);
	p9->pid = atoi(argv[9]);
	p10->pid = atoi(argv[10]);

	p1->next_pid = p2;
p2->next_pid = p3;
p3->next_pid = p4;
p4->next_pid = p5;
p5->next_pid = p6;
p6->next_pid = p7;
p7->next_pid = p8;
p8->next_pid = p9;
p9->next_pid = p10;
p10->next_pid = NULL;

    printf("Invoking system call");
//    long int ret_status = syscall(377,NULL); // 377 is the syscall number 32 bit 
//    long int ret_status = syscall(377); // 377 is the syscall number 32 bit 
//    long int ret_status = syscall(326,NULL); // 326 is the syscall number 64 bit 
//    long int ret_status = syscall(326); // 326 is the syscall number 64 bit 
    long int ret_status =  mysys_faultMonitor(p1);

printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p1->pid, p1->sys_time, p1->usr_time,p1->min_flt,p1->maj_flt,p1->hiwater_rss, p1->rss,p1->accumulated_rss,p1->vm_size,p1->accumulated_vm,p1->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p2->pid, p2->sys_time, p2->usr_time,p2->min_flt,p2->maj_flt,p2->hiwater_rss, p2->rss,p2->accumulated_rss,p2->vm_size,p2->accumulated_vm,p2->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p3->pid, p3->sys_time, p3->usr_time,p3->min_flt,p3->maj_flt,p3->hiwater_rss, p3->rss,p3->accumulated_rss,p3->vm_size,p3->accumulated_vm,p3->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p4->pid, p4->sys_time, p4->usr_time,p4->min_flt,p4->maj_flt,p4->hiwater_rss, p4->rss,p4->accumulated_rss,p4->vm_size,p4->accumulated_vm,p4->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p5->pid, p5->sys_time, p5->usr_time,p5->min_flt,p5->maj_flt,p5->hiwater_rss, p5->rss,p5->accumulated_rss,p5->vm_size,p5->accumulated_vm,p5->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p6->pid, p6->sys_time, p6->usr_time,p6->min_flt,p6->maj_flt,p6->hiwater_rss, p6->rss,p6->accumulated_rss,p6->vm_size,p6->accumulated_vm,p6->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p7->pid, p7->sys_time, p7->usr_time,p7->min_flt,p7->maj_flt,p7->hiwater_rss, p7->rss,p7->accumulated_rss,p7->vm_size,p7->accumulated_vm,p7->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p8->pid, p8->sys_time, p8->usr_time,p8->min_flt,p8->maj_flt,p8->hiwater_rss, p8->rss,p8->accumulated_rss,p8->vm_size,p8->accumulated_vm,p8->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p9->pid, p9->sys_time, p9->usr_time,p9->min_flt,p9->maj_flt,p9->hiwater_rss, p9->rss,p9->accumulated_rss,p9->vm_size,p9->accumulated_vm,p9->page_count);
printf("\nPID: %d\nsys_time:%ld\nusr_time:%ld\nmin_flt:%ld\nmaj_flt:%ld\nhiwater_rss: %ld\nrss:%ld\naccumulated rss:\%ld\nvm_size:%ld\naccumulated vm: %ld\npage_count:%ld\n", p10->pid, p10->sys_time, p10->usr_time,p10->min_flt,p10->maj_flt,p10->hiwater_rss,p10->rss, p10->accumulated_rss,p10->vm_size,p10->accumulated_vm,p10->page_count);



    if(ret_status == 0) {
        printf("System call executed correctly. Use 'dmesg' to check kernel prints to verify against information passed to user.\n\n");
}
    else {
         printf("System call did not execute as expected %ld\n",ret_status);
     }

	free(p1);
	free(p2);
free(p3);
free(p4);
free(p5);
free(p6);
free(p7);
free(p8);
free(p9);
free(p10);
     return 0;
}
