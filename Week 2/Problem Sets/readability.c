#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Prototypes
int count_letters(string usertext);
int count_words(string usertext);
int count_sentences(string usertext);
int liau_index(int letters, int words, int sentences);

int main(void) {
    // Get the text from the user
    string text = get_string("Text: ");
    
    // set variables for calulations
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    
    // calculate the index and Output the grade level 
    int grade = liau_index(letters, words, sentences);
    if (grade >= 16){
        printf("Grade 16+\n");
    }
    else if (grade < 1) {
        printf("Before Grade 1\n");
    }
    else {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string usertext) {
    // count the number of letters that show up in the text
    int letters = 0; 
    for (int i = 0, n = strlen(usertext); i < n; i++) {
        if(isalpha(usertext[i])) {
            letters++;
        }
        else {
            letters += 0;
        }
    }
    return letters;
}

int count_words(string usertext) {
    // count the number of words that show up in the text
    int words = 0; 
    for (int i = 0, n = strlen(usertext); i < n; i++) {
        if((usertext[i]) == ' ' || (usertext[i]) == '\n' || (usertext[i]) == '\t' || (usertext[i+1]) == '\0') {
            words++;
        }
        else {
            words += 0;
        }
    }
    return words;
}

int count_sentences(string usertext) {
    // count the number of sentences that show up in the text
    int sentences = 0; 
    for (int i = 0, n = strlen(usertext); i < n; i++) {
        if((usertext[i]) == '.' || (usertext[i]) == '!' || (usertext[i]) == '?') {
            sentences++;
        }
        else {
            sentences += 0;
        }
    }
    return sentences;
}

int liau_index(int letters, int words, int sentences) {
    float L = ((100.0 / words) * letters);
    float S = ((100.0 / words) * sentences);
    int index = round(0.0588 * L - 0.296 * S - 15.8); 
    return index;
}
