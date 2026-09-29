#include "include/nolibc.h"
#include "nolibc.h"

/*
void exit(const int status):
    Takes an const int and exits program with its value
    Uses syscall 0x60 for return
    regiter rax to store the syscall number 0x60
    regiter rdi to store the status of exit
 */

void exit_i32(const i32 status) {
    __asm__ volatile(
        "syscall"
        : 
        : "a"(60), 
          "D"(status)
        : "rcx", "r11", "memory"
    );
    __builtin_unreachable();
}
void exit_i64(const i64 status) {
    __asm__ volatile(
        "syscall"
        : 
        : "a"(60), 
          "D"(status)
        : "rcx", "r11", "memory"
    );
    __builtin_unreachable();
}
void exit_i128(const i128 status) {
    __asm__ volatile(
        "syscall"
        : 
        : "a"(60), 
          "D"(status)
        : "rcx", "r11", "memory"
    );
    __builtin_unreachable();
}
void exit_f32(const f32 status) {
    int int_status = f32_i32(status);
    __asm__ volatile(
        "syscall"
        : 
        : "a"(60), 
          "D"(int_status)
        : "rcx", "r11", "memory"
    );
    __builtin_unreachable();
}
void exit_f64(const f64 status) {
    int int_status = f64_i64(status);
    __asm__ volatile(
        "syscall"
        : 
        : "a"(60), 
          "D"(int_status)
        : "rcx", "r11", "memory"
    );
    __builtin_unreachable();
}
void exit_f128(const f128 status) {
    int int_status = f128_i128(status);
    __asm__ volatile(
        "syscall"
        : 
        : "a"(60), 
          "D"(int_status)
        : "rcx", "r11", "memory"
    );
    __builtin_unreachable();
}
