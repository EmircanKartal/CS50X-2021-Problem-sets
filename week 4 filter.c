#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            int average = round((pixel.rgbtRed + pixel.rgbtBlue + pixel.rgbtGreen) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtGreen = image[i][j].rgbtBlue = average;
        }
    }
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

            if (image[i][j].rgbtRed > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            if (image[i][j].rgbtGreen > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            if (image[i][j].rgbtBlue > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temporary = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temporary;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE image_copy[height][width];
    memcpy(image_copy, image, sizeof(RGBTRIPLE) * height * width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;
            float blueSum = 0;
            float redSum = 0;
            float greenSum = 0;

            for (int k = i - 1; k <= i + 1; k++)
            {
                if (k < 0)
                {
                    continue;
                }

                if (k > height)
                {
                    break;
                }

                for (int l = j - 1; l <= j + 1; l++)
                {
                    if (l < 0)
                    {
                        continue;
                    }

                    if (l > width)
                    {
                        break;
                    }

                    blueSum += image_copy[k][l].rgbtBlue;
                    greenSum += image_copy[k][l].rgbtGreen;
                    redSum += image_copy[k][l].rgbtRed;
                    count++;
                }
            }

            image[i][j].rgbtBlue = round(blueSum / count);
            image[i][j].rgbtRed = round(redSum / count);
            image[i][j].rgbtGreen = round(greenSum / count);
        }
    }
}
