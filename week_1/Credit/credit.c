#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int count = 0;
    long card;

    do
    {
        card = get_long("Number: ");
    }
    while (card < 0);

    long check = card;

    int card1 = (((card % 100) / 10) * 2); // Умножение цифр начиная предпоследней на 2
    int card2 = (((card % 10000) / 1000) * 2);
    int card3 = (((card % 1000000) / 100000) * 2);
    int card4 = (((card % 100000000) / 10000000) * 2);
    int card5 = (((card % 10000000000) / 1000000000) * 2);
    int card6 = (((card % 1000000000000) / 100000000000) * 2);
    int card7 = (((card % 100000000000000) / 10000000000000) * 2);
    int card8 = (((card % 10000000000000000) / 1000000000000000) * 2);

    card1 = (card1 % 100 / 10) + (card1 % 10); // Сложение цифр вместе
    card2 = (card2 % 100 / 10) + (card2 % 10);
    card3 = (card3 % 100 / 10) + (card3 % 10);
    card4 = (card4 % 100 / 10) + (card4 % 10);
    card5 = (card5 % 100 / 10) + (card5 % 10);
    card6 = (card6 % 100 / 10) + (card6 % 10);
    card7 = (card7 % 100 / 10) + (card7 % 10);
    card8 = (card8 % 100 / 10) + (card8 % 10);

    int card_no = card1 + card2 + card3 + card4 + card5 + card6 + card7 + card8;

    int non_mult =
        (card % 10) + ((card % 1000) / 100) + ((card % 100000) / 10000) +
        ((card % 10000000) / 1000000) + ((card % 1000000000) / 100000000) +
        ((card % 100000000000) / 10000000000) + ((card % 10000000000000) / 1000000000000) +
        ((card % 1000000000000000) / 100000000000000); // Сложение чисел которые не умножались

    int check_sum = card_no + non_mult; // Проверочная сумма умноженных и не умноженных чисел

    if ((check_sum % 10) != 0) // Проверка заканичивается ли сумма на 0 в конце
    {
        printf("INVALID\n");
        return 0;
    }

    while (check > 0) // Проверка на кол-во цифр в номере карты
    {
        check = check / 10; //
        count++;            //
    }

    if (count != 15 && count != 13 &&
        count != 16) // Проверка на то чтобы в номере карты было 15,13,16 цифр.
    {
        printf("INVALID\n");
        return 0;
    }

    long MC = card / 100000000000000;    // проверка на первые две цифры MASTER
    long AMEX = card / 10000000000000;   // проверка на первые две цифры AMERICAN EXPRESS
    long Visa = card / 1000000000000000; // проверка на первую цифру VISA
    long Visa_13 = card / 1000000000000; // проверка на первую цифру VISA 13-значная карта

    if (count == 15)
    {
        if (AMEX != 34 && AMEX != 37) // Проверка на первые две цифры чтобы были 34 или 37
        {
            printf("INVALID\n");
            return 0;
        }

        else
        {
            printf("AMEX\n");
            return 0;
        }
    }

    if (count == 16)
    {
        if (MC == 51 || MC == 52 || MC == 53 || MC == 54 ||
            MC == 55) // Проверка на Master_card 51, 52, 53, 54, 55.
        {
            printf("MASTERCARD\n");
            return 0;
        }

        else if (Visa == 4) // Проверка на Visa 4
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

    if (count == 13 && Visa_13 == 4) // Вторая проверка на VISA если карта 13-значная
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
