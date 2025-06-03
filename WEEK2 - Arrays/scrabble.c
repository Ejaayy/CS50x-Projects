#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int score(string letter, int length){


    int wordPoints = 0;
    for (int i = 0; i<length; i++){

        //converts that first char to upper case
        if (!isalpha(letter[i])){
            continue;
        }
        letter[i]=toupper(letter[i]);

        //Makes A= 0, B=1, ...
        int index = letter[i] - 'A';

        //Adds the specifc point inteded for that char index
        wordPoints += POINTS[index];
    }
    return wordPoints;
}



int main(){
    //ask user for input;

    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = score(word1, strlen(word1));
    int score2 = score(word2, strlen(word2));

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}
