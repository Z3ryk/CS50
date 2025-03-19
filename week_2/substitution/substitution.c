#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Сообщение об ошибке
const string error_message = "Usage: ./substitution key\n";

// Переменная с кол-вом букв в алфавите
const int number_of_letters = 26;

int main(int argc, string argv[])
{
    // Проверка на количество аргументов
    if (argc != 2)
    {
        printf("%s", error_message);
        return 1;
    }

    // Присваеваем key значение аргумента
    string key = argv[1];

    // Длину аргумента записываем в переменную
    int argument_length = strlen(key);

    // Проверка на количество символов в аргументе (ключ)
    if (argument_length != number_of_letters)
    {
        printf("%s", error_message);
        return 1;
    }

    // Проверка является ли аргумент буквенным
    for (int i = 0; i < argument_length; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("%s", error_message);
            return 1;
        }
    }

    // Меняем в key буквы на единый регистр для проверки смешанного регистра
    for (int i = 0; i < number_of_letters; i++)
    {
        key[i] = toupper(key[i]);
    }

    // Проверка на дубликаты в ключе
    bool seen[26] = {false};

    for (int i = 0; i < number_of_letters; i++)
    {
        int index = key[i] - 'A';

        if (seen[index] == false)
        {
            seen[index] = true;
        }

        else
        {
            printf("%s", error_message);
            return 1;
        }
    }

    // Получение текста для шифрования
    string text = get_string("Text: ");

    printf("ciphertext: ");

    // Шифрование текста
    int text_length = strlen(text);

    for (int i = 0; i < text_length; i++)
    {
        // Выводит текущий элемент массива если он не является буквенным
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            continue;
        }

        // Печать строчных букв
        if (islower(text[i]))
        {
            int index = text[i] - 'a';
            printf("%c", key[index] + 32);
        }

        // Печать прописных букв
        else
        {
            int index = text[i] - 'A';
            printf("%c", key[index]);
        }
    }

    printf("\n");
    return 0;
}
