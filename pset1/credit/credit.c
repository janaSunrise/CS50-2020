#include <cs50.h>
#include <stdio.h>

void print_type(int digit1, int first_two_digits, int num_digits, bool is_valid)
{
    // if visa type
    if (digit1 == 4 && num_digits >= 13 && num_digits <= 16 && is_valid)
    {
        printf("VISA\n");
    }
    // if mastercard type
    else if (first_two_digits >= 51 && first_two_digits <= 55 && num_digits == 16 && is_valid)
    {
        printf("MASTERCARD\n");
    }
    // if amex type
    else if ((first_two_digits == 34 || first_two_digits == 37) && num_digits == 15 && is_valid)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    // get the card number
    long card_number = get_long("Number: ");

    // initialize the vars
    int digit1 = 0, digit2 = 0, odds = 0, evens = 0;
    int num_digits = 0;

    // get card len
    while (card_number > 0)
    {
        digit2 = digit1;
        digit1 = card_number % 10;

        if (num_digits % 2 == 0)
        {
            evens += digit1;
        }
        else
        {
            int multiple = 2 * digit1;
            odds += (multiple / 10) + (multiple % 10);
        }

        card_number /= 10;
        num_digits++;
    }

    bool is_valid = (evens + odds) % 10 == 0;

    int first_two_digits = (digit1 * 10) + digit2;

    print_type(digit1, first_two_digits, num_digits, is_valid);
}