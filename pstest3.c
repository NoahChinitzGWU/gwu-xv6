#include "types.h"
#include "user.h"
#include "pstat.h"

int main (void) {
    int pid;

    // Parent forks two children
    for (int i = 0; i < 2; i++) {
        pid = fork();
        // Parent's child fork two children
        if (pid == 0) {
            for (int j = 0; j < 2; j++) {
                pid = fork();
                if (pid > 0) {
                    fork();
                }
            }
        }
    }

    if (pid > 0) {
        ps();
    }
    while (wait() != -1);
    exit();  
}