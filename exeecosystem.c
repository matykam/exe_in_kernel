/*Эта программа работает как прослойка между 
*подсистемой процессов ядра линукс и 
*экосистемы exe процессов*/

#include <stdio.h>
#include <sched.h>
#include <linux/printk.h>
#include <linux/kernel.h>
const unsigned long startmaskid = 0x99999ul;
const struct task_struct *start = &init_task;


struct exeprocess 
/* структура используется для изолированной работы с процессами в которых исполняются exe файлы,
*с помощью этой структуры экосистема exe может обращаться 
*только к процессам которые были запущены внутри нее*/
{
    struct task_struct *tasks;
    pid_t exeid;
    pid_t pid;
    pid_t tgid;
    unsigned int exeflags;
    /* exeflags: 00000001-read,00000010-write,00000011-r/w,10000000-systemprogramm */
    struct exe_list_head{
       struct exeprocess *next;
       struct exeprocess *prev;
        }
    
};
 struct exeprocess __lowexe__(){
     struct exeprocess einit;
     einit.exeid = einit.pid + startmaskid;
     einit.exeflags = 128; /* flag-10000000*/
     printk(KERN_NOTICE "процесс initexe успешно был запущен/the process has been successfully launched");
 }
 
 void exespace(){
    
 }

 void *__openprocexe__(int *addrprocexe){
    printf("%d \n ",*addrprocexe);
    return addrprocexe;
}             
 
 void *__closeprocexe__(int *addrprocexe){
    printf("%d \n",*addrprocexe);
    return addrprocexe;
}

void __startpoint__(char *path,unsigned long size,) {
    printk(KERN_NOTICE "запуск точки входа exe_ecosystem");
   __lowexe__();
}

typedef void*(call)(int*);
call* execall[] = {__openprocexe__,__closeprocexe__};
int main() {
       int prim = 9;
       int *addr;
       addr = &prim;
      int *a;
      a = execall[0](addr);
      printf("%d \n",*a);
      struct exeprocess one;
      one.pid = 8;
}