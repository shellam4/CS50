#include <cs50.h>
#include <stdio.h>
#include <string.h>

//implement a program that runs a plurality election

// this is a constant variable called Max with the number of candidates as the value
#define MAX 9

// this is a custom data structure callled candidate with a name and vote count for candidates
typedef struct
{
    string name;
    int votes;
}
candidate;

// declared an array called candidates where each element is of the custom candidate data type
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // declare a variable for the number of candidates in the array based on how names the user entered at the cli  
    candidate_count = argc - 1;
    
    // return an error message return of 2 if the user inputs too many candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    
    // Populate array of candidates with the arguments that the user gave and set all their current number of votes to 0
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    // declare a variable that sets how many people will get to vote 
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters and ask them for their preferred candidate
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote by using the vote function
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // check whether the voter has enetered a valid candidate name and add one to the candidates votes, otherwise return false 
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].name, name) == 0) {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // declare the variable called most votes and set to the first candidate's amount of votes 
    int most_votes = candidates[0].votes;
    
    // check whether the next candidate has more votes and then set that as the most votes
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes > most_votes) {
            most_votes = candidates[i].votes;
        }
    }
    
    //print the name of the candidate(s) with the number of votes that matches the value of most_votes
    for (int i = 0; i < candidate_count; i++) {
        if (candidates[i].votes == most_votes) {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}

