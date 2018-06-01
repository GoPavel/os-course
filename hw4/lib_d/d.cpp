#include <iostream>

extern "C"
void f_from_d() {
    std::cout << "Called function from dynamic library d, which load in run-time.\n";
}
