#include <errno.h>
#include <stdio.h>
#include <sys/sem.h>
#include <unistd.h>

union semun {
    int val;
    struct semid_ds* buf;
    unsigned short* array;
};

struct Semaphore {
    int sem_id;
    union semun sem_union;
};

int init(struct Semaphore* sem, key_t key);
int wait(struct Semaphore* sem);
int post(struct Semaphore* sem);
int destroy(struct Semaphore* sem);

int main() {
    struct Semaphore sem;

    int ret = init(&sem, 0x5005);
    if (ret == -1) {
        printf("init failed...\n");
        return -1;
    }
    printf("init successully...\n");

    ret = wait(&sem);
    if (ret == -1) {
        printf("wait failed...\n");
        return -1;
    }
    printf("wait successully...\n");

    sleep(50);

    ret = post(&sem);
    if (ret == -1) {
        printf("post failed...\n");
        return -1;
    }
    printf("post successully...\n");

    ret = destroy(&sem);
    if (ret == -1) {
        printf("destroy failed...\n");
        return -1;
    }
    printf("destroy successully...\n");

    return 0;
}

int init(struct Semaphore* sem, key_t key) {
    int* sem_id = &sem->sem_id;
    *sem_id = semget(key, 1, 0640);
    if (*sem_id == -1) {
        if (errno == ENOENT) {
            *sem_id = semget(key, 1, 0640|IPC_CREAT);
            if (*sem_id == -1) {
                perror("semget create");
                return -1;
            }
            union semun sem_union;
            sem_union.val = 1;
            int ret = semctl(*sem_id, 0, SETVAL, sem_union);
            if (ret < 0) {
                perror("semctl");
                return -1;
            }
        } else {
            perror("semget not create");
            return -1;
        }
    }
    
    return 0;
}

int wait(struct Semaphore* sem) {}
int post(struct Semaphore* sem) {}
int destroy(struct Semaphore* sem) {}