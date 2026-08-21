#include <stdio.h>
#include <sched.h>
const unsigned long startmaskid = 0x99ul;
struct exeprocess
{
    struct mm_struct *mm;
    pid_t exeid;
    pid_t pid;
    pid_t tgid;
    unsigned int flags;
    unsigned int exeflags;
};

 void *__openprocexe__(int *addrprocexe){
    printf("%d \n ",*addrprocexe);
    return addrprocexe;
}
 
 void *__closeprocexe__(int *addrprocexe){
    printf("%d \n",*addrprocexe);
    return addrprocexe;
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
      one.pid = 5;
      
}