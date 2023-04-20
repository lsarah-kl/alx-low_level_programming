#include <unistd.h>

/**
 * main - Entry point
 *
 * Return: 1 (error code)
 */
int main(void)
{
	ssize_t bytes;
	char *text = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";

	bytes = sizeof(text) - 1;
	if (write(STDERR_FILENO, text, bytes) != bytes)
		return (1);
	return (1);
}
