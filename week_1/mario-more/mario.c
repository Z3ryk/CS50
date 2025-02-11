#include <cs50.h>
#include <stdio.h>


int main(void)
{
    int height;
    char space = ' ';
    char hash ='#';

    do
    {
        height = get_int("Height: ");
    }
    while (height <= 0);

    for (int i = 0; i < height; i++)
    {

        if (i <= height)
        {

            for (int j = 0; j < height - i - 1; j++)
            {
                printf("%c", space);
            }

            for (int h = 0; h <= i; h++)
            {
                printf("%c", hash);
            }

            printf("%c%c", space, space);

            for (int h = 0; h <= i; h++)
            {
                printf("%c", hash);
            }

        }

        printf("\n");
    }
}
