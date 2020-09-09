#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{

    string text = get_string("Please input a text: ");

// Count Letters
    int letters = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            letters += 1;
        }
        else
        {
            letters += 0;
        }
    }

// Count Words
    int words = 0;

    for (int w = 0; w < strlen(text); w++)
    {
        while (isalpha(text[w]) || text[w] == '\'' || text[w] == '-')
        {
            w++;
        }

        while (ispunct(text[w]) || isspace(text[w]))
        {
            w++;
        }

        words += 1;
    }

// Count Sentences

    int sentences = 0;

    for (int s = 0; s < strlen(text); s++)
    {
        if (text[s] == '!' || text[s] == '.' || text[s] == '?')
        {
            sentences += 1;
        }
    }

// Use the Formula

    float l = 100 * (letters / (float) words);
    float s = 100 * (sentences / (float) words);

    //printf("l = %f\n",l);
    //printf("s = %f\n",s);

    float readability = 0.0588 * l - 0.296 * s - 15.8;

    //printf("readability = %f\n", readability);
    //printf("rounded_readability = %i\n", (int) round(readability));

    if (round(readability) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(readability) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int) round(readability));
    }

// Get Data
    //printf("%i letters \n", letters);
    //printf("%i words \n", words);
    //printf("%i sentences \n", sentences);
}