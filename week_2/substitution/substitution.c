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
        printf("Usage: ./substitution k\n");
        return 1;
    }

    // Присваеваем key значение аргумента
    string key = argv[1];
    // Приваемае check значение аргумента
    string check = argv[1];

    // Проверка является ли аргумент буквенным
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }

    // Меняем в check буквы на единый регистр для проверки смешанного регистра
    for (int i = 0; i < 26; i++)
    {
        if (islower(check[i]))
        {
            check[i] = check[i] - 32;
        }
    }

    // Проверка на дубликаты в ключе
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (check[i] == check[j])
            {
                for (int n = j - 1; n >= 0; n--)
                {
                    if (check[j] == check[n])
                    {
                        printf("Usage: ./substitution k\n");
                        return 1;
                    }
                }
            }
        }
    }

    // Проверка на количество символов в строке
    if (strlen(argv[1]) != 26)
    {
        printf("Usage: ./substitution k\n");
        return 1;
    }

    string alp = "abcdefghijklmnopqrstuvwxyz";
    string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string text = get_string("Text: ");
    printf("ciphertext: ");

    // Перебор каждой буквы в тексте
    for (int i = 0, lng = strlen(text); i < lng; i++)
    {
        if (!isalpha(text[i]))
        {
            // Выводит текущий элемент массива если он не является альфавитным
            printf("%c", text[i]);
            continue;
        }

        // Перебор какая буква из текста подходит к алвафиту и замена его на букву из ключа
        // (Строчные)
        if (islower(text[i]))

        {
            for (int x = 0, length = strlen(alp); x < length; x++)
            {
                int z = alp[x];
                int h = text[i];
                if (z == h)
                {
                    if (islower(key[x]))
                    {
                        printf("%c", key[x]);
                    }

                    else
                    {
                        printf("%c", key[x] + 32);
                    }
                }
            }
        }

        // Перебор какая буква из текста подходит к алвафиту и замена его на букву из ключа
        // (Заглавные)
        if (!islower(text[i]))
        {
            for (int x = 0, length = strlen(ALP); x < length; x++)
            {
                int z = ALP[x];
                int h = text[i];
                if (z == h)
                {
                    if (!islower(key[x]))
                    {
                        printf("%c", key[x]);
                    }

                    else
                    {
                        printf("%c", key[x] - 32);
                    }
                }
            }
        }
    }
    printf("\n");
    return 0;
}
