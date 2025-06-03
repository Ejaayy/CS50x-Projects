#include <stdio.h>

int main(){

    char name[30];
    fgets(name, 30, stdin);
    name[0]= 'X';
    printf("%s", name);

    return 0;
}
