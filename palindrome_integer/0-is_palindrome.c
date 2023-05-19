#include "palindrome.h"

/**
 * is_palindrome - Checks whether a given unsigned integer is a palindrome.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
    unsigned long reverse = 0;
    unsigned long temp = n;

    while(temp > 0)
    {
        reverse = reverse * 10 + temp % 10;
        temp /= 10;
    }
return (n == reverse);
}
