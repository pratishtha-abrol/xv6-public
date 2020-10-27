#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main (int argc, char *argv[])
{
    if (argc <= 1)
    {
        printf(2, "time: No command\n");
        exit();
    }
    int pid;
    int status, a, b;
    pid = fork();
    if (pid == 0)
    {
        printf(1, "Timing %s\n", argv[1]);
        exec(argv[1], argv);
        printf(2, "ecec %s failed.\n", argv[1]);
    }
    else if (pid > 0)
    {
        status = waitx(&a, &b);
        printf(1, "Wait time = %d\nRun time = %d\nwith Status %d\n", a, b, status);
        exit();
    }
    
}