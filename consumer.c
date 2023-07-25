#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

/* 
Consume some CPU.

1. Write our PID to a file
2. Loop on this forever:
    a) chew up some CPU with a loop
    b) Print our elapsed CPU

Note: Don't leave this running.
*/

int main() {
    int i;
    int loopCounter = 1;
    clock_t startTime, endTime;
    double cpuTimeUsed;

    // Write the PID to a file
    FILE *pidFile = fopen("consumer_pid.txt", "w");
    if (pidFile == NULL) {
        perror("Error opening the PID file");
        return 1;
    }
    fprintf(pidFile, "%d", getpid());
    fclose(pidFile);

    printf("I think I can do %ld clocks per second\n", CLOCKS_PER_SEC);

    while (1) { // Infinite loop
        startTime = clock();

        for (i = 0; i < 400 * CLOCKS_PER_SEC; i++) {
            // Intentionally consume CPU time without doing anything meaningful
        }

        endTime = clock();

        cpuTimeUsed += ((double) (endTime - startTime)) / CLOCKS_PER_SEC;

        printf("Message %d: CPU Time Used: %.6f seconds.\n", loopCounter, cpuTimeUsed);
        sleep(0.5);
        loopCounter++;
    }

    return 0;
}
