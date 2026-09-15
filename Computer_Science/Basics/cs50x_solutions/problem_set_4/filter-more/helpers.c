#include "helpers.h"
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

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

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // gx
    int gx_red, gx_blue, gx_green;
    int gx_matrix[3][3] = {
        {-1, 0, 1},
        {-2, 0, 2},
        {-1, 0, 1}
    };

    // gy
    int gy_red, gy_blue, gy_green;
    int gy_matrix[3][3] = {
        {-1, -2, -1},
        {0, 0, 0},
        {1, 2, 1}
    };

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

            // populate mask
            for (int k = 0; k < MASK_HEIGHT; k++) {
                for (int l = 0; l < MASK_WIDTH; l++) {
                    if (!mask_bool[k][l]) {
                        mask[k][l].rgbtRed = 0;
                        mask[k][l].rgbtGreen = 0;
                        mask[k][l].rgbtBlue = 0;
                    }
                }
            }
            gy_red = 0, gy_green = 0, gy_blue = 0;
            gx_red = 0, gx_green = 0, gx_blue = 0;

            for (int k = 0; k < MASK_HEIGHT; k++) {
                for (int l = 0; l < MASK_WIDTH; l++) {
                    gy_red += mask[k][l].rgbtRed * gy_matrix[k][l];
                    gy_green += mask[k][l].rgbtGreen * gy_matrix[k][l];
                    gy_blue += mask[k][l].rgbtBlue * gy_matrix[k][l];

                    gx_red += mask[k][l].rgbtRed * gx_matrix[k][l];
                    gx_green += mask[k][l].rgbtGreen * gx_matrix[k][l];
                    gx_blue += mask[k][l].rgbtBlue * gx_matrix[k][l];
                }
            }
            int r = round(sqrt((gy_red * gy_red) + (gx_red * gx_red)));
            int g = round(sqrt((gy_green * gy_green) + (gx_green * gx_green)));
            int b = round(sqrt((gy_blue * gy_blue) + (gx_blue * gx_blue)));
            image[i][j].rgbtRed = (r <= 255) ? r : 255;
            image[i][j].rgbtGreen = (g <= 255) ? g : 255;
            image[i][j].rgbtBlue = (b <= 255) ? b : 255;
            //c = (a < b) ? a : b;

        }
    }
    return;
}

