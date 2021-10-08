// Holds all important information about each process
struct pstat {
    int pid; // Process id of process you're printing information for
    int ppid; // Process' parent's process id (pid)
    char state; // Process state [EMBRYO (E), SLEEPING (S), RUNNABLE (N), RUNNING (R), & ZOMBIE (Z)]
    char name[16]; // Process' name that is stored in the structure
};