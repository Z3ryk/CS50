#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Сообщение об ошибке
const string error_message = "Usage: ./substitution key\n";

// Переменная с кол-вом букв в алфавите
const int number_of_letters = 26;

// Печать об ошибке
int print_error()
{
    printf("%s", error_message);
    return 1;
}

int main(int argc, string argv[])
{
    // Проверка на количество аргументов
    if (argc != 2)
    {
        return print_error();
    }

    // Присваеваем key значение аргумента
    string key = argv[1];

    // Проверка на количество символов в аргументе (ключ)
    if (strlen(key) != number_of_letters)
    {
        return print_error();
    }

    bool seen[26] = {false};

    // Проверки
    for (int i = 0; i < number_of_letters; i++)
    {
        // Проверка является ли аргумент буквенным
        if (!isalpha(key[i]))
        {
            return print_error();
        }
        // Проверки на совпадение буквенных символов в ключе
        int index = toupper(key[i]) - 'A';

        if (seen[index] == true)
        {
            return print_error();
        }
        else
        {
            seen[index] = true;
        }
    }

    // Получение текста для шифрования
    string text = get_string("Text: ");

    printf("ciphertext: ");

    // Шифрование текста
    for (int i = 0; text[i] != '\0'; i++)
    {
        char character = text[i];

        // Выводит текущий элемент массива если он не является буквенным
        if (!isalpha(character))
        {
            printf("%c", character);
            continue;
        }

        // Печать строчных букв
        int index;
        if (islower(character))
        {
            index = character - 'a';
            printf("%c", tolower(key[index]));
        }

        // Печать прописных букв
        else
        {
            index = character - 'A';
            printf("%c", toupper(key[index]));
        }
    }

    printf("\n");

    return 0;
}
