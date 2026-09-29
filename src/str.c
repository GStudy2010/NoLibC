#include "nolibc.h"

struct s {
    c *data;
    i32 lenght;
};

i32 strlen(const s *str) {
    return str->lenght;
}

