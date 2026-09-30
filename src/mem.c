#include "nolibc.h"

#define SYS_MMAP 9

#define PROT_READ  1
#define PROT_WRITE 2

#define MAP_PRIVATE 2
#define MAP_ANON    32

#define HEAP_SIZE (1024 * 1024) // 1Mib

static unsigned char *heap = 0;
static usize heap_used = 0;

static void *request_mem_i32(i32 size)
{
    register long r10 __asm__("r10") = MAP_PRIVATE | MAP_ANON;
    register long r8  __asm__("r8")  = -1;
    register long r9  __asm__("r9")  = 0;

    long res = SYS_MMAP;

    __asm__ volatile (
        "syscall"
        : "+a"(res)
        : "D"(0L),
          "S"((long)size),
          "d"((long)(PROT_READ | PROT_WRITE)),
          "r"(r10),
          "r"(r8),
          "r"(r9)
        : "rcx", "r11", "memory"
    );

    if (res < 0 && res >= -4095)
        return 0;

    return (void *)res;
}

void *malloc_usize(usize size) {
    if (size == 0)
        return 0;
    if (size > (usize)-1 - 15)
        return 0;

    size = (size + 15) & ~(usize)15;

    if (!heap) {
        heap = request_mem_i32(HEAP_SIZE); // Initialize heap if not yet initialized

        if (!heap)
            return 0;
    }
    if (size > HEAP_SIZE - heap_used)
        return 0;

    void *result = heap + heap_used;
    heap_used += size;

    return result;
}

void *malloc_i32(i32 size) {
    if (size <= 0)
        return 0;
    size = (size + 15) & ~(usize)15;
    if (!heap) {
        heap = request_mem_i32(HEAP_SIZE); // Initialize heap if not yet initialized

        if (!heap)
            return 0;
    }
    if (size > usize_i32(HEAP_SIZE - heap_used))
        return 0;

    void *result = heap + heap_used;
    heap_used += size;

    return result;
}
void *malloc_i64(i64 size) {
    if (size <= 0)
        return 0;
    size = (size + 15) & ~(usize)15;
    if (!heap) {
        heap = request_mem_i32(HEAP_SIZE); // Initialize heap if not yet initialized

        if (!heap)
            return 0;
    }
    if (size > usize_i64(HEAP_SIZE - heap_used))
        return 0;

    void *result = heap + heap_used;
    heap_used += size;

    return result;
}
