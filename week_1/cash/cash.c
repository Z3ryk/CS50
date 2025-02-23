#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int change_owed;

    do
    {
        change_owed = get_int("Change owed: ");
    }
    while (change_owed < 0);

    int number_of_quarters = 0; // 25 cents
    int number_of_dimes = 0;    // 10 cents
    int number_of_nickels = 0;  // 5 cents
    int number_of_pennies = 0;  // 1 cent

    while (25 <= change_owed)
    {
        change_owed -= 25;
        number_of_quarters++;
    }

    while (10 <= change_owed)
    {
        change_owed -= 10;
        number_of_dimes++;
    }

    while (5 <= change_owed)
    {
        change_owed -= 5;
        number_of_nickels++;
    }

    while (1 <= change_owed)
    {
        change_owed -= 1;
        number_of_pennies++;
    }

    int total_number_of_coins =
        number_of_quarters + number_of_dimes + number_of_nickels + number_of_pennies; // Сумма монет

    printf("%i\n", total_number_of_coins);
}
