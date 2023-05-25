#include "holberton.h"

/**
 * is_digit - checks if the argument is a number
 * @str: argument
 * Return: 0 on failure, 1 on success
 **/
int is_digit(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

/**
 * _strlen - find the length of a string
 * @str: a string
 * Return: the length of the string
 **/
int _strlen(char *str)
{
	char *ptr = str;

	while (*str)
		str++;
	return (str - ptr);
}

/**
 * multiply - multiplies two numbers
 * @num1: first number
 * @num2: second number
 * Return: Nothing
 **/
void multiply(char *num1, char *num2)
{
	int i, len_num1, len_num2, total, digit_num1, digit_num2, result = 0, tmp;
	int *ptr;

	len_num1 = _strlen(num1);
	len_num2 = _strlen(num2);
	tmp = len_num2;
	total = len_num1 + len_num2;
	ptr = malloc(sizeof(int) * total);
	if (!ptr)
		return;

	for (len_num1--; len_num1 >= 0; len_num1--)
	{
		digit_num1 = num1[len_num1] - '0';
		result = 0;
		len_num2 = tmp;

		for (len_num2--; len_num2 >= 0; len_num2--)
		{
			digit_num2 = num2[len_num2] - '0';
			result += ptr[len_num2 + len_num1 + 1] + (digit_num1 * digit_num2);
			ptr[len_num1 + len_num2 + 1] = result % 10;
			result /= 10;
		}

		if (result)
			ptr[len_num1 + len_num2 + 1] = result % 10;
	}

	while (*ptr == 0)
	{
		ptr++;
		total--;
	}

	for (i = 0; i < total; i++)
		printf("%i", ptr[i]);
	printf("\n");
}

/**
 * main - Entry point
 * @argc: argument count
 * @argv: argument values
 * Return: 0 on success
 **/
int main(int argc, char *argv[])
{
	char *num1 = argv[1];
	char *num2 = argv[2];

	if (argc != 3 || !is_digit(num1) || !is_digit(num2))
	{
		printf("Error\n");
		exit(98);
	}

	multiply(num1, num2);
	return (0);
}
