#include <stdio.h>
#include <cs50.h>

typedef struct{

    string name;
    int votes;

}candidate;

bool vote(string name, int number){

    for (int i=0; i< num_candidates; i++){
        if (name == candidates.name[i]){
            return true;
        }
        else{
            return false;
        }
    }

}
int main(){
const int num_candidates = 3;
candidate candidates[num_candidates];//made an array of candidate name candidates
int NumVoters = 0;

candidate candidates.name[0]="Albert";
candidate candidates.votes[0]=0;

candidate candidates.name[1]="Bob";
candidate candidates.votes[1]=0;

candidate candidates.name[2]="Charles";
candidate candidates.votes[2]=0;

printf("Number of Voters: ");
scanf("%d", &NumVoters);

for (int i=0; i<NumVoters; i++){
    

}

    return 0;
}
