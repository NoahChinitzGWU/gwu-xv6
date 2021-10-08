#include "types.h"
#include "user.h"
#include "pstat.h"

int
main(void)
{
    int pid;

    // Parent forks two children
    for (int i = 0; i < 2; i++) {
        pid = fork();
        if (pid < 0) {
            exit();
        } else if (pid == 0) {
            // Parent's child fork two children
            for (int j = 0; j < 2; j++) {
                pid = fork();
                if (pid < 0) {
                    exit();
                } else if (pid == 0) {
                    sleep(100);
                    exit();
                }
            }
            wait();
            wait();
            exit();
        }
    }
    sleep(10);
    if (pid > 0) {
        ps();
    }
    while (wait() != -1);
    exit();  
}