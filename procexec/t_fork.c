/* Demonstrate the use of fork(), showing that parent and child
   get separate copies of stack and data segments.*/

#include "tlpi_hdr.h"
static int idata = 111;
int main(int argc, char *argv[])
{
    int istack = 222;
    pid_t childPid;
    switch (childPid = fork())
    {
        case -1:
        /* Handle error */
            errExit("fork");
        case 0:
        /* Child process */
            idata *= 3;
            istack *=3;
        default:
        /* Parent process */
            sleep(3);
            break;
    }
    /* Both parent and child come here */
    printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(), (childPid == 0) ? "(child) " : "(parent)", idata, istack);
    exit(EXIT_SUCCESS);
}