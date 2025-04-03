#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average_pixel_value =
                (image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3;
            image[i][j].rgbtRed = average_pixel_value;
            image[i][j].rgbtGreen = average_pixel_value;
            image[i][j].rgbtBlue = average_pixel_value;
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

            int sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue;
            int sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue;
            int sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue;

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
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

        for (; left < right; left++, right--)
        {
            RGBTRIPLE tmp = row[left];
            row[left] = row[right];
            row[right] = tmp;
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
                        redSum += original[x][y].rgbtRed;
                        greenSum += original[x][y].rgbtGreen;
                        blueSum += original[x][y].rgbtBlue;
                        count++;
                    }
                }
            }

            // Вычисляем среднее значение для каждого канала
            image[i][j].rgbtRed = redSum / count;
            image[i][j].rgbtGreen = greenSum / count;
            image[i][j].rgbtBlue = blueSum / count;
        }
    }
    return;
}
