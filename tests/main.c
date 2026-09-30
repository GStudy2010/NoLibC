#include "nolibc.h"
void _start(void) {
    const char *s = "Hello world";
    usize bytes_to_allocate = char_p_len(s);
    char *text = malloc(bytes_to_allocate);

    if (!text) {
        exit(PROGRAM_FAILIURE);
    }

    for (usize i = 0;i<bytes_to_allocate;i++) {
        text[i] = s[i];
    }

    exit(PROGRAM_SUCCES);
}
