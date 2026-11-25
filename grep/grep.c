#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* fptr;
    char* line = NULL;
    size_t size = 0;
    ssize_t nread;
    _Bool found = false;

    if (argc != 3) {
        printf("USE: ./grep -file -pattern\n");
        return 0;
    }
    fptr = fopen(argv[1], "r");

    if (fptr == NULL) {
        perror(argv[1]);
        return 1;
    }
    size_t lc = 1;
    while ((nread = getline(&line, &size, fptr)) != -1) {
        if (strstr(line, argv[2])) {
            printf("%zu:%s", lc, line);
            found = true;
        }
        lc++;
    }

    free(line);
    fclose(fptr);

    if (!found) {
        printf("no matches found\n");
        return 1;
    }

    return 0;
}
