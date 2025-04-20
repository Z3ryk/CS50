#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Максимальное число кандидатов
#define MAX 9

// Кандидаты имя и кол-во голосов
typedef struct
{
    string name;
    int votes;
} candidate;

// Множество кандидатов
candidate candidates[MAX];

int voter_count;

// номер кандидата
int candidate_count;

// Прототип функции
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // прверка на кол-во аргументов
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Проверка на максимум кандидатов
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count1 = get_int("Number of voters: ");
    voter_count = voter_count1;

    // Проверка избирателей
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // проверка на инвалида избирателя
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Функция печати победителя
    print_winner();
}

// Обноление счетчика голосов
bool vote(string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Распечатка победителя
void print_winner(void)
{
    int max_votes = -1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == max_votes)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

