#include "types.h"
#include "user.h"
#include "pstat.h"

int
main(void)
{
    int pid;
    for (int i = 0; i < 8; i++) {
        pid = fork();
        if (pid < 0) { 
		    exit();
        } else if (pid == 0) { // child
            sleep(100);
            exit();
        }
    }
    ps();
    while (wait() != -1); 
    exit();    
}