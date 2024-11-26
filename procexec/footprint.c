#include <sys/wait.h>
#include "tlpi_hdr.h"
/*
   This program contains a function that (artificially) consumes a large
   amount of memory. To avoid changing the process's memory footprint, the
   program creates a child process that calls the function. When the child
   terminates, all of its memory is freed, and the memory consumption of
   the parent is left unaffected.
*/
static int func(int arg)
{
    int j;
    for (j = 0; j < 0x100; j++)
        if (malloc(0x80000) == NULL)
            errExit("malloc");
    printf("Program break in child: %10p\n", sbrk(0)); //sbrk(0): This is a function used to retrieve the current address of the "program break" — the boundary between the allocated heap area and the unallocated memory.
    return arg;
}

int main(int argc, char *argv[])
{
    int arg = (argc > 1) ? getInt(argv[1], 0, "arg") : 0;
    pid_t childPid;
    int status;
    setbuf(stdout, NULL);
    printf("Program break in parent: %10p\n", sbrk(0));
    childPid = fork();
    if (childPid == -1)
        errExit("fork");
    if (childPid == 0)
        exit(func(arg));
    if (wait(&status) == -1)
        errExit("wait");
    printf("Program break in parent: %10p\n", sbrk(0));
    printf("Status = %d %d\n", status, WEXITSTATUS(status));   //WEXITSTATUS(status) get value return from exit(func(arg)) in child process. This macro extracts the lower 8 bits of status,
    exit(EXIT_SUCCESS);
}