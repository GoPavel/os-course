#include <stdio.h>

extern "C"
void f_from_d() {
    printf("Called function from dynamic library d, which load in run-time.\n");
}
