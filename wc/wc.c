#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    FILE* fptr;
    char* line = NULL;
    size_t size = 0;
    ssize_t nread;
    ssize_t wc = 0;

    if (argc != 2) {
        printf("USE: wc -file\n");
        return 0;
    }
    fptr = fopen(argv[1], "r");

    if (fptr == NULL) {
        perror(argv[1]);
        return 1;
    }

    while ((nread = getline(&line, &size, fptr)) != -1) {
        wc++;
    }

    printf("%zu\n", wc);

    free(line);
    fclose(fptr);

    return 0;
}
