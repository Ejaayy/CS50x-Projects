#include <stdio.h>
#include <cs50.h>

    const int N=3; //global variable

int main(){

    int scores[N];
    for ( int i = 0; i<N; i++){

        scores[i]= get_int("Score: ");
    }

        printf("Average: %.2f\n", (scores[0] + scores[1] + scores[2]) / (float)N );

    return 0;
}
