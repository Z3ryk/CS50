#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;
    int count = 0;
    do
    {
        card_number = get_long("Number: ");
    }
    while (card_number < 0);

    int val[] = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    int check_sum = 0;

    for (long n = card_number; n; n /= 100)
    {
        check_sum += n % 10 + val[n / 10 % 10];
    }

    if (check_sum % 10 != 0) // Проверка на 0
    {
        printf("INVALID\n");
        return 0;
    }

    while (card_number >= 100) // Ловим первые две цифры карты и считаем кол-во цифр в карте
    {
        card_number /= 10;
        count++;
    }

    if (count < 11) // проверка на кол-во цифр в карте
    {
        printf("INVALID\n");
        return 0;
    }

    if (count == 11) //  Проверка на 13-значную визу
    {
        if (card_number / 10 == 4)
        {
            printf("VISA\n");
            return 0;
        }

        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (count == 13) // Проверка на AMEX
    {
        if (card_number == 34 || card_number == 37)
        {
            printf("AMEX\n");
            return 0;
        }

        else
        {
            printf("INVALID\n");
            return 0;
        }
    }

    if (count == 14) // Проверка на Мастеркард и Визу
    {
        if (card_number == 51 || card_number == 52 || card_number == 53 || card_number == 54 ||
            card_number == 55)
        {
            printf("MASTERCARD\n");
            return 0;
        }

        else if (card_number / 10 == 4)
        {
            printf("VISA\n");
            return 0;
        }

        else
        {
            printf("INVALID\n");
            return 0;
        }
    }
}
