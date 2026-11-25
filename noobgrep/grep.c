#include <regex.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("USE: ./grep -file -pattern\n");
        return 0;
    }

    FILE* fptr;
    fptr = fopen(argv[1], "r");
    if (fptr == NULL) {
        perror(argv[1]);
        return 1;
    }
    fseek(fptr, 0, SEEK_END);
    long size = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    int ch;
    char buf[size + 1];
    buf[size] = '\0';
    size_t count = 0;
    while ((ch = fgetc(fptr)) != EOF) {
        buf[count] = ch;
        count++;
    }
    char* res = strstr(buf, argv[2]);
    if (res != NULL) {
        printf("FOUND PATTERN!\n");
        return 0;
    }
    // idea: get the file inside a buffer, then pattern match that buffer
    // against the wanted value

    return 0;
}
