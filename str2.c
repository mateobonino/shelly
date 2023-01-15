#include "main.h"
/**
* _puts - prints a string
* @str: the string
* Return: void func
*/
void _puts(char *str)
{

	while (*str != '\0')
	{
		_putchar(*str++);
	}
}
/**
* *str_concat - concatenates two strings
* @s1: first string
* @s2: second string
*Return: returns the concatenated string
*
*/
char *str_concat(char *s1, char *s2)
{
	long int i, j, s1len, s2len;
	char *a;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	s1len = charlen(s1);
	s2len = charlen(s2);
	a = malloc(sizeof(char) * s1len + s2len + 1);
	if (a == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < s1len; i++)
	{
		a[i] = s1[i];
	}
	for (j = 0; j < s2len; j++)
	{
		a[i] = s2[j];
		i++;
	}
	a[i] = '\0';
	return (a);
}
