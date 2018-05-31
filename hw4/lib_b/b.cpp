#include <stdio.h>

void f_from_b() {
    printf("Called function from dynamic library b, which load before run-time.\n");
}
