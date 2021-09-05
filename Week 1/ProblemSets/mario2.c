#include <stdio.h>
#include <cs50.h>

int main() {
    // prompt the user for a positive int for the height
    int height;
    do {
        height = get_int("Height: ");
    }
    while(height > 8 || height <= 0);
    
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
        // print the spaces in between
        printf("  ");
        
        // print the other rows the correct number of times
        for(int g = 1; g <= row; g++) {
            printf("#");
        }
        
        printf("\n");
    }
    return 0;
}
