#include "types.h"
#include "user.h"
#include "pstat.h"

int main (void) {
    int pid;
    pid = fork();
    if (pid < 0) {
        exit();
    } else if (pid > 0) {
        wait();
        exit();
    } else if (pid == 0) {
        pid = fork();
        if (pid < 0) {
            exit();
        } else if (pid > 0) {
            wait();
            exit();
        } else if (pid == 0) {
            pid = fork();
            if (pid < 0) {
                exit();
            } else if (pid > 0) {
                wait();
                exit();
            } else if (pid == 0) {
                pid = fork();
                if (pid < 0) {
                    exit();
                } else if (pid > 0) {
                    wait();
                    exit();
                } else if (pid == 0) {
                    pid = fork();
                    if (pid < 0) {
                        exit();
                    } else if (pid > 0) {
                        wait();
                        exit();
                    } else if (pid == 0) {
                        pid = fork();
                        if (pid < 0) {
                            exit();
                        } else if (pid > 0) {
                            wait();
                            exit();
                        } else if (pid == 0) {
                            pid = fork();
                            if (pid < 0) {
                                exit();
                            } else if (pid > 0) {
                                wait();
                                exit();
                            } else if (pid == 0) {
                                pid = fork();
                                if (pid < 0) {
                                    exit();
                                } else if (pid > 0) {
                                    wait();
                                    exit();
                                } else if (pid == 0) {
                                    ps();
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    while (wait() != -1);
    exit();  
}