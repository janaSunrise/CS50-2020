#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

bool is_alpha(char c);

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Get text
    string text = get_string("Text: ");

    // count letters
    int letters = count_letters(text);

    // count words
    int words = count_words(text);

    // count sentences
    int sentences = count_sentences(text);

    // calculate the index
    float index = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;

    // convert index to integer
    index = round(index);

    // output index
    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int) index);
    }
}

bool is_alpha(char c)
{
    if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// get the letter count
int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (is_alpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}

// get the word count
int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    return words;
}

// get the sentence count
int count_sentences(string text)
{
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}