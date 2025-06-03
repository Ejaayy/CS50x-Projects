#include <cs50.h>
#include <stdio.h>


int main(void)
{
    char c;
    printf("Do you agree? ");
    scanf("%c", &c);

    if (c == 'y'|| c == 'Y'){
        printf("Agreed\n");
    }

    else if ( c == 'n' || c == 'Y'){
        printf ("Not agreed.\n");
    }

    return 0;
}
