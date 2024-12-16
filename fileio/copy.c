/* 
Run command: ./copy oldfile newfile
Note : Run and read/write file in right folder
*/
#include <sys/stat.h>
#include <fcntl.h>
#include "tlpi_hdr.h"

#ifndef BUF_SIZE     /* Allow gcc -D to override definition*/
#define BUF_SIZE 1024
#endif

/*
O_CREAT: Create the file if it does not exist.
O_WRONLY: Open the file for write-only access.
O_TRUNC: If the file already exists and is successfully opened, truncate its length to 0. This effectively clears the file.


S_IRUSR (00400): Read permission for the owner of the file.
S_IWUSR (00200): Write permission for the owner of the file.
S_IRGRP (00040): Read permission for members of the file's group.
S_IWGRP (00020): Write permission for members of the file's group.
S_IROTH (00004): Read permission for others (everyone else).
S_IWOTH (00002): Write permission for others.
*/
int main(int argc, char *argv[]) 
{
    int inputFd, outputFd, openFlags;
    mode_t filePerms;
    ssize_t numRead;
    char buf[BUF_SIZE];

    if (argc != 3 || strcmp(argv[1], "--help") == 0)
        usageErr("%s old-file new-file\n", argv[0]);

    /* Open input output files */
    inputFd = open(argv[1], O_RDONLY);
    if (inputFd == -1)
        errExit("opening file %s\n", argv[1]);

    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
    outputFd  = open(argv[2], openFlags, filePerms);
    if (outputFd == -1)
        errExit("opening file %s\n", argv[2]);
    while ((numRead = read(inputFd, buf, BUF_SIZE)))
        if (write(outputFd, buf, numRead) != numRead)
            fatal("couldn't write whole buffer");
    
    if (numRead == -1)
        errExit("read");
    if (close(inputFd) == -1)
        errExit("close input");
    exit(EXIT_SUCCESS);
}