#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <windows.h>
#include <process.h>  // for _beginthread

#define NUM_TASKS 5

// Simple dummy work (light loop)
void do_work() {
    double result = 0;
    for (int i = 1; i <= 10000000; i++) {
        result += log(i) * sin(i) * cos(i);  // math operation
    }
    
}

// ----------- Thread Task Function -----------
unsigned __stdcall my_thread(void* arg) {
    do_work();
    return 0;
}

void run_with_threads() {
    printf("\n--- Running with Threads ---\n");

    HANDLE threads[NUM_TASKS];
    clock_t start = clock();

    for (int i = 0; i < NUM_TASKS; i++) {
        threads[i] = (HANDLE)_beginthreadex(NULL, 0, my_thread, NULL, 0, NULL);
    }

    WaitForMultipleObjects(NUM_TASKS, threads, TRUE, INFINITE);
    clock_t end = clock();

    printf("Time (Threads): %.4f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
}

// ----------- Process Logic -----------
void run_with_processes() {
    printf("\n--- Running with Processes ---\n");
    clock_t start = clock();

    for (int i = 0; i < NUM_TASKS; i++) {
        system("child_basic.exe");
    }

    clock_t end = clock();
    printf("Time (Processes): %.4f sec\n", (double)(end - start) / CLOCKS_PER_SEC);
}

// ----------- Main -----------
int main() {
    printf("=== Comparing Process vs Thread (simple logic) ===\n");

    run_with_processes();
    run_with_threads();

    return 0;
}
