#include <stdio.h>
#include <cs50.h>

// Say we have a population of n. Each year, n / 3 new llamas are born, and n / 4 llamas pass away.

int main(void) {
    // Prompt for start size
    int startsize;
    do {
        startsize = get_int("Start size: ");
    }
    while(startsize <= 9);

    // Prompt for end size
    int endsize;
    do {
        endsize = get_int("End size: ");
    }
    while(endsize <= startsize);

    // Calculate number of years until we reach threshold
    int years = 0;
    do {
        double llamasgained = startsize / 3;
        double llamaslost = startsize / 4;
        startsize = startsize + llamasgained - llamaslost;
        years = years + 1;
    }
    while(startsize < endsize);

    // Print the number of years
    printf("Years: %i\n", years);
}
