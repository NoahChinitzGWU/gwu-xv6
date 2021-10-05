#include "types.h"
#include "user.h"

int main (void) {
    int pid;
    pid = fork();
    if (pid == 0) {
        //sleep(100);
        pid = fork();
        if (pid == 0) {
            //sleep(100);
            pid = fork();
            if (pid == 0) {
                //sleep(100);
                pid = fork();
                if (pid == 0) {
                    //sleep(100);
                    pid = fork();
                    if (pid == 0) {
                        //sleep(100);
                        pid = fork();
                        if (pid == 0) {
                            //sleep(100);
                            pid = fork();
                            if (pid == 0) {
                                //sleep(100);
                                pid = fork();
                                // ps();
                                // exit();
                            }
                        }
                    }
                }
            }
        }
    }
    ps();
    while (wait() != -1);
    exit();  
}