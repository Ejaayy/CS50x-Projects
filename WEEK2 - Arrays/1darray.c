// Online C compiler to run C program online
#include <stdio.h>

int main() {
    int score[5] = {10,10,10,10,10};
    int size = sizeof(score)/sizeof(score[0]);
    int tempscore = 0;

    for (int i = 0; i<size; i++){
        tempscore += score[i];
    }

    float average = tempscore / (float)size;
    printf("Average mark is %.2f", average);

    return 0;
}
