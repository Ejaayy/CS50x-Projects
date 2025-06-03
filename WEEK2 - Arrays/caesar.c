
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (int argc, string argv[]){
// examplpe: ./caesar3
//argc = 2
//argv[0] = ./caesar
//argv[1] = 3

    // Make sure program was run with just one command-line argument
    if (argc == 1 ){
        printf("Usage: ./caesar key");
        return 1;
    }
    else if (argc!=2){
        printf("Usage: ./caesar key");
        return 1;
    }


    // Make sure every character in argv[1] is a digit
    int size = strlen(argv[1]);

    for (int i = 0; i < size; i++){
        if(isdigit(argv[1][i])==0){
            printf("Usage: ./caesar key");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    char plaintext[100];
    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    // For each character in the plaintext:

    char ciphertext[100];

    for (int i = 0; i < strlen(plaintext); i++){

        if (isupper(plaintext[i])){
            int upperindex = plaintext[i] - 'A'; //makes A = 0, B = 1....
            ciphertext[i]= ( upperindex + key ) % 26 + 'A';
        }
        else if(islower(plaintext[i])){
            int lowerindex = plaintext[i] - 'a'; //makes a = 0, b = 1....
            ciphertext[i]= ( lowerindex + key ) % 26 + 'a';
        }
        else{
            ciphertext[i]=plaintext[i];
        }

    }

    printf("ciphertext: %s", ciphertext);

        // Rotate the character if it's a letter
    return 0;
}



