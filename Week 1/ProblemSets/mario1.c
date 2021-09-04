#include <stdio.h>
#include <cs50.h>

int main() {
    // prompt the user for a positive int for the height
    int height;
    do {
        height = get_int("Height: ");
    }
    while(height % 2 != 0 || height > 8 || height < 1);
    
    // print the pyramid
    for (int row = 1; row <= height; row++) {
       // print the spaces to make it right aligned
       for (int k = 1; k <= height - row; k++) {
            printf(" ");

       }
       // print row the correct number of times
        for(int j = 1; j <= row; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
