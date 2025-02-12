#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 25;
    int b = 10;
    int c = 5;
    int d = 1;
    int all;
    do
    {
        all = get_int("Change owed: ");
    }
    while (all < 0);

    int cycle25 = 0;
    int cycle10 = 0;
    int cycle5 = 0;
    int cycle1 = 0;

    for (int i = 25; i <= all; i += 25) // 25 cent
    {
        cycle25++;
    }

    int all25 = all - cycle25 * 25;

    for (int i = 10; i <= all25; i += 10) // 10 cent
    {
        cycle10++;
    }

    int all10 = all25 - cycle10 * 10;

    for (int i = 5; i <= all10; i += 5) // 5 cent
    {
        cycle5++;
    }

    int all5 = all10 - cycle5 * 5;

    for (int i = 1; i <= all5; i++) // 1 cent
    {
        cycle1++;
    }

    int cycle = cycle25 + cycle10 + cycle5 + cycle1; // Сумма монет

    printf("%i\n", cycle);
}
