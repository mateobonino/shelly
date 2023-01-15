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
		write(1, "[", 1);
		write(1, _getenv("USER"), strlen(_getenv("USER")));
		write(1, "@shelly]$ ", 11);
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
	write(2, av[0], strlen(av[0]));
	write(2, ": 1: ", 5);
	write(2, cmd, strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, strlen(msg));
	write(2, "\n", 1);
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
			printf("error xd\n");
		}
	} else {
		printf("no args passed xd\n");
	}
}