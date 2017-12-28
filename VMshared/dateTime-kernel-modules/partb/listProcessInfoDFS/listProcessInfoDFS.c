#include<linux/kernel.h>



long listProcessInfoDFSHelper(struct task_struct *current_task){

	struct task_struct *next_task;
	struct list_head *list;

	printk(
		      "Process: %s\n \
		       PID_Number: %ld\n \
		       Process State: %ld\n \
		       Priority: %ld\n \
		       RT_Priority: %ld\n \
		       Static Priority: %ld\n \
		       Normal Priority: %ld\n", \
		       current_task->comm, \
		       (long)task_pid_nr(current_task), \
		       (long)current_task->state, \
		       (long)current_task->prio, \
		       (long)current_task->rt_priority, \
		       (long)current_task->static_prio, \
		       (long)current_task->normal_prio \
	    );
	    if(current_task->parent){
	    	printk("Parent Process: %s\nPID_Number: %ld\n",current_task->parent->comm, (long)task_pid_nr(current_task->parent));
	    }
	    printk("\n\n");
	

	list_for_each(list, &current_task->children){
		next_task = list_entry(list, struct task_struct, sibling);

	    listProcessInfoDFSHelper(next_task);
	}
	return 0;
}

asmlinkage long sys_listProcessInfoDFS(void){
	return listProcessInfoDFSHelper(&init_task);
}
