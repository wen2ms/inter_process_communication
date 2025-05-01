#include <stdio.h>
#include <sys/shm.h>
#include <unistd.h>

// ipcs -m

int main() {
    int shmid = shmget((key_t)0x5005, 1024, 0640 | IPC_CREAT);

    if (shmid == -1) {
        perror("shmget");
        return -1;
    }

    char* ptext = (char*)shmat(shmid, NULL, 0);

    printf("Before writing: %s\n", ptext);
    sprintf(ptext, "current pid: %d", getpid());
    printf("After writing: %s\n", ptext);

    // nattch: nubmer of attach
    // sleep(30);

    shmdt(ptext);

    // Remove the shared memory segment identified by shmid after the last process detaches from it.
    int ret = shmctl(shmid, IPC_RMID, NULL);
    if (ret == -1) {
        perror("shmctl");
        return -1;
    }

    return 0;
}