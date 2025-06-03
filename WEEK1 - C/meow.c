#include <stdio.h>

void meow(int n);
//this is the function
//its just like a title to show that it exists but is defined at the bottom

int main(void)
{

    meow(6);

    return 0;
}

void meow(int n){
    for (int i=0; i<n; i++){
        printf("Meow\n");
    }
}
