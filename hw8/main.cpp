#include <signal.h>
#include <errno.h>
#include <malloc.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>
#include <setjmp.h>
#include <ucontext.h>
#include <string>
#include <iostream>
#include "sigsegv_dump.h"

int main() {
    sigsegv_dump::init();

    // <wrong code>
    //1
//     raise(SIGSEGV);
    //2
    int *ptr = (int*)(&main);
    ptr[0] = 0;
    // </wrong code>

    return 0;
}
