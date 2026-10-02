#include "palindrome.h"

/**
 * is_palindrome - checks if an unsigned integer is a palindrome
 * @n: number to check
 *
 * Return: 1 if n is a palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
    unsigned long divisor;

    if (n < 10)
        return (1);

    divisor = 1;

    while (n / divisor >= 10)
        divisor *= 10;

    while (n > 0)
    {
        if (n / divisor != n % 10)
            return (0);

        n %= divisor;
        n /= 10;
        divisor /= 100;
    }

    return (1);
}
