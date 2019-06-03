#define _GNU_SOURCE
#include <sys/uio.h>
#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <time.h>


int main(){
    ssize_t nread; 
    unsigned long nr_segs = 200;
    int fd2 = open("../../random-files/20m-files/file.txt", O_RDONLY);

    clock_t start_t, end_t, total_t;
    printf("Starting of the program, start_t = %ld\n", start_t);
	start_t = clock();
    nread = splice(fd2, NULL, STDOUT_FILENO,
            NULL, 20000000, SPLICE_F_MOVE);
    end_t = clock();
	printf("End of the big loop, end_t = %ld\n", end_t);
	
	total_t = ((double)(end_t - start_t)) / CLOCKS_PER_SEC;
	printf("Time: %f\n", (double)total_t);

    if (-1 == nread) {
        printf("errno = %d\n", errno);
        perror("splice");
        return 1;
    }
    printf("copied bytes number = %d\n", (int)nread);
    return 0;
}