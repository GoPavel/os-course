#ifndef SIGSEGV_H
#define SIGSEGV_H

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

class sigsegv_dump {
public:
    const int range_of_memory = 4;

    void* address_fault;
    ucontext_t context;

    void print();

    static int fd[2];
    static jmp_buf env;

    static void handler_sigsegv(int sig, siginfo_t *si, void* unused);

    static void handler_sigsegv_check(int sig, siginfo_t *si, void* unused);

    static void init();

private:
    int print_byte(uint8_t *ptr, int offset);

    void print_st(_libc_fpxreg st, size_t index);
};

#endif // SIGSEGV_H
