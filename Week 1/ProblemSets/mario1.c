#include <stdio.h>
#include <cs50.h>

int main(void) {
    // prompt the user for a positive int for the height
    int height;
    do {
        height = get_int("Height: ");
    }
    while(height % 2 != 0 || height > 8 || height < 1);
    
    // print the pyramid
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < height; j++) {
            if ((i + j) < (height - 1)) {
                printf(" ");
            }
            else {
                printf("#");
            }
        }
        printf("\n");
    }
}
