#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;
            int red = image[i][j].rgbtRed;

            int average = round((float) (blue + green + red) / 3);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            int sepiaRed =
                round(0.393 * originalRed + 0.769 * originalGreen + 0.189 * originalBlue);
            int sepiaGreen =
                round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);
            int sepiaBlue =
                round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);

            const int max_value = 255;

            if (sepiaRed > max_value)
            {
                sepiaRed = max_value;
            }

            if (sepiaGreen > max_value)
            {
                sepiaGreen = max_value;
            }

            if (sepiaBlue > max_value)
            {
                sepiaBlue = max_value;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        RGBTRIPLE *row = &image[i][0];

        int left = 0;
        int right = width - 1;

        while (left < right)
        {
            RGBTRIPLE tmp = row[left];
            row[left] = row[right];
            row[right] = tmp;

            left++;
            right--;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Создаём временную матрицу для хранения исходных значений
    RGBTRIPLE original[height][width];

    // Копируем исходное изображение
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            original[i][j] = image[i][j];
        }
    }

    // Проходим по каждому пикселю
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Инициализируем переменные для суммы цветов
            int redSum = 0;
            int greenSum = 0;
            int blueSum = 0;
            int count = 0;

            // Проходим по соседним пикселям (3x3 окно)
            for (int x = i - 1; x <= i + 1; x++)
            {
                for (int y = j - 1; y <= j + 1; y++)
                {
                    // Проверяем, что пиксель находится в границах изображения
                    if (x >= 0 && x < height && y >= 0 && y < width)
                    {
                        // Добавляем значения цветов соседних пикселей
                        redSum += round((float) original[x][y].rgbtRed);
                        greenSum += round((float) original[x][y].rgbtGreen);
                        blueSum += round((float) original[x][y].rgbtBlue);
                        count++;
                    }
                }
            }
            // Вычисляем среднее значение для каждого канала
            image[i][j].rgbtRed = round((float) redSum / count);
            image[i][j].rgbtGreen = round((float) greenSum / count);
            image[i][j].rgbtBlue = round((float) blueSum / count);
        }
    }

    return;
}
