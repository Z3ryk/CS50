#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int s;
    do
    {
        s = get_int("Height: "); // задать высоту пирамидки
    }
    while (s <= 0);
    for (int i = 1; i <= s; i++)
    {
        int space = i <= s ? s - i : 0; // расчет количества пробелов

        for (int j = 0; j < space; j++) // печать пробелов
        {
            printf(" ");
        }
        for (int resh = 1; resh <= i; resh++) // печать решеток
        {
            printf("#");
        }
        printf("  "); // разделение пирамидок

        for (int k = 1; k <= i; k++) // то же самое, но в обратном порядке
        {
            printf("#");
        }

        printf("\n");
    }
}
