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
