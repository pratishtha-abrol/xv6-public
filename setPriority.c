#include "types.h"
#include "stat.h"
#include "user.h"

int main (int argc, char *argv[])
{
    int pid, pr;
    int a;
    if(argc != 3) {
        printf(1, "Usage: setPriority <new_priority> <pid>\n");
        exit();
    }
    else {
        pid = atoi(argv[2]);
        pr = atoi(argv[1]);
        a = set_priority(pr, pid);
        printf(1, "old priority=%d\n", a);
        exit();
    }
}