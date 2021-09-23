#include "types.h"
#include "user.h"

#define BUFFERSZ 500

int
main(int argc, char **argv)
{
    char *buffer;
    char *heap_ptr;
        
    heap_ptr = getheapptr();

    printf(0, "Heap Before Malloc: %p\n", getheapptr());
    printf(0, "Process is using: %d bytes\n\n", (int)heap_ptr);

    buffer = malloc(sizeof(char) * BUFFERSZ + 1);
        
    /* Print the Alphabet over and over */

    for (int i = 0; i < BUFFERSZ; i++) buffer[i] = 'a' + (i % 26); 
    buffer[BUFFERSZ] = '\0';
    printf(0, "My buffer at %p contains: %s\n\n", buffer, buffer);

    heap_ptr = getheapptr();
    printf(0, "Heap After Malloc: %p\n", getheapptr());
    printf(0, "Process is using: %d bytes\n\n", (int)heap_ptr);

    free(buffer);

    heap_ptr = getheapptr();
    printf(0, "Heap After Free: %p\n", heap_ptr);
    printf(0, "Process is using: %d bytes\n", (int)heap_ptr);

    exit();
    return 0; 
}
