#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Open memory card
    FILE *f = fopen("card.raw", "r");
    FILE *img = NULL;

    //returns 1 if file can't be opened or too few arguments
    if (f == NULL || argc != 2)
    {
        return 1;
    }

    uint8_t blockBuffer[512]; // Buffer for image with 512 bytes
    int number; // Count of how many valid reads overall
    int count=-1; //counts how many jpeg


    //loop to repeat until end of card while also reading 512 into buffer
    while ((number = fread(blockBuffer, 512, 1, f)) > 0){

        //checks if start of new jpeg
        if (blockBuffer[0]==0xff && blockBuffer[1] == 0xd8 && blockBuffer[2] == 0xff && (blockBuffer[3]&0xf0)==0xe0){

            //checks if a file has been opened
            if (img != NULL){
                fclose(img);
            }

            //adds to count of jpg
            count++;

            //makes a new file and writes on it
            char filename[20];
            sprintf(filename, "%03i.jpg",count);
            img = fopen(filename, "w");
            fwrite(blockBuffer,512,1,img);
        }
        else{
            //checks if a file has been opened
            if (img != NULL){
                //if still open, continue writing
                fwrite(blockBuffer,512,1,img);
            }
        }
    }
    //closes everything for safety
    fclose(f);
    fclose(img);
    return 0;
}
