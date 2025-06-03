#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string answer1 = get_string("What's your name ");
    int answer2 = get_int("What's your age? ");
    int answer3 = get_int("What's your contact number? ");


    printf("Name: %s\n", answer1);
    printf("Contact Number: %i\n", answer2);
    printf("Contact Number: %i\n", answer3);
    return 0;
}
