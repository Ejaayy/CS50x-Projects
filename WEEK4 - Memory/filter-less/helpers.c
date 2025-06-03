#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
/*  //Loop over all pixels
    // Take average of red, green, and blue
    // Update pixel values

    BYTE  rgbtBlue;
    BYTE  rgbtGreen;
    BYTE  rgbtRed;
*/

    for (int i = 0; i<height; i++){
        for (int j = 0; j<width;j++){

            float average = (image[i][j].rgbtRed + image[i][j].rgbtBlue + image[i][j].rgbtGreen)/3.0;

            image[i][j].rgbtRed = (int)round(average);
            image[i][j].rgbtBlue = (int)round(average);
            image[i][j].rgbtGreen = (int)round(average);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i<height; i++){
        for (int j = 0; j<width;j++){

            //formula or algorithm for sepia pixel colors;

            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            //capped at 255
            if (sepiaRed > 255){
                sepiaRed = 255;
            }
            if(sepiaBlue > 255){
                sepiaBlue = 255;
            }
            if(sepiaGreen > 255){
                sepiaGreen = 255;
            }

            //updates the pixels
            image[i][j].rgbtRed = (int)round(sepiaRed);
            image[i][j].rgbtBlue = (int)round(sepiaBlue);
            image[i][j].rgbtGreen = (int)round(sepiaGreen);
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempImage[height][width];
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            tempImage[i][j] = image[i][width-1-j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = tempImage[i][j];
        }
    }


    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)//row of main pixel
    {
        for (int j = 0; j < width; j++)//column of main pixel
        {
            float redsum = 0;
            float bluesum = 0;
            float greensum = 0;
            int count = 0;

            for (int k = -1; k<=1;k++){ //k is for row of sorrounding pixel
                for (int l = -1; l<=1; l++){//l is for column of sorrounding pixel
                    if (i + k >= 0 && i + k < height && j + l >= 0 && j + l < width){ //checks validity of pixel
                    //i+k is checking if pixel has valid row
                    // j+l is checking if pixel has valid column
                        redsum += copy[i+k][j+l].rgbtRed;
                        bluesum += copy[i+k][j+l].rgbtBlue;
                        greensum += copy[i+k][j+l].rgbtGreen;
                        count++;
                    }
                    else{
                        continue;
                    }
                }
            }

            float averageRed = redsum / count;
            float averageBlue = bluesum / count;
            float averageGreen = greensum / count;

            image[i][j].rgbtRed = (int)round(averageRed);
            image[i][j].rgbtBlue = (int)round(averageBlue);
            image[i][j].rgbtGreen = (int)round(averageGreen);
        }
    }

    return;
}
