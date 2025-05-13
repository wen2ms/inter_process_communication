#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
    int fd = open("foo.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
        exit(1);
    }

    // len >= off_set + operation_bytes
    // int* ptr = mmap(NULL, 5, PROT_WRITE, MAP_SHARED, fd, 0);

    // const char* str = "ABCD"; 
    // memcpy(ptr, str, 4);

    // const char* str = "ABCD"; 
    // memcpy(((char*)ptr) + 1, str, 4);

    char* ptr = mmap(NULL, 5, PROT_WRITE, MAP_SHARED, fd, 0);
    ptr[0] = 'A';
    ptr[1] = 'B';
    ptr[2] = 'C';
    ptr[3] = 'D';

    munmap(ptr, 5);
    close(fd);

    return 0;
}