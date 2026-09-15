#include "helpers.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

#define MASK_HEIGHT 3
#define MASK_WIDTH 3

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int avg = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);
            image[i][j].rgbtRed = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtBlue = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int s_red = round((image[i][j].rgbtRed * 0.393) + (image[i][j].rgbtGreen * 0.769) + (image[i][j].rgbtBlue * 0.189));
            int s_green = round((image[i][j].rgbtRed * 0.349) + (image[i][j].rgbtGreen * 0.686) + (image[i][j].rgbtBlue * 0.168));
            int s_blue = round((image[i][j].rgbtRed * 0.272) + (image[i][j].rgbtGreen * 0.534) + (image[i][j].rgbtBlue * 0.131));
            if (s_red > 255) {
                s_red = 255;
            }

            if (s_green > 255) {
                s_green = 255;
            }

            if (s_blue > 255) {
                s_blue = 255;
            }

            image[i][j].rgbtRed = s_red;
            image[i][j].rgbtGreen = s_green;
            image[i][j].rgbtBlue = s_blue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int left;
    int right;
    for (int i = 0; i < height; i++) {
        left = 0;
        right = width - 1;
        while (left < right) {
            RGBTRIPLE temp = image[i][left];
            image[i][left] = image[i][right];
            image[i][right] = temp;
            left++;
            right--;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE mask[MASK_HEIGHT][MASK_WIDTH];
    bool mask_bool[MASK_HEIGHT][MASK_WIDTH];
    RGBTRIPLE copy_image[height][width];
    int red, green, blue, total_pixels;

    // copy image array
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            copy_image[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            // reset bool mask
            for (int k = 0; k < MASK_HEIGHT; k++) {
                for (int l = 0; l < MASK_WIDTH; l++) {
                    mask_bool[k][l] = false;
                }
            }

            // reset colors
            red = 0, green = 0, blue = 0, total_pixels = 0;

            // populate mask
            if ((i - 1) >= 0 && (j - 1) >= 0) { mask[0][0] = copy_image[i - 1][j - 1]; mask_bool[0][0] = true; }
            if ((i - 1) >= 0) { mask[0][1] = copy_image[i - 1][j]; mask_bool[0][1] = true;}
            if ((i - 1) >= 0 && (j + 1) < width) { mask[0][2] = copy_image[i - 1][j + 1]; mask_bool[0][2] = true; }
            if ((j - 1) >= 0) { mask[1][0] = copy_image[i][j - 1]; mask_bool[1][0] = true; }
            mask[1][1] = copy_image[i][j];
            mask_bool[1][1] = true;
            if ((j + 1) < width) { mask[1][2] = copy_image[i][j + 1]; mask_bool[1][2] = true; }
            if ((i + 1) < height && (j - 1) >= 0) { mask[2][0] = copy_image[i + 1][j - 1]; mask_bool[2][0] = true; }
            if ((i + 1) < height) { mask[2][1] = copy_image[i + 1][j]; mask_bool[2][1] = true; }
            if ((i + 1) < height && (j + 1) < width) { mask[2][2] = copy_image[i + 1][j + 1]; mask_bool[2][2] = true; }


            for (int k = 0; k < MASK_HEIGHT; k++) {
                for (int l = 0; l < MASK_WIDTH; l++) {
                    if (mask_bool[k][l]) {
                        red += mask[k][l].rgbtRed;
                        green += mask[k][l].rgbtGreen;
                        blue += mask[k][l].rgbtBlue;
                        total_pixels += 1;

                    }
                }
            }
            image[i][j].rgbtRed = round(red / (float) total_pixels);
            image[i][j].rgbtGreen = round(green / (float) total_pixels);
            image[i][j].rgbtBlue = round(blue / (float) total_pixels);
        }
    }
    return;
}

