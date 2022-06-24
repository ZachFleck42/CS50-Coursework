#include <math.h>

#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int pixelAvg = round(((float)image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);

            image[i][j].rgbtRed = pixelAvg;
            image[i][j].rgbtGreen = pixelAvg;
            image[i][j].rgbtBlue = pixelAvg;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float totalRed = 0;
            float totalGreen = 0;
            float totalBlue = 0;
            int counter = 0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    if (i + x < 0 || i + x >= height)
                    {
                        continue;
                    }

                    if (j + y < 0 || j + y >= width)
                    {
                        continue;
                    }

                    totalRed += copy[i + x][j + y].rgbtRed;
                    totalGreen += copy[i + x][j + y].rgbtGreen;
                    totalBlue += copy[i + x][j + y].rgbtBlue;
                    counter++;
                }
            }

            image[i][j].rgbtRed = round(totalRed / counter);
            image[i][j].rgbtGreen = round(totalGreen / counter);
            image[i][j].rgbtBlue = round(totalBlue / counter);
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int gxValues[9] = {-1, 0, 1, -2, 0, 2, -1, 0, 1};
    int gyValues[9] = {-1, -2, -1, 0, 0, 0, 1, 2, 1};

    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float gxRed = 0;
            float gyRed = 0;
            float gxGreen = 0;
            float gyGreen = 0;
            float gxBlue = 0;
            float gyBlue = 0;

            int totalRed = 0;
            int totalGreen = 0;
            int totalBlue = 0;

            int posCounter = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {

                    if (i + k < 0 || i + k >= height)
                    {
                        posCounter++;
                    }
                    else if (j + l < 0 || j + l >= width)
                    {
                        posCounter++;
                    }
                    else
                    {
                        gxRed += gxValues[posCounter] * copy[i + k][j + l].rgbtRed;
                        gxGreen += gxValues[posCounter] * copy[i + k][j + l].rgbtGreen;
                        gxBlue += gxValues[posCounter] * copy[i + k][j + l].rgbtBlue;

                        gyRed += gyValues[posCounter] * copy[i + k][j + l].rgbtRed;
                        gyGreen += gyValues[posCounter] * copy[i + k][j + l].rgbtGreen;
                        gyBlue += gyValues[posCounter] * copy[i + k][j + l].rgbtBlue;

                        posCounter++;
                    }
                }
            }

            totalRed = round(sqrt(gxRed * gxRed + gyRed * gyRed));
            if (totalRed > 255)
            {
                totalRed = 255;
            }
            image[i][j].rgbtRed = totalRed;

            totalGreen = round(sqrt(gxGreen * gxGreen + gyGreen * gyGreen));
            if (totalGreen > 255)
            {
                totalGreen = 255;
            }
            image[i][j].rgbtGreen = totalGreen;

            totalBlue = round(sqrt(gxBlue * gxBlue + gyBlue * gyBlue));
            if (totalBlue > 255)
            {
                totalBlue = 255;
            }
            image[i][j].rgbtBlue = totalBlue;
        }
    }

    return;
}