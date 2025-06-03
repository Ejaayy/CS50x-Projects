#include <stdio.h>
#include <cs50.h>

int main(void)
{

    int x = get_int ("what's x? ");
    int y = get_int ("What's y? ");

    if (x < y){
        printf("x is less than y\n");
    }
    else if (x > y){
        printf("x is more than y\n");
    }
    else if (x == y){
        printf("x is equal to y\n");
    }
//its actually better to just make it else than else if for the third
    return 0;
}
