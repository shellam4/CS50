#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// implement a program that encrypts messages using Caesar's cipher. Plaintext is unencrypted, ciphertext is encrypted, and the key is the secret used to decrypt it.

// get the command line arguments from the user
int main(int argc, string argv[]) {

    // return an error message if the user does not input the proper number of arguments
    if (argc != 2) {
       printf("Usage: ./caesar key\n");
       return 1;
    }

    // return an error message and exits the program if the user inputs a character that is not a digit
   for (int i = 0, n = strlen(argv[1]); i < n; i++) {
       if (!isdigit(argv[1][i])) {
          printf("Usage: ./caesar key\n");
          return 1;
       }
   }

   // ask the user to input a string of text for the plaintext that will be later encrypted into ciphertext
   string plaintext = get_string("plaintext: ");

   // check whether each character in the plaintext is a letter, if it is not a letter then reprompt the user for the plaintext
   for (int i = 0, n = strlen(plaintext); i < n; i++) {
       while (isdigit(plaintext[i])) {
           plaintext = get_string("plaintext: ");
       }
   }

   // print out the prompt for the ciphertext
   printf("ciphertext: ");

    // declare the constant key variable and set the value to the interger version of the user's second cli argument and set it the remainder after 26 so the ciphertext wraps around and does not 
    // go beyond the alphabets in ascii
   const int KEY = atoi(argv[1]) % 26;

   // calculate the ciphertext for each character in the plaintext
   for (int i = 0, n = strlen(plaintext); i < n; i++) {
       
       // check if the character at the index is not a letter and print the character instead
       if (!isalpha(plaintext[i])) {
           printf("%c", plaintext[i]);
           continue;
       }
       
       // set the starting point in ascii for if the character is uppercase or lowercase, then set the letter to corresponding position in the alphabet, 
       // then do the caesar algorithm and print the proper ciphertext
       if (isupper(plaintext[i])) {
           int pi = plaintext[i] - 65;
           int ci = (pi + KEY) % 26;
           printf("%c", ci + 65);
       }
        
        if (islower(plaintext[i])) {
           int pi = plaintext[i] - 97;
           int ci = (pi + KEY) % 26;
           printf("%c", ci + 97);
       }
   }
   printf("\n");
   return 0;
}
