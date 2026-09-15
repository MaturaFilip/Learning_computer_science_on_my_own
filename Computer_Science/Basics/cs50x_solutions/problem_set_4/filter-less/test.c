int tmp_red = image[i][j].rgbtRed;
image[i][j].rgbtRed = image[i][width-j].rgbtRed;
image[i][width-j].rgbtRed = tmp_red;

int tmp_blue = image[i][j].rgbtBlue;
image[i][j].rgbtBlue = image[i][width-j].rgbtBlue;
image[i][width-j].rgbtBlue = tmp_blue;

int tmp_green = image[i][j].rgbtGreen;
image[i][j].rgbtGreen = image[i][width-j].rgbtGreen;
image[i][width-j].rgbtGreen = tmp_green;

