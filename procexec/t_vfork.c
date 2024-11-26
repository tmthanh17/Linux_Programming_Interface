/*
vfork() function
No duplication of virtual memory pages or page tables is done for the child
process. Instead, the child shares the parent’s memory until it either performs
a successful exec() or calls _exit() to terminate.

Execution of the parent process is suspended until the child has performed an
exec() or _exit().

The child is guaranteed to be scheduled for the CPU before the parent
*/

#include "tlpi_hdr.h"
int main(int argc, char *argv[])
{
    int istack = 222;
    switch (vfork())
    {
        case -1:
            errExit("vfork");
        case 0:
            sleep(3);     //Even though child slept, parent was not scheduled
            write(STDOUT_FILENO, "Child executing\n", 16);
            istack *= 3;
            _exit(EXIT_SUCCESS);
        default:
            write(STDOUT_FILENO, "Parent executing\n", 17);
            printf("istack=%d\n", istack);
            exit(EXIT_SUCCESS);
    }
}