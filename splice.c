#define _GNU_SOURCE
#include <sys/uio.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


int main(){
    ssize_t nread; 
    unsigned long nr_segs = 200;

    nread = splice(STDIN_FILENO, NULL, STDOUT_FILENO,
            NULL, INT_MAX, SPLICE_F_MOVE);

    if (-1 == nread) {
        printf("errno = %d\n", errno);
        perror("splice");
        return 1;
    }
    return 0;
}