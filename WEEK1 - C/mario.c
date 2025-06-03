#include <cs50.h>
#include <stdio.h>

void haba(int length);
void space(int count);

int main(void){

int height;

    do {
        printf("Enter height: ");
        scanf("%d", &height);
    } while (height <= 0);

    for (int i = 0; i < height; i++){
    space(height-i-1); //just making height-i will start with 4 spaces cuz height-0 in the beginning so we added 1 more -1
    haba(i+1);
    printf("\n");

    }
    return 0;
}

void haba(int length){
    for (int i = 0; i < length; i++){
        printf("#");
    }
}

void space(int count){
    for (int i = 0; i < count; i++){
        printf(" ");
    }

}

