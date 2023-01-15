#include "main.h"
/**
* sh_read - reads a line from the prompt entered by user
* Return: the line
*/
char *sh_read(void)
{
	int i = 0, status;
	char *cmd = NULL;
	size_t size = 0;

	fflush(stdin);
	status = getline(&cmd, &size, stdin);

	if (feof(stdin) || status == EOF)
	{
		free(cmd);
		if (isatty(STDIN_FILENO))
			_putchar('\n');
		exit(0);
	}
	if (!isatty(STDIN_FILENO))
		status = 0;
	if (strcmp(cmd, "\n") == 0)
	{
		return (NULL);
	}
	while (cmd[i] != '\n')
	{
		if (cmd[i] != ' ' && cmd[i] != '\t')
			return (cmd);
		i++;
	}
	free(cmd);
	return (NULL);
}
/**
* print_prompt - prints the prompt of the shell
* Return: void func
*/
void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		char buf[256];
		write(1, "\033[1;33m", strlen("\033[1;33m"));
		write(1, "[", 1);
		write(1, _getenv("USER"), strlen(_getenv("USER")));
		write(1, "@shelly] ", 10);
		write(1, "~ ", 2);
		write(1, getcwd(buf, sizeof(buf)), strlen(getcwd(buf, sizeof(buf))));
		write(1, "\n$ ", 3);
		write(1, "\033[0m", strlen("\033[0m"));
	}
}
/**
* _getenv - looks for a environment variable
* @name: the variable to look for
* Return: the value if found, NULL otherwise
*/
char *_getenv(const char *name)
{
	int i, j, found;

	for (i = 0; environ[i]; i++)
	{
		found = 1;
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (name[j] != environ[i][j])
			{
				found = 0;
				break;
			}
		}

		if (found)
			return (&environ[i][j + 1]);
	}
	return (NULL);
}
/**
* _printenv - prints environment variables
* Return: void function
*/
int _printenv(void)
{
	int i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
	return (0);
}
/**
* gatorr - prints error msg
* @av: the executable name
* @cmd: the command
* @msg: msg to print
* @num: the num of error
* Return: void func
*/
void gatorr(char **av, char *cmd, char *msg, int num __attribute__((unused)))
{
	write(1, "\033[1;31m", strlen("\033[1;31m"));
	write(2, av[0], strlen(av[0]));
	write(2, ": 1: ", 5);
	write(2, cmd, strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, strlen(msg));
	write(1, "\033[0m", strlen("\033[0m"));
	write(2, "\n", 1);
	write(1, "\033[1;31m", strlen("\033[1;31m"));
	write(2, "[X]", 3);
	write(1, "\033[0m", strlen("\033[0m"));
	/*_puts(av[0]);
	_puts(": ");
	_putchar('1');
	_puts(": ");
	_puts(cmd);
	_puts(": ");
	_puts(msg);
	_putchar('\n');*/
}

void checkcd(char **commands) {
	if (commands[1])
	{
		DIR* dir = opendir(commands[1]);
		if (dir)
		{
			closedir(dir);
			chdir(commands[1]);
		} else {
			write(1, "\033[1;31m", strlen("\033[1;31m"));
			write(1, commands[1], strlen(commands[1]));
			write(1, ": No such file or directory", strlen(": No such file or directory"));
			write(1, "\033[0m", strlen("\033[0m"));
			write(1, "\n", 1);
		}
	} else {
		chdir(_getenv("HOME"));
	}
}