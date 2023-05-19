#include "palindrome.h"

/**
 * is_palindrome - Checks whether a given unsigned integer is a palindrome.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    char str[20];  // Assuming the maximum number of digits is 20.
    int length = 0;
    int i = 0;

    // Convert the number to a string.
    sprintf(str, "%lu", n);

    // Find the length of the string.
    while (str[length] != '\0')
        length++;

    // Compare characters from both ends of the string.
    while (i < length / 2)
    {
        if (str[i] != str[length - i - 1])
            return 0;
        i++;
    }

    return 1;
}
