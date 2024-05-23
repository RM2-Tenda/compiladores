#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct yy_buffer_state *YY_BUFFER_STATE;

extern int yyparse();
extern void yy_delete_buffer(YY_BUFFER_STATE buffer);
extern YY_BUFFER_STATE yy_scan_string(const char *);

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"

int total_tests = 0;
int passed_tests = 0;

void run_test(const char *input, const char *expected_output) {
    total_tests++;

    // Redirect stdout to a dynamic buffer
    char *buffer = NULL;
    size_t buffer_size = 0;
    FILE *stream = open_memstream(&buffer, &buffer_size);
    FILE *original_stdout = stdout;
    stdout = stream;

    // Run the parser
    YY_BUFFER_STATE buffer_state = yy_scan_string(input);
    yyparse();
    yy_delete_buffer(buffer_state);

    // Restore stdout
    fflush(stdout);
    fclose(stream);
    stdout = original_stdout;

    // Trim trailing whitespace and newline characters from the actual output
    char *actual_output = buffer;
    while (buffer_size > 0 && (actual_output[buffer_size - 1] == '\n' ||
                               actual_output[buffer_size - 1] == ' ')) {
        actual_output[--buffer_size] = '\0';
    }

    // Trim trailing whitespace and newline characters from the expected output
    char *trimmed_expected_output = strdup(expected_output);
    size_t expected_size = strlen(trimmed_expected_output);
    while (expected_size > 0 &&
           (trimmed_expected_output[expected_size - 1] == '\n' ||
            trimmed_expected_output[expected_size - 1] == ' ')) {
        trimmed_expected_output[--expected_size] = '\0';
    }

    // Compare the actual output with the expected output
    if (strcmp(actual_output, trimmed_expected_output) == 0) {
        printf(GREEN "✓ Test passed: %s\n" RESET, input);
        passed_tests++;
    } else {
        printf(RED "✗ Test failed: %s\n" RESET, input);
        printf("  Expected output:\n%s\n", trimmed_expected_output);
        printf("  Actual output:\n%s\n", actual_output);
    }

    // Free the dynamically allocated buffers
    free(buffer);
    free(trimmed_expected_output);
}

void print_test_summary() {
    printf("\nTest Summary:\n");
    printf("Total tests: %d\n", total_tests);
    printf("Passed tests: %d\n", passed_tests);
    printf("Failed tests: %d\n", total_tests - passed_tests);

    if (passed_tests == total_tests) {
        printf(GREEN "All tests passed!\n" RESET);
    } else {
        printf(RED "Some tests failed.\n" RESET);
    }
}

int main() {
    // Test integer input
    run_test("1\n", "1");
    run_test("-5\n", "-5");

    // Test float input
    run_test("1.0\n", "1.000000");
    run_test("-3.14\n", "-3.140000");

    // Test addition
    run_test("2 + 3\n", "5");
    run_test("1.5 + 2.5\n", "4.000000");
    run_test("2 + 3.5\n", "5.500000");

    // Test subtraction
    run_test("5 - 2\n", "3");
    run_test("4.5 - 1.5\n", "3.000000");
    run_test("5 - 2.5\n", "2.500000");

    // Test multiplication
    run_test("2 * 3\n", "6");
    run_test("1.5 * 2\n", "3.000000");
    run_test("2 * 3.5\n", "7.000000");

    // Test division
    run_test("6 / 2\n", "3");
    run_test("5 / 2.0\n", "2.500000");
    run_test("4.5 / 1.5\n", "3.000000");

    // Test modulo
    run_test("7 % 3\n", "1");
    run_test("5.5 % 2\n", "1.500000");

    // Test power
    run_test("2 ** 3\n", "8");
    run_test("2.5 ** 2\n", "6.250000");

    // Test left shift
    run_test("5 << 2\n", "20");

    // Test right shift
    run_test("10 >> 1\n", "5");

    // Test unary minus
    run_test("-3\n", "-3");
    run_test("-2.5\n", "-2.500000");

    // Test parentheses
    run_test("(2 + 3) * 4\n", "20");
    run_test("(3.5 - 1.5) * (2 + 1)\n", "6.000000");

    // Test variable assignment and retrieval
    run_test("a = 5\n", "5");
    run_test("a\n", "5");
    run_test("b = 2.5\n", "2.500000");
    run_test("b\n", "2.500000");

    // Test variable increment and decrement
    run_test("a = 5\n", "5");
    run_test("a++\n", "6");
    run_test("a--\n", "5");

    // Test clearing variables
    run_test("a = 5\n", "5");
    run_test("@CLEAR a\n", "Variable a cleared");
    run_test("@CLEAR\n", "All variables cleared");

    // Test listing variables
    run_test("a = 5\n", "5");
    run_test("b = 2.5\n", "2.500000");
    run_test("@LIST\n", "a (int) = 5\nb (float) = 2.500000");
    run_test("@LIST a\n", "a (int) = 5");

    // Test Sample Input
    run_test("2+5*3\n", "17");
    run_test("x=2**3\n", "8");
    run_test("alfa = (x<<1)*2\n", "32");
    run_test("alfa+1\n", "33");

    // Precedence Test
    run_test("7<<2-1\n", "14");
    run_test("2 + 3 * 4\n", "14");
    run_test("2 * 3 + 4\n", "10");
    run_test("2 + 3 * 4 - 5\n", "9");
    run_test("2 * (3 + 4)\n", "14");
    run_test("(2 + 3) * 4\n", "20");
    run_test("2 + 3 * 4 / 2\n", "8");
    run_test("2 * 3 + 4 / 2\n", "8");
    run_test("2 + 3 * 4 % 3\n", "2");
    run_test("2 * 3 % 4 + 5\n", "7");
    run_test("2 + 3 << 1\n", "10");
    run_test("2 << 1 + 3\n", "32");
    run_test("2 + 3 >> 1\n", "2");
    run_test("8 >> 1 + 1\n", "2");
    run_test("2 ** 3 + 4\n", "12");
    run_test("2 + 3 ** 2\n", "11");
    run_test("2 ** (3 + 1)\n", "16");
    run_test("2 * 3 ** 2\n", "18");
    run_test("2 + 3 & 1\n", "1");
    run_test("2 & 3 + 1\n", "0");
    run_test("2 | 3 + 1\n", "6");
    run_test("2 + 3 | 1\n", "5");
    run_test("2 ^ 3 + 1\n", "6");
    run_test("2 + 3 ^ 1\n", "4");

    print_test_summary();

    return 0;
}