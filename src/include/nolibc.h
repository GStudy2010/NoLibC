#ifndef NOLIBC_H
#define NOLIBC_H

// Types //

    // Numbers //
typedef long long i128;
typedef long i64;
typedef int  i32;
typedef float f32;
typedef double f64;
typedef __float128 f128;

    // Strings //
typedef char c;
typedef struct s s;
s *str_create(const char *str); // Cannot create, no malloc, memcpy
void str_destroy(s *str);       // Cannot create, no free

    // Type conversion functions //
i32 f32_i32(f32 input);
i64 f64_i64(f64 input);
i128 f128_i128(f128 input);

#define to_int(input) _Generic((input), \
    f32: f32_i32,                         \
    f64: f64_i64,                         \
    f128: f128_i128,                      \
)(input)


    // End Type conversion functions //


    // String functions //
i32 strlen(const s *str);



    // End String functions //


// Types // 


// Exit program functions //
void exit_i32(i32 status);
void exit_i64(i64 status);
void exit_i128(i128 status);
void exit_f32(f32 status);
void exit_f64(f64 status);
void exit_f128(f128 status);

#define exit(status) _Generic((status), \
    i32: exit_i32,                      \
    i64: exit_i64,                    \
    i128: exit_i128,                    \
    f32: exit_f32,                  \
    f64: exit_f64,                \
    f128: exit_f128                 \
)(status)
// End Exit program functions //

#endif // !NOLIBC_H

// Memory //

    // I don't have a slightes idea how to implement those mf/

void *malloc_i32(i32 size);
void *malloc_i64(i64 size);
void *malloc_i128(i128 size);

#define malloc(size) _Generic((size), \
    i32: malloc_i32,                  \
    i64: malloc_i64,                  \
    i128: malloc_i128,                \
)(size)

void *free();
void *memcpy();

