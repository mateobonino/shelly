#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
* *_strdup - returns a pointer to a newly allocated space in memory
* @str: the string
*Return: NULL if str = NULL, p if copied succesfully
*
*
*/
char *_strdup(char *str)
{
	int j, size;
	char *p;

	if (str == NULL)
	{
		return (NULL);
	}
	for (size = 0; str[size] != '\0'; size++)
	{
		;
	}
	p = malloc(sizeof(char) * size + 1);
	if (p == NULL)
	{
		return (NULL);
	}
	for (j = 0; j < size; j++)
	{
		p[j] = str[j];
	}
	p[j] = '\0';
	return (p);
}
/**
* _strcat - concatenates two string
* @dest: the first string
* @src: the second string
* Return: the concatenated string
*/
char *_strcat(char *dest, char *src)
{
	int i, j;

	i = 0;
	j = 0;

	while (dest[i++])
	{
		j++;
	}
	for (i = 0; src[i]; i++)
	{
		dest[j++] = src[i];
	}
	dest[j++] = '\0';
	return (dest);
}
/**
* charlen - gets the length of a string
* @s: the string
*Return: returns the length of the string
*
*
*/
int charlen(char *s)
{
	int size;

	for (size = 0; s[size] != '\0'; size++)
	{
		;
	}
	return (size);
}
/**
* _strcmp - compares two strings
* @s1 : first string
* @s2: second string
*Return: returns the result
*
*
*/
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
