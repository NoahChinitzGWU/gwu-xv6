#include "types.h"
#include "user.h"
#include "pstat.h"
/**
 * Test 2: Parent forks a single child, that forks a single child, and so on until there
 * are 8 processes in the ancestry from the original parent, then call ps. This will, in
 * total, create 8 processes that are children, grandchildren, etc... of the parent
 * (9 processes in total).
 */
int main (void) {
    int pid;
    pid = fork();
    if (pid < 0) { // error
        exit();
    } else if (pid > 0) { // parent
        wait();
        exit();
    } else if (pid == 0) { // child
        // logic repeats
        pid = fork();
        if (pid < 0) {
            exit();
        } else if (pid > 0) {
            wait();
            exit();
        } else if (pid == 0) {
            // logic repeats
            pid = fork();
            if (pid < 0) {
                exit();
            } else if (pid > 0) {
                wait();
                exit();
            } else if (pid == 0) {
                // logic repeats
                pid = fork();
                if (pid < 0) {
                    exit();
                } else if (pid > 0) {
                    wait();
                    exit();
                } else if (pid == 0) {
                    // logic repeats
                    pid = fork();
                    if (pid < 0) {
                        exit();
                    } else if (pid > 0) {
                        wait();
                        exit();
                    } else if (pid == 0) {
                        // logic repeats
                        pid = fork();
                        if (pid < 0) {
                            exit();
                        } else if (pid > 0) {
                            wait();
                            exit();
                        } else if (pid == 0) {
                            // logic repeats
                            pid = fork();
                            if (pid < 0) {
                                exit();
                            } else if (pid > 0) {
                                wait();
                                exit();
                            } else if (pid == 0) {
                                // logic repeats
                                pid = fork();
                                if (pid < 0) {
                                    exit();
                                } else if (pid > 0) {
                                    wait();
                                    exit();
                                } else if (pid == 0) {
                                    ps(); // print out the processes
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while (wait() != -1); // wait until all processes have been cleaned up
    exit();  
}