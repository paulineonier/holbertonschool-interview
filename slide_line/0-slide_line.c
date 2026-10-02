#include "slide_line.h"

/**
 * slide_left - slides and merges a line to the left
 * @line: pointer to the line
 * @size: size of the line
 *
 * Return: 1
 */
static int slide_left(int *line, size_t size)
{
    size_t i, j;
    size_t count = 0;

    /* Move all non-zero values to the left */
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[count] = line[i];
            count++;
        }
    }

    /* Fill the remaining positions with zeros */
    for (i = count; i < size; i++)
        line[i] = 0;

    /* Merge identical adjacent values */
    i = 0;
    while (i + 1 < count)
    {
        if (line[i] == line[i + 1])
        {
            line[i] *= 2;

            for (j = i + 1; j + 1 < count; j++)
                line[j] = line[j + 1];

            count--;
            line[count] = 0;
        }

        i++;
    }

    return (1);
}

/**
 * slide_right - slides and merges a line to the right
 * @line: pointer to the line
 * @size: size of the line
 *
 * Return: 1
 */
static int slide_right(int *line, size_t size)
{
    size_t i, j;
    size_t count = 0;

    /* Move all non-zero values to the right */
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[size - 1 - count] = line[i];
            count++;
        }
    }

    /* Fill the remaining positions with zeros */
    for (i = 0; i < size - count; i++)
        line[i] = 0;

    /* Merge identical adjacent values */
    i = size - 1;
    while (i > size - count)
    {
        if (line[i] == line[i - 1])
        {
            line[i] *= 2;

            for (j = i - 1; j > size - count; j--)
                line[j] = line[j - 1];

            count--;
            line[size - count - 1] = 0;
        }

        i--;
    }

    return (1);
}

/**
 * slide_line - slides and merges a line
 * @line: pointer to the line
 * @size: size of the line
 * @direction: direction of the slide
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    if (direction == SLIDE_LEFT)
        return (slide_left(line, size));

    if (direction == SLIDE_RIGHT)
        return (slide_right(line, size));

    return (0);
}
