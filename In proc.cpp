In proc.c-

int getTotalMemoryConsumed()
{
struct proc *p; long long total=0;
acquire(&ptable.lock);
for(p = ptable.proc; p < &ptable.proc[NPROC]; p++){ total+=(p->sz);
}
release(&ptable.lock); return total;
}

In sysproc.c-

int sys_getTotalMemoryConsumed(){ return getTotalMemoryConsumed();
}

Added definition of these function to appropriate places Test.c-
#include "types.h" #include "stat.h" #include "user.h"

int main(void)
{
printf(1, "Process memory is %d\n", getprocmemory()/1024);
printf(1, "Process memory is %d\n", getTotalMemoryConsumed()/1024); exit();
}
