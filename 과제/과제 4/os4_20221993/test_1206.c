#include "types.h"
#include "user.h"
#include "mmu.h"

int main() {
    printf(1, "Starting syscall test...\n");

    int free_pages_before = getNumFreePages();
    printf(1, "Free pages before page fault: %d\n", free_pages_before);

    char *addr = sbrk(PGSIZE); 
    if (addr == (char *)-1) {
        printf(1, "Error: Failed to allocate memory\n");
        exit();
    }
    printf(1, "Allocated memory at address: %p\n", addr);

    printf(1, "Reading from allocated page: %c\n", addr[0]); 

    printf(1, "Triggering page fault by writing to allocated page...\n");
    addr[0] = 'A';

    pagefault();
    printf(1, "Page fault handled successfully\n");

    int free_pages_after = getNumFreePages();
    printf(1, "Free pages after page fault: %d\n", free_pages_after);

    if (sbrk(-PGSIZE) == (char *)-1) {
        printf(1, "Error: Failed to deallocate memory\n");
    } 
    else {
        printf(1, "Memory deallocated successfully\n");
    }

    int free_pages_final = getNumFreePages();
    printf(1, "Final free pages: %d\n", free_pages_final);

    printf(1, "Syscall test completed.\n");
    exit();
}
