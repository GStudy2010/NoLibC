
#include "nolibc.h"

#define SYS_MMAP 9

#define PROT_READ  1
#define PROT_WRITE 2

#define MAP_PRIVATE 2
#define MAP_ANON    32

#define MAX_BLOCKS 1024

static Block blocks[MAX_BLOCKS];

static MemHeap heap = {
    .array = blocks,
    .size = 0,
    .cap = MAX_BLOCKS
};

static void *request_memory(usize size)
{
    register long r10 __asm__("r10") =
        MAP_PRIVATE | MAP_ANON;
    register long r8 __asm__("r8") = -1;
    register long r9 __asm__("r9") = 0;

    long result = SYS_MMAP;

    __asm__ volatile (
        "syscall"
        : "+a"(result)
        : "D"(0L),
          "S"((long)size),
          "d"((long)(PROT_READ | PROT_WRITE)),
          "r"(r10),
          "r"(r8),
          "r"(r9)
        : "rcx", "r11", "memory"
    );

    if (result < 0 && result >= -4095)
        return 0;

    return (void *)result;
}

void *malloc(usize size)
{
    if (size == 0)
        return 0;

    if (size > (usize)-1 - 15)
        return 0;

    size = (size + 15) & ~(usize)15;

    if (heap.size >= heap.cap)
        return 0;

    void *address = request_memory(size);

    if (!address)
        return 0;

    heap.array[heap.size].address = address;
    heap.array[heap.size].bytes = size;
    heap.size++;

    return address;
}
