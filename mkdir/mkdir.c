#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("USE: mkdir folder folder ...\n");
        return 0;
    }
    for (int i = 0; i < argc; i++) {
        mkdir(argv[i], 0755);
    }

    return 0;
}
