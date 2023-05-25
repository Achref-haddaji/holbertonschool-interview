#include <stdlib.h>
#include <unistd.h>

int _putchar(char c)
{
	return (write(1, &c, 1));
}

int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int is_positive_number(char *str)
{
	if (*str == '\0')
		return (0);

	while (*str)
	{
		if (!is_digit(*str))
			return (0);
		str++;
	}

	return (1);
}

int string_length(char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

void print_error(void)
{
	int i;
	char error_msg[] = "Error\n";

	for (i = 0; i < 6; i++)
		_putchar(error_msg[i]);
}

void print_number(char *number)
{
	int i;

	for (i = 0; i < string_length(number); i++)
		_putchar(number[i]);
	_putchar('\n');
}

char *multiply(char *num1, char *num2)
{
	int len1 = string_length(num1);
	int len2 = string_length(num2);
	int len_result = len1 + len2;
	int i, j;
	int carry, product;
	char *result;

	result = malloc(sizeof(char) * (len_result + 1));

	if (result == NULL)
		return (NULL);

	for (i = 0; i < len_result; i++)
		result[i] = '0';

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			product = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0') + carry;
			carry = product / 10;
			result[i + j + 1] = (product % 10) + '0';
		}

		result[i] += carry;
	}

	return (result);
}

int main(int argc, char *argv[])
{
	char *num1, *num2;
	char *result;

	if (argc != 3 || !is_positive_number(argv[1]) || !is_positive_number(argv[2]))
	{
		print_error();
		return (98);
	}

	num1 = argv[1];
	num2 = argv[2];

	result = multiply(num1, num2);

	if (result == NULL)
	{
		print_error();
		return (98);
	}

	print_number(result);
	free(result);

	return (0);
}
