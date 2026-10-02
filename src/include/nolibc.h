#ifndef NOLIBC_H
#define NOLIBC_H


// Consts //
#define PROGRAM_FAILIURE 1
#define PROGRAM_SUCCES 0

// Types //

    // Numbers //
typedef long i64;
typedef int  i32;
typedef float f32;
typedef double f64;
typedef unsigned long usize;
    // Strings //
typedef char c;

    // Type conversion functions //

i32 usize_i32(usize input);
i64 usize_i64(usize input);


i32 f32_i32(f32 input);
i64 f64_i64(f64 input);

#define to_int(input) _Generic((input), \
    f32: f32_i32,                         \
    f64: f64_i64                          \
)(input)


    // End Type conversion functions //


    // String functions //
usize char_p_len(const c *ch);



    // End String functions //


// Types // 


// Exit program functions //
void exit_i32(i32 status);
void exit_i64(i64 status);
void exit_f32(f32 status);
void exit_f64(f64 status);
#define exit(status) _Generic((status), \
    i32: exit_i32,                      \
    i64: exit_i64,                    \
    f32: exit_f32,                  \
    f64: exit_f64                 \
)(status)
// End Exit program functions //


// Memory //

typedef struct {
    void *address;
    usize bytes;
} Block;

typedef struct {
    Block *array;
    usize size;
    usize cap;
} MemHeap;

MemHeap *create_MemHeap(usize capacity);


    // I don't have a slightes idea how to implement those mf/

void *malloc(usize size); // Implemented
void free(void *ptr);
void *memcpy();

#endif // !NOLIBC_H
