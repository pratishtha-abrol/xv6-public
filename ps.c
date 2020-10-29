#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

// enum procstate { UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE };

// struct proc {
//     enum procstate state;
//     int pid;
//     int ppid;
//     char name[16];
//     int stime, etime, iotime, rtime;
//     int priority;
// };

// #define MAX 20

// int main (int argc, char *argv[])
// {
//     struct proc ptable[MAX];
//     struct proc *p;
//     int err;

//     err = getptable(10 * sizeof(struct proc), &ptable);
//     if (err != 0) printf(2, "Error getting ptable\n");

//     p = &ptable[0];
//     printf(1, " PID    PPID       STATE    CMD    \n");
//     while(p != &ptable[MAX-1] && p->state != UNUSED)
//     {
//         printf(1, " %d  %d  ", p->pid, p->ppid);
//         switch(p->state) {
//             case UNUSED:
//                 printf(1, "%s", "UNUSED");
//                 break;
//             case EMBRYO:
//                 printf(1, "%s", "EMBRYO");
//                 break;
//             case SLEEPING:
//                 printf(1, "%s", "SLEEPING");
//                 break;
//             case RUNNABLE:
//                 printf(1, "%s", "RUNNABLE");
//                 break;
//             case RUNNING:
//                 printf(1, "%s", "RUNNING");
//                 break;
//             case ZOMBIE:
//                 printf(1, "%s", "ZOMBIE");
//                 break;
//         }
//         printf(1, "    %s     \n", p->name);
//         p++;
//     }

//     exit();
// }

int main (int argc, char *argv[])
{
    if(argc != 1) {
        printf(1, "Usage: ps\n");
        exit();
    }
    else {
        getps();
        exit();
    }
}