#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool is_alpha(string c);
bool is_valid_key(string key);
string convert_to_cipher(string key, string text);

int main(int argc, string argv[])
{
    string key = argv[1];

    // validate arguments
    if (argc == 2)
    {
        if (strlen(key) != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        else
        {
            if (!is_alpha(key))
            {
                printf("Invalid Key!\n");
                return 1;
            }
            else if (!is_valid_key(key))
            {
                printf("Invalid Key!\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // get plaintext
    string plaintext = get_string("plaintext: ");

    // convert to cipher
    string ciphertext = convert_to_cipher(key, plaintext);

    // print ciphertext
    printf("ciphertext: %s\n", ciphertext);
}

// is alphabet? function
bool is_alpha(string c)
{
    int n = strlen(c);
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if ((c[i] >= 65 && c[i] <= 90) || (c[i] >= 97 && c[i] <= 122))
        {
            count++;
        }
    }

    if (n == count)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// valid key checker
bool is_valid_key(string key)
{
    int key_len = strlen(key);

    for (int i = 0; i < key_len ; i++)
    {
        for (int j = i + 1; j < key_len; j++)
        {
            if (tolower(key[j]) == tolower(key[i])) // is the char repeated?
            {
                return false;
            }
        }
    }
    return true;
}

// Convert to cipher
string convert_to_cipher(string key, string text)
{
    string ciphertext = text;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // ignore the punctuation.
        if (text[i] == ' ' || text[i] == ',' || text[i] == '.' || text[i] == '?')
        {
            // leave it as it is
        }

        //is the plaintext a capital char
        if (text[i] >= 65 && text[i] <= 90)
        {
            ciphertext[i] = toupper(key[text[i] - 65]);
        }

        // is the plaintext a lowercase char
        if (text[i] >= 97 && text[i] <= 122)
        {
            ciphertext[i] = tolower(key[text[i] - 97]);
        }
    }

    return ciphertext;
}