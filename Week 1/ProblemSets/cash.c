#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void){
    //get the amount of change owed
    float change;
    do {
        change = get_float("Change owed: ");
    }
    while(change < 0);
    
    // convert the amount of change owed into an integer
    int cents = round(change * 100);
    
    // calculate how many coins should be used
    int quarters = cents / 25;
    cents = cents - (25 * quarters);
    int dimes = cents / 10;
    cents = cents - (10 * dimes);
    int nickles = cents / 5;
    cents = cents - (5 * nickles);
    int pennies = cents / 1;
    cents = cents - (1 * pennies);
    
    // print the number of coins to use
    printf("%i\n", quarters + dimes + nickles + pennies);
}
