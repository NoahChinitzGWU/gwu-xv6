#include "types.h"
#include "user.h"
#include "pstat.h"
/**
 * Test 1: Parent forks 8 children, then calls ps.
 */ 
int
main(void)
{
    int pid;
    for (int i = 0; i < 8; i++) {
        pid = fork();
        if (pid < 0) { // error
		    exit();
        } else if (pid == 0) { // child
            sleep(100);
            exit();
        }
    }
    ps();
    while (wait() != -1); // wait until all processes have been cleaned up
    exit();    
}