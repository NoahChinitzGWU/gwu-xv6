#include "types.h"
#include "user.h"
#include "pstat.h"
/**
 * Test 3: Parent forks two children, and they each fork two children, then the original parent calls ps.
 */
int
main(void)
{
    int pid;
    // Parent forks two children
    for (int i = 0; i < 2; i++) {
        pid = fork();
        if (pid < 0) { // error
            exit();
        } else if (pid == 0) { // child
            // Parent's child forks two children
            for (int j = 0; j < 2; j++) {
                pid = fork();
                if (pid < 0) { // error
                    exit();
                } else if (pid == 0) { // child
                    sleep(200);
                    exit();
                }
            }
            wait();
            wait();
            exit();
        }
    }
    sleep(100);
    if (pid > 0) { // if we are the parent then print out the processes
        ps();
    }
    while (wait() != -1); // wait until all processes have been cleaned up
    exit();  
}