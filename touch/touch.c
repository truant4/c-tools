#include <stdio.h>
int main(int argc, char* argv[]) {
    if (argc <= 1 || argc > 2) {
        printf("USE TOUCH: ./touch -file\n");
        return 0;
    }
    FILE* fptr = fopen(argv[1], "w");

    if (fptr == NULL) {
        printf("Failed to create file");
        return 1;
    }

    printf("Created File Succesfully!\n");

    return 0;
}
