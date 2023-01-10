#include <stdio.h>
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtBlue + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
}

int cap(int value)
{
    return value > 255 ? 255 : value;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int OGRed = pixel.rgbtRed;
            int OGBlue = pixel.rgbtBlue;
            int OGGreen = pixel.rgbtGreen;

            image[i][j].rgbtRed = round(0.393 * OGRed + 0.769 * OGGreen + 0.189 * OGBlue);
            image[i][j].rgbtGreen = round(0.349 * OGRed + 0.686 * OGGreen + 0.168 * OGBlue);
            image[i][j].rgbtBlue = round(0.272 * OGRed + 0.534 * OGGreen + 0.131 * OGBlue);

        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
