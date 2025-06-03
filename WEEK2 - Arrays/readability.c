#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
int main(){

    // Prompt the user for some text
    int letter = 0;
    int word = 1;
    int sentence = 0;
    string text = get_string("Text: ");

    if (strlen(text)<=0){
        return 0;
    }

    // Count the number of letters, words, and sentences in the text

    //count letter
    for (int i = 0; i<strlen(text); i++){
        if(isalpha(text[i])){
            letter++;
        }
    }

    //count words
    for (int i = 0; i<strlen(text); i++){
        if(text[i]==32){
            word++;}
    }

    //count sentence
    for (int i=0; i<strlen(text); i++){
        if(text[i]==46 || text[i]==33 || text[i]==63){
            sentence++;
        }
    }

    // Compute the Coleman-Liau index

    //L = average letter per word;
    float L = letter / (float)word * 100;

    //S = average sentence per word;
    float S = sentence / (float)word * 100;

    //index
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade level
    if(index<1){
        printf("Before Grade 1\n");
    }
    else if(index>=16){
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %d\n",index);
    }

    return 0;
}
