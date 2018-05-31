#include <cstdio>
#include <dlfcn.h>

void f_from_a();
void f_from_a1();
void f_from_b();

int main() {

    printf("Called main.\n");

    f_from_a();
    f_from_a1();
    f_from_b();

    void *p = dlopen("libd.so", RTLD_LAZY);
    if(!p) {
        printf("Can't load dynamic library\n");
        return 1;
    }

    void(*f_from_d)() = reinterpret_cast<void(*)()>(dlsym(p, "f_from_d"));
    if(!f_from_d) {
        printf("Can't load symbol f_from_d\n");
        dlclose(p);
        return 1;
    }

    f_from_d();
    dlclose(p);


    return 0;
}
