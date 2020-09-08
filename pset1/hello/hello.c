#import <cs50.h>
#import <stdio.h>

int main(void)
{
    // get the name
    string name = get_string("What's you name: ");

    // print the name
    printf("Hello, %s!\n", name);
}
