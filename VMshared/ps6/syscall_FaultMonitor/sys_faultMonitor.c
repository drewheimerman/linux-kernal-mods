#include <linux/kernel.h>
//#include<linux/init.h>
#include<linux/sched.h>
#include<linux/syscalls.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/mm_types.h>


//#include <linux/slab.h>
#include <linux/pid.h>
#include <linux/pid_namespace.h>

//#include <linux/init.h>
//#include <linux/module.h>
//MODULE_LICENSE("GPL");329
//MODULE_DESCRIPTION("Module");


int get_task_info(struct task_struct* task);


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

asmlinkage long sys_faultMonitor(void* p_list){
	struct pid_list* node = (struct pid_list*)p_list;
	while(node != NULL){
		pid_t pid = node->pid;
		//struct task_struct* task = find_task_by_pid(pid);
		
		struct task_struct* task = pid_task(find_vpid(pid), PIDTYPE_PID);

		printk("PID: %d\n", pid);
		printk("task_struct: %p\n\n", task);

		//get_task_info(task);

		//struct task_struct* task;
		struct mm_struct* mm;
	
		//task = current; //get the current process task_struct
		mm = task->mm; //get the mm_struct from current task
		printk("Initializing Fault Monitor");
		
		printk("\ninit_task: %p\n", task);
		printk("\nmm: %p\n", mm);
	
	
		printk("\n Task stime: %ld\n", task->stime);
		printk("\n Task utime: %ld\n", task->utime);
		node->sys_time = task->stime;
		node->usr_time = task->utime;
	
		printk("\n Minor faults: %ld\n", task->min_flt);
		printk("\n Major faults: %ld\n", task->maj_flt);
		node->min_flt = task->min_flt;
		node->maj_flt = task->maj_flt;
	
		printk("\nmm task space: %ld\n", mm->task_size);
	
		printk("\nmm total_vm (pages mapped): %ld\n", mm->total_vm);
		node->page_count = mm->total_vm;
	
		printk("\nmm hiwater_vm: %ld\n", mm->hiwater_vm);
		node->vm_size = ((mm->total_vm)*4);
		node->hiwater_rss = mm->hiwater_rss;
		node->rss = (get_mm_rss(mm)*4); //multiplied by 4 to get it in GBs so that it equals what is given by the ps command
		printk("\nmm hiwater_rss: %ld\n", mm->hiwater_rss);
		printk("\nmm rss: %ld\n", node->rss);
		
		printk("\nmm mm_count: %ld\n", mm->mm_count);
		printk("\nmm mmap: %p\n", mm->mmap);
		printk("\nmm map_count: %d\n", mm->map_count);

		node->accumulated_rss = task->acct_rss_mem1;
		node->accumulated_vm = task->acct_vm_mem1;

		node = node->next_pid;
	}

	return (long)0;
}