#include "types.h"
#include "user.h"
//why no pstat.h?????
int
main(void)
{
    int pid;
    for (int i = 0; i < 8; i++) {
        pid = fork();
        if (pid < 0) { // error checking?????
		    exit();
        } else if (pid == 0) { // child
            sleep(100);
            exit(); //exit????
        }
    }
    ps();
    while (wait() != -1); //necessary????
    exit();    
}