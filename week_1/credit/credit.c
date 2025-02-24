#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long card_number;

    do
    {
        card_number = get_long("Enter card number: ");
    }
    while (card_number < 0);

    long temp_card_number = card_number;
    int sum1 = 0;
    int sum2 = 0;
    int position = 0;

    while (temp_card_number > 0)
    {
        int last_digit = temp_card_number % 10;

        if (position % 2 == 0)
        {
            sum1 += last_digit;
        }
        else
        {
            int last_digit_multiplied = last_digit * 2;
            sum2 += (last_digit_multiplied % 10) + (last_digit_multiplied / 10);
        }

        temp_card_number /= 10;
        position++;
    }

    if ((sum1 + sum2) % 10 != 0) // проверка на кратность 10
    {
        printf("INVALID\n");
        return 0;
    }

    int card_number_length = 2;

    while (card_number >= 100) // ловим первые две цифры карты и считаем количество цифр в карте
    {
        card_number /= 10;
        card_number_length++;
    }

    int first_two_digits = card_number;
    int first_digit = first_two_digits / 10;

    if (card_number_length == 15 &&
        (first_two_digits == 34 || first_two_digits == 37)) // проверка на AMEX
    {
        printf("AMEX\n");
    }
    else if (card_number_length == 16 &&
             (first_two_digits >= 51 && first_two_digits <= 55)) // проверка на MASTERCARD
    {
        printf("MASTERCARD\n");
    }
    else if ((card_number_length == 13 || card_number_length == 16) &&
             first_digit == 4) // проверка на VISA
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
