#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int count_words = 0;
    int count_letters = 0;
    int count_sentences = 0;
    int size_text = strlen(text);

    for (int i = 0; i <= size_text; i++)
    {
        if (isspace(text[i]))
        {
            count_words++;
        }
        if (text[i] == 46 || text[i] == 33 || text[i] == 63)
        {
            count_sentences++;
        }
        if (isalpha(text[i]))
        {
            count_letters++;
        }
    }
    count_words++;

    float average_count_letters = ((float) count_letters / count_words * 100);

    float average_count_sentences = ((float) count_sentences / count_words * 100);

    int index = round(0.0588 * average_count_letters - 0.296 * average_count_sentences - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
        return 0;
    }

    else if (index <= 16)
    {
        printf("Grade %i\n", index);
        return 0;
    }

    else if (index > 16)
    {
        printf("Grade 16+\n");
        return 0;
    }
}

