#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/wait.h>
#include <time.h>

#define NUM 5

void* task(void* arg) {
    sleep(1);
    return NULL;
}

void run_with_fork() {
    printf("\n🔹 Running with fork():\n");
    clock_t start = clock();
    for (int i = 0; i < NUM; i++) {
        pid_t pid = fork();
        if (pid == 0) {
            task(NULL);
            exit(0);
        } else {
            wait(NULL);
        }
    }
    clock_t end = clock();
    printf("⏱️ Time (fork): %.4f sec\n",
        (double)(end - start) / CLOCKS_PER_SEC);
}

void run_with_thread() {
    printf("\n🔸 Running with pthread:\n");
    pthread_t t[NUM];
    clock_t start = clock();
    for (int i = 0; i < NUM; i++)
        pthread_create(&t[i], NULL, task, NULL);
    for (int i = 0; i < NUM; i++)
        pthread_join(t[i], NULL);
    clock_t end = clock();
    printf("⏱️ Time (thread): %.4f sec\n",
        (double)(end - start) / CLOCKS_PER_SEC);
}

int main() {
    printf("🔍 Comparing Fork vs Thread (sleep task)\n");
    run_with_fork();
    run_with_thread();
    return 0;
}
