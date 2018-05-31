#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <string.h>

unsigned char  code_func[] = {0x8b, 0x44, 0x24, 0x04, 0x03, 0x44, 0x24, 0x08, 0xc3};


typedef int __attribute__((__cdecl__)) (*a_plus_b)(int a, int b);

int a = 20;
int b = 20;

int main() {
    void *ptr = mmap(0, sizeof(code_func), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0 );
    if (ptr == (void *) -1) {
        perror("mmap");
        exit(EXIT_FAILURE);
    }

    memcpy(ptr, code_func, sizeof(code_func));
    if (mprotect(ptr, sizeof(code_func), PROT_READ | PROT_EXEC) == -1) {
        perror("mprotect");
        exit(EXIT_FAILURE);
    }

    a_plus_b func = (a_plus_b)(ptr);
    printf("a = %d, b = %d => a + b = %d\n", a, b, func(a, b));

    if (munmap(ptr, sizeof(code_func)) == -1) {
        perror("munmap");
        exit(EXIT_FAILURE);
    }

    return 0;
}
