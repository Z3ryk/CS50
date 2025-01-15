#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int s;
    do
    {
        s = get_int("Height: ");
    }
    while (s <= 0);
    for (int i = 1; i <= s; i++)
    {
        int space = i <= s ? s - i : 0;

        for (int j = 0; j < space; j++)
        {
            printf(" ");
        }
        for (int resh = 1; resh <= i; resh++)
        {
            printf("#");
        }
        printf("\n");
    }
}

