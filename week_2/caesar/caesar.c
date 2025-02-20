#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])

{
    // Проверка на количество аргументов
    if (argc != 2)
    {
        printf("Usage: ./ceasar k\n");
        return 1;
    }

    // Проверка является ли аргумент буквенным
    for (int key = 0; key < strlen(argv[1]); key++)
    {
        if (isalpha(argv[1][key]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argv[1]) % 26; // Конвертация строки в число

    // Запрос на ввод текста
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Перебор каждой буквы в тексте
    for (int i = 0, length = strlen(plaintext); i < length; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            // Выводит текущий элемент массива если он не является альфой (что такое альфа?)
            printf("%c", plaintext[i]);
            continue;
        }

        // Проверка буквы на заглавную
        int offset = isupper(plaintext[i]) ? 65 : 97;

        // Вычисление того, насколько далеко текущий элемент находится от строчной "a" или заглавной
        int pi = plaintext[i] - offset;

        // Индекс шифра
        int ci = (pi + key) % 26;

        // Печать символа в зашифрованом виде
        printf("%c", ci + offset);
    }

    printf("\n");
    return 0;
}
