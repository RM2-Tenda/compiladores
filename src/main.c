#define _POSIX_C_SOURCE 200809L
#include "../utils/headers/variables.h"
#include "calc.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Making it work with nmake on windows
#ifdef _WIN32
#ifdef _WIN64
#define SIZE_T PRIu64
#else
#define SIZE_T PRIu32
#endif
#else
#define SIZE_T "llu"
#endif

extern void yylex_destroy(void);

int main() {
    printf("Welcome to calculator\n");
    yyparse();
    clear_all_variables();
    yylex_destroy();
    return 0;
}
