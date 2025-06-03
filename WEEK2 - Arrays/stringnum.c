#include <stdio.h>
#include <cs50.h>

int length(string no);

int main(){

string yes = get_string("Name: ");
int leng = length(yes);
printf("%d", leng);


    return 0;
}

int length(string no){
int n=0;
while(no[n] != '\0'){
    n= n+1;
}
return n;
}

