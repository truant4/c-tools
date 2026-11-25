#include <stdio.h>

int main(int argc, char* argv[]) {
    FILE* fptr;
    if (argc <= 1 || argc > 2) {
        printf("USE: ./cat -file\n");
        return 0;
    }

    fptr = fopen(argv[1], "r");

    if (fptr == NULL) {
        printf("couldn't open file\n");
        return 1;
    }
    char ch;
    while ((ch = fgetc(fptr)) != EOF) {
        putchar(ch);
    }

    return 0;
}
