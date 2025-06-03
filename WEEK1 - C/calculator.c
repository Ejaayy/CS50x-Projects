#include <stdio.h>
#include <cs50.h>

int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main(void){
    int x, y;
    char z;

    printf("Enter 1st number: ");
    scanf("%d", &x);

    printf("Enter Operation: ");
    scanf(" %c", &z);

    printf("Enter 2nd Number: ");
    scanf("%d", &y);

    if ( z == '+'){
        printf("%d\n",  add(x,y) );
    }
    else if ( z == '-'){
        printf("%d\n",  subtract(x,y) );
    }
    else if ( z == '*'){
        printf("%d\n",  multiply(x,y) );
    }
    else if ( z == '/'){
        printf("%d\n",  divide(x,y) );
    }
    return 0;
}

int add(int a, int b){
    return a + b;
}

int subtract(int a, int b){
    return a - b;
}

int multiply(int a, int b){
    return a * b;
}

int divide(int a, int b){
    return a / b;
}
