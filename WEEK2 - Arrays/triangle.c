#include <stdio.h>
#include <cs50.h>
#include <stdbool.h>

bool valid_triangle (float a, float b, float c);

int main(){

    float side1, side2, side3;
    printf("Enter the sides of the triangle: \n");
    printf("Side 1: ");
    scanf("%f", &side1);
    printf("Side 2: ");
    scanf("%f", &side2);
    printf("Side 3: ");
    scanf("%f", &side3);

    bool triangle = valid_triangle (side1, side2, side3);
    if ( triangle == 0){
        printf("It is not a triangle\n");
    }
    else if (triangle == 1){
        printf("It is a triangle\n");
    }

    return 0;
}

bool valid_triangle (float a, float b, float c){

    if (a==0 || b==0 || c==0){
        return false;
    }
    else if ( a+b > c && a+c > b && b+c > a) {
        return true;
    }
    else{
        return false;
    }

}
