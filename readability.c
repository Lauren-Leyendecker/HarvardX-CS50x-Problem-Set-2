#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

// asks the user to input text and calculates the Coleman-Liau index of the text
int main(void)
{
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    // calculates the Coleman-Liau index using the equation index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text and S is the average number of
    // sentences per 100 words in the text
    int readability = round(0.0588 * (((double) letters / words) * 100) - 0.296 * (((double) sentences / words) * 100) - 15.8);
    if (readability < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (readability >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", readability);
    }

}

// calculates the number of letters in the text and returns it
int count_letters(string text)
{
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            letters++;
        }
    }
    return letters;
}

// calculates the number of words in the text and returns it
int count_words(string text)
{
    // has to start at one if not the last word in the text won't be counted
    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    return words;
}

// calculates the number of sentences in the text and returns it
int count_sentences(string text)
{
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}