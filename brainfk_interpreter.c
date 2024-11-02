#include <stdio.h>
#include <stdlib.h>

void operation(char c, int *array, int *ptr) {
    switch (c) {
        case '+': (array[*ptr])++; break;
        case '-': (array[*ptr])--; break;
        case '>': (*ptr)++; break;
        case '<': (*ptr)--; break;
        case '.': printf("%c", (char)array[*ptr]); break;
        case ',': array[*ptr] = getchar(); break; 
        default: break; 
    }
}

int main(int argc, char *argv[]) {
    int *array = calloc(1000, sizeof(int));
    if (array == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
    }
    int ptr = 0;

    if (argc >= 2) {
        for (int i = 0; argv[1][i] != '\0'; i++) {
            char c = argv[1][i];
            if (c == '[') {
                // if the current value is zero, skip to the matching ']'
                if (array[ptr] == 0) {
                    int bracket_count = 1; 
                    while (bracket_count > 0) {
                        i++;
                        if (argv[1][i] == '[') bracket_count++;
                        else if (argv[1][i] == ']') bracket_count--;
                    }
                }
            } else if (c == ']') {
                // if the current value is non-zero, go back to the matching '['
                if (array[ptr] != 0) {
                    int bracket_count = 1;
                    while (bracket_count > 0) {
                        i--;
                        if (argv[1][i] == ']') bracket_count++;
                        else if (argv[1][i] == '[') bracket_count--;
                    }
                }
            } else {
                operation(c, array, &ptr);
            }
        }
    } else {
        printf("Usage(Windows): ./a.exe {bf code}\nUsage(Linux/Mac): ./a.out {bf code}\n");
        free(array);
        return 0;
    }

    free(array);
    return 0;
}
