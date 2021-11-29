/*
Objective: Write a program to modify the volume of an audio file.

helpers.h
Next, take a look at helpers.h. This file is quite short, and just provides the function prototypes for the functions you saw earlier.
Here, take note of the fact that each function takes a 2D array called image as an argument, where image is an array of height many rows, and each row is itself another array of width many RGBTRIPLEs. So if image represents the whole picture, then image[0] represents the first row, and image[0][0] represents the pixel in the upper-left corner of the image.

helpers.c
Now, open up helpers.c. Here’s where the implementation of the functions declared in helpers.h belong. But note that, right now, the implementations are missing! This part is up to you.
*/

#include "helpers.h"
#include <math.h>
#include <cs50.h>

// Convert image to grayscale by finding the average of the original colors within the given pixel. And changing each scale to the average to change the grayness of the of the entire pixel
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE pixel = image[i][j];
            // calculate the average of the red, green, and blue values and set the all values equal to the average
            int avg = round((pixel.rgbtBlue + pixel.rgbtRed + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

// If value is greater than 255, then return 255. Else, leave it as is.
int max(int value) {
    if (value > 255) {
        return 255;
    }
    else {
        return value;
    }
}

// Convert each pixel to corresponding sepia color by taking all the orginal colors and using the given formula to assign the new pixel color for the particular color.
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            RGBTRIPLE pixel = image[i][j];
            // perform the sepia formula to get the new color of the given pixel and round to the nearest tenth
            image[i][j].rgbtRed = max(round((0.393 * pixel.rgbtRed) + (0.769 * pixel.rgbtGreen) + (0.189 * pixel.rgbtBlue)));
            image[i][j].rgbtGreen = max(round((0.349 * pixel.rgbtRed) + (0.686 * pixel.rgbtGreen) + (0.168 * pixel.rgbtBlue)));
            image[i][j].rgbtBlue = max(round((0.272 * pixel.rgbtRed) + (0.534 * pixel.rgbtGreen) + (0.131 * pixel.rgbtBlue)));
        }
    }
    return;
}

// swap the addesses of the values at the given pixels by using pointers
void swap(RGBTRIPLE * older, RGBTRIPLE * newer) {
    RGBTRIPLE temp = *older;
    *older = *newer;
    *newer = temp;
}

// Reflect image horizontally by iterating over only half of the image's width and swapping the corresponding addresses of the pixels
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width / 2; j++) {
            // use the swap function to reflect the image
            swap(&image[i][j], &image[i][width - 1 - j]);
        }
    }
    return;
}

// check if the blurred pixel is valid
bool valid(int i, int j, int height, int width) {
    if (i >= 0 && i < height && j >= 0 && j < width) {
        return true;
    }
    else {
        return false;
    }
}


// the image will become blurred by moving back and forth in the row and the column to each different colored and adding the necessary amount to each color to blur the surrounding area
RGBTRIPLE blurred(int i, int j, int height, int width, RGBTRIPLE image[height][width]) {
    int r = 0;
    int g = 0;
    int bl = 0;
    int validPixels = 0;
    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            int bluri = i + a;
            int blurj = j + b;
            if (valid(bluri, blurj, height, width)) {
               validPixels++;
               r += image[bluri][blurj].rgbtRed;
               g += image[bluri][blurj].rgbtGreen;
               bl += image[bluri][blurj].rgbtBlue;
            }
        }
    }
    RGBTRIPLE blurredPixel;
    blurredPixel.rgbtRed = round((float) r / validPixels);
    blurredPixel.rgbtGreen = round((float) g / validPixels);
    blurredPixel.rgbtBlue = round((float) bl / validPixels);
    return blurredPixel;
}

// Blur image storing the original image and copying the new values into it
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // declare the new image to make the blur effect changes in
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy[i][j] = blurred(i, j, height, width, image);
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j] = copy[i][j];
        }
    }
    return;
}
