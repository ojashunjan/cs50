#include "helpers.h"
#include <math.h>

// func

void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE r = image[i][j].rgbtRed;
            BYTE g = image[i][j].rgbtGreen;
            BYTE b = image[i][j].rgbtBlue;

            BYTE avg = round((r + g + b) / 3.0);

            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
}

void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int r = image[i][j].rgbtRed;
            int g = image[i][j].rgbtGreen;
            int b = image[i][j].rgbtBlue;

            int nr = round(.393 * r + .769 * g + .189 * b);
            int ng = round(.349 * r + .686 * g + .168 * b);
            int snb = round(.272 * r + .534 * g + .131 * b);

            image[i][j].rgbtRed = nr > 255 ? 255 : nr;
            image[i][j].rgbtGreen = ng > 255 ? 255 : ng;
            image[i][j].rgbtBlue = snb > 255 ? 255 : snb;
        }
    }
}

void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE t = image[i][j];

            image[i][j] = image[i][width - j - 1];

            image[i][width - j - 1] = t;
        }
    }
}


void blur(int height, int width, RGBTRIPLE image[height][width])
{

    RGBTRIPLE movef[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            movef[i][j] = image[i][j];
        }
    }


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int rs = 0;
            int gs = 0;
            int bs = 0;
            int c = 0;

          
            for (int k = -1; k<= 1; k++)
            {
                for (int m= -1; m <= 1; m++)
                {
                    int n = i + k;
                    int o = j + m;

                    if (n >= 0 && n < height && o >= 0 && o < width)
                    {
                        rs = rs + movef[n][o].rgbtRed;
                        gs = gs +movef[n][o].rgbtGreen;
                        bs = bs +movef[n][o].rgbtBlue;
                        c++;
                    }
                }
            }

            image[i][j].rgbtRed = round((float) rs / c);

            image[i][j].rgbtGreen = round((float) gs / c);

            image[i][j].rgbtBlue = round((float) bs / c);
        }
    }
}
