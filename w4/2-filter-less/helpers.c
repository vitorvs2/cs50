#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int avg = round((r + g + b) / 3.0);

            // Update pixel values
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            // sepia calculation and 255 value limit
            int sepiaRed = round(.393 * r + .769 * g + .189 * b);
            if (sepiaRed > 255)
                sepiaRed = 255;
            int sepiaGreen = round(.349 * r + .686 * g + .168 * b);
            if (sepiaGreen > 255)
                sepiaGreen = 255;
            int sepiaBlue = round(.272 * r + .534 * g + .131 * b);
            if (sepiaBlue > 255)
                sepiaBlue = 255;

            // Update pixel values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // new limit for manipulation
            int limit = width - 1;

            // check if middle of image reached
            // if yes, break
            if (j <= limit / 2)
            {
                // temp array for storing rgb data from image
                int temp[3];

                // storing the variables from first pixel
                temp[0] = image[i][j].rgbtRed;
                temp[1] = image[i][j].rgbtGreen;
                temp[2] = image[i][j].rgbtBlue;

                // swapping first pixel data with the opposing pixel's data
                image[i][j].rgbtRed = image[i][limit - j].rgbtRed;
                image[i][j].rgbtGreen = image[i][limit - j].rgbtGreen;
                image[i][j].rgbtBlue = image[i][limit - j].rgbtBlue;

                // set the first pixel data into the opposing pixel
                image[i][limit - j].rgbtRed = temp[0];
                image[i][limit - j].rgbtGreen = temp[1];
                image[i][limit - j].rgbtBlue = temp[2];
            }
            else
            {
                // break if middle of file reached
                break;
            }
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //  variables declaration
            int r, g, b, sumR = 0, sumG = 0, sumB = 0;

            // double variable for correct division/average
            double count = 0.0;

            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    // limit the scan for fields out of the image size, beyond its borders
                    if (i + x >= 0 && i + x <= (height - 1) && j + y >= 0 && j + y <= (width - 1))
                    {
                        sumR += image[i + x][j + y].rgbtRed;
                        sumG += image[i + x][j + y].rgbtGreen;
                        sumB += image[i + x][j + y].rgbtBlue;
                        count++;
                    }
                }
            }

            // pixel average calculation with scan results
            r = round(sumR / count);
            g = round(sumG / count);
            b = round(sumB / count);

            // setting up the new pixel in temp image
            temp[i][j].rgbtRed = r;
            temp[i][j].rgbtGreen = g;
            temp[i][j].rgbtBlue = b;
        }
    }

    // transfering the temp image pixel data into the final image file data
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }
}
