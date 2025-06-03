#include <stdio.h>
#include <cs50.h>

int main(void){

int change;

do{
change = get_int("Change owed in cents: ");
}while (change < 0);

//check50 cs50/problems/2024/x/cash
//submit50 cs50/problems/2024/x/cash
int coins =0;

while(change>0){
if(change >= 25){

    coins=coins+1;
    change=change-25;
}

/*If the first if else statement is true, the next else if (change_owed >= 10) and others are ignored because the program already executed the if block.
After subtracting, the loop goes back to the top and starts the next iteration.*/

else if(change >=10){
    coins=coins+1;
    change=change-10;
}\

else if(change >=5){
    coins=coins+1;
    change=change-5;
}

else if(change >=1){
    coins=coins+1;
    change=change-1;
}
else if(change == 0){
    coins=coins+0;
    change=change-0;
}

}

printf("%d coins", coins);
    return 0;
}
