#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp[3];
    for (int row = 0; row < height; row += 1)
    {
        for (int column = 0; column < (width / 2); column += 1)
        {

            temp[0] = image[row][column].rgbtBlue;
            temp[1] = image[row][column].rgbtGreen;
            temp[2] = image[row][column].rgbtRed;

            image[row][column].rgbtBlue = image[row][width - column - 1].rgbtBlue;
            image[row][column].rgbtGreen = image[row][width - column - 1].rgbtGreen;
            image[row][column].rgbtRed = image[row][width - column - 1].rgbtRed;

            image[row][width - column - 1].rgbtBlue = temp[0];
            image[row][width - column - 1].rgbtGreen = temp[1];
            image[row][width - column - 1].rgbtRed = temp[2];
        }
    }
    return;
}

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int row = 0; row < height; row += 1)
    {
        for (int column = 0; column < width; column += 1)
        {
            int red = image[row][column].rgbtRed;
            int green = image[row][column].rgbtGreen;
            int blue = image[row][column].rgbtBlue;

            float average = (red + green + blue) / 3.0;
            int final_average = (int)(average + 0.5f);

            image[row][column].rgbtRed = final_average;
            image[row][column].rgbtGreen = final_average;
            image[row][column].rgbtBlue = final_average;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    typedef struct
    {
        int row;
        int column;
    } tuple;

    tuple T[9];

    T[0].row = 1;
    T[0].column = 0;

    T[1].row = -1;
    T[1].column = 0;

    T[2].row = 0;
    T[2].column = 1;

    T[3].row = 0;
    T[3].column = -1;

    T[4].row = 0;
    T[4].column = 0;

    T[5].row = -1;
    T[5].column = -1;

    T[6].row = +1;
    T[6].column = +1;

    T[7].row = -1;
    T[7].column = +1;

    T[8].row = +1;
    T[8].column = -1;

    for (int row = 0; row < height; row += 1)
    {
        for (int column = 0; column < width; column += 1)
        {
            int red_total = 0;
            int blue_total = 0;
            int green_total = 0;
            int neighbours_total = 0;

            for (int i = 0; i < 9; i += 1)
            {
                // Find the neighbours just like in breadth first search
                if ((row + T[i].row) < height && (row + T[i].row) >= 0 && (column + T[i].column) < width && (column + T[i].column) >= 0)
                {
                    // printf("(%i - %i) \n", T[i].row, T[i].column);
                    // Within boundary
                    red_total += image[row + T[i].row][column + T[i].column].rgbtRed;
                    green_total += image[row + T[i].row][column + T[i].column].rgbtGreen;
                    blue_total += image[row + T[i].row][column + T[i].column].rgbtBlue;

                    neighbours_total += 1;
                }
            }

            temp[row][column].rgbtRed = round(red_total / (float)neighbours_total);
            temp[row][column].rgbtGreen = round(green_total / (float)neighbours_total);
            temp[row][column].rgbtBlue = round(blue_total / (float)neighbours_total);
        }
    }

    // Copy blurred image array to normal image array
    for (int row = 0; row < height; row += 1)
    {
        for (int column = 0; column < width; column += 1)
        {
            image[row][column] = temp[row][column];
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    int GX_ARRAY[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int GY_ARRAY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    RGBTRIPLE temp[height][width];

    for (int row = 0; row < height; row += 1)
    {
        for (int column = 0; column < width; column += 1)
        {
            float gx_red = 0, gx_green = 0, gx_blue = 0;
            float gy_red = 0, gy_green = 0, gy_blue = 0;

            for (int r = -1; r < 2; r += 1)
            {
                for (int c = -1; c < 2; c += 1)
                {
                    if ((row + r < height && row + r >= 0) && (column + c < width && column + c >= 0))
                    {
                        gx_blue += image[row + r][column + c].rgbtBlue * GX_ARRAY[r + 1][c + 1];
                        gy_blue += image[row + r][column + c].rgbtBlue * GY_ARRAY[r + 1][c + 1];

                        gx_green += image[row + r][column + c].rgbtGreen * GX_ARRAY[r + 1][c + 1];
                        gy_green += image[row + r][column + c].rgbtGreen * GY_ARRAY[r + 1][c + 1];

                        gx_red += image[row + r][column + c].rgbtRed * GX_ARRAY[r + 1][c + 1];
                        gy_red += image[row + r][column + c].rgbtRed * GY_ARRAY[r + 1][c + 1];
                    }
                }
            }

            // combine Gx and Gy into a single value.
            int red = round(sqrt(gx_red * gx_red + gy_red * gy_red));
            int green = round(sqrt(gx_green * gx_green + gy_green * gy_green));
            int blue = round(sqrt(gx_blue * gx_blue + gy_blue * gy_blue));

            // And since channel values can only take on integer values from 0 to 255,
            // be sure the resulting value is rounded to the nearest integer and capped at 255!
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }

            temp[row][column].rgbtRed = red;
            temp[row][column].rgbtGreen = green;
            temp[row][column].rgbtBlue = blue;
        }
    }

    // Copy edged image array to normal image array
    for (int row = 0; row < height; row += 1)
    {
        for (int column = 0; column < width; column += 1)
        {
            image[row][column].rgbtBlue = temp[row][column].rgbtBlue;
            image[row][column].rgbtGreen = temp[row][column].rgbtGreen;
            image[row][column].rgbtRed = temp[row][column].rgbtRed;
        }
    }

    return;
}
