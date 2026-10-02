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
    size_t pos = 0;

    /* Move non-zero values to the left */
    for (i = 0; i < size; i++)
    {
        if (line[i] != 0)
        {
            line[pos] = line[i];
            pos++;
        }
    }

    /* Fill the rest with zeros */
    for (i = pos; i < size; i++)
        line[i] = 0;

    /* Merge identical values */
    i = 0;
    while (i + 1 < pos)
    {
        if (line[i] == line[i + 1])
        {
            line[i] *= 2;

            for (j = i + 1; j + 1 < pos; j++)
                line[j] = line[j + 1];

            pos--;
            line[pos] = 0;
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
    size_t pos = size;

    /* Move non-zero values to the right */
    for (i = size; i > 0; i--)
    {
        if (line[i - 1] != 0)
        {
            pos--;
            line[pos] = line[i - 1];
        }
    }

    /* Fill the beginning with zeros */
    for (i = 0; i < pos; i++)
        line[i] = 0;

    /* Merge identical values from right to left */
    i = size - 1;

    while (i > pos)
    {
        if (line[i] == line[i - 1])
        {
            line[i] *= 2;

            for (j = i - 1; j > pos; j--)
                line[j] = line[j - 1];

            pos++;
            line[pos] = 0;
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
