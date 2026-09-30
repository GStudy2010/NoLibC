#include "include/nolibc.h"
#include "nolibc.h"

i32 usize_i32(usize input) {
    if (input > 2147483647UL)
        return 0;
    return (i32)input;
}
i64 usize_i64(usize input) {
    if (input > 2147483647UL*2)
        return 0;
    return (i64)input;
}

i32 f32_i32(f32 input) {
    return (i32)input;
}
i64 f64_i64(f64 input) {
    return (i64)input;
}
