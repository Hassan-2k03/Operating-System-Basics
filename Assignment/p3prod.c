#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Expected two command-line arguments\n");
        return 1;
    }

    int x = atoi(argv[1]);
    int y = atoi(argv[2]);

    printf("The product of %d and %d is %d\n", x, y, x*y);

    return 0;
}