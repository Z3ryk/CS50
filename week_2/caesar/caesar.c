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
        printf("Usage: ./ceasar key\n");
        return 1;
    }

    // Длину аргумента записываем в переменную
    int argument_length = strlen(argv[1]);

    // Проверка присутствуют ли в аргументе что-то кроме цифр
    for (int i = 0; i < argument_length; i++)
    {
        if (isdigit(argv[1][i]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Переводим цифры из в аргумента в число
    // Берем остаток от деления на 26 так как в англ. языке 26 букв.
    int key = atoi(argv[1]) % 26;

    // Запрос на ввод текста
    string plaintext = get_string("plaintext: ");

    printf("ciphertext: ");

    // Присваиваемм переменной длину строки plaintext
    int length = strlen(plaintext);

    // Перебор каждой буквы в тексте
    for (int i = 0; i < length; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            // Выводит текущий элемент массива
            printf("%c", plaintext[i]);
            continue;
        }

        // Проверка буквы на заглавную
        int offset = isupper(plaintext[i]) ? 65 : 97;

        // Вычисление того, насколько далеко текущий элемент находится от строчной "a" или заглавной
        int range_to_a = plaintext[i] - offset;

        // Индекс шифра (Берем расстояние о строчной или заглавной "a" и добавляем ключ)
        int cypher_index = (range_to_a + key) % 26;

        // Печать символа в зашифрованом виде
        printf("%c", cypher_index + offset);
    }

    printf("\n");

    return 0;
}
