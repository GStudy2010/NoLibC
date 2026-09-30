#include "nolibc.h"

struct s {
    c *data;
    i32 lenght;
};

i32 strlen(const s *str) {
    return str->lenght;
}

usize char_p_len(const c *ch) {
    usize i = 0;
    while (ch[i] != '\0') {
        i++;
    }
    return i+1;
}
