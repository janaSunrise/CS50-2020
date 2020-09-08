#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = 0;

    do
    {

        // get the size
        size = get_int("Height: ");

        // check if the size falls under the specified range
        if (size >= 1 && size <= 8)
        {
            break;
        }

    }
    while (true);

    int spaces = size - 1;

    for (int i = 0; i < size; i++)
    {
        // Print the spaces
        for (int j = spaces; j > 0; j--)
        {
            printf(" ");
        }

        // print the hashes
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }

        // print the empty 2 spaces
        printf("  ");

        // print the oposite pyramid
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }

        printf("\n");
        spaces -= 1;
    }
}
