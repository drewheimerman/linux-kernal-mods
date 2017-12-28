#include <linux/module.h>
#include <linux/time.h>
#include <linux/uaccess.h>
#include <linux/slab.h>

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Andrew Heimerman");
MODULE_DESCRIPTION("Returns the system date and time.");

struct date_time{
	//struct tm tstamp;
	int hour;
	int min;
	int sec;
	int day;
	int month;
	int year;
};
asmlinkage long sys_dateTime(void* user_dt){
	struct date_time *dt;
	struct tm tstamp;
	struct timeval c;
	int res;
	
	dt = (struct date_time*)kmalloc(sizeof(struct date_time), GFP_KERNEL);
	do_gettimeofday(&c);
	time_to_tm(c.tv_sec, 0, &tstamp);
	dt->hour = tstamp.tm_hour;
	dt->min = tstamp.tm_min;
	dt->sec = tstamp.tm_sec;
	dt->day = tstamp.tm_mday;
	dt->month = tstamp.tm_mon+1;
	dt->year = tstamp.tm_year+1900;
	printk("System call 'dateTime' called:\n");

	printk("Time: %02d:%02d:%02d\nDay: %02d\nMonth: %02d\nYear: %d\n", dt->hour, dt->min, dt->sec, dt->day, dt->month,dt->year);
	res = copy_to_user(user_dt, dt, sizeof(struct date_time));
	if(res>0){
		printk("COPY DATETIME TO USER FAILED.");
		return 1;
	}
	kfree(dt);
	return 0;
}