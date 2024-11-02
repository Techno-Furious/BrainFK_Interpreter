#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char code[5000];

    if (argc >= 3 && strcmp(argv[1], "-f") == 0) {
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) {
            fprintf(stderr, "Failed to open file: %s\n", argv[2]);
            free(array);
            return 1;
        }
        fread(code, sizeof(char), 5000, fp);
        fclose(fp);
    } else if (argc >= 2) {
        strcpy(code, argv[1]);
    } else {
        printf("Usage(Windows): ./a.exe {bf code or -f bfCode.bf}\nUsage(Linux/Mac): ./a.out {bf code or -f bfCode.bf}\n");
        free(array);
        return 0;
    }

    for (int i = 0; code[i] != '\0'; i++) {
        char c = code[i];
        if (c == '[') {
            // if the current value is zero skip to the matching ']'
            if (array[ptr] == 0) {
                int bracket_count = 1; 
                while (bracket_count > 0) {
                    i++;
                    if (code[i] == '[') bracket_count++;
                    else if (code[i] == ']') bracket_count--;
                }
            }
        } else if (c == ']') {
            // if the current value is non-zero go back to the matching '['
            if (array[ptr] != 0) {
                int bracket_count = 1;
                while (bracket_count > 0) {
                    i--;
                    if (code[i] == ']') bracket_count++;
                    else if (code[i] == '[') bracket_count--;
                }
            }
        } else {
            operation(c, array, &ptr);
        }
    }

    free(array);
    return 0;
}
