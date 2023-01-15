#include "main.h"
/**
* main - checks the code
* @ac: the number of args
* @av: array of args
* Return: always 0
*/
int main(int ac __attribute__((unused)), char **av)
{
	int ex_status = 0;
	char *prompt = NULL, **commands = NULL;
	system("clear");
	signal(SIGINT, SIG_IGN);
	while (1)
	{
		print_prompt();
		prompt = sh_read();
		if (!prompt)
			continue;
		commands = parse_cmd(prompt);
		if (_strcmp(commands[0], "exit") == 0)
		{
			free(prompt);
			break;
		}
		if (_strcmp(commands[0], "env") == 0)
		{
			free(commands);
			free(prompt);
			_printenv();
			continue;
		}
		if (_strcmp(_getenv("PATH"), "") == 0)
		{
			free(prompt);
			ex_status = 127;
			break;
		}
		if (_strcmp(commands[0], "cd") == 0)
		{
			checkcd(commands);
			free(prompt);
			free(commands);
			continue;
		}
		ex_status = checked(commands, av);
		if (ex_status == 555)
		{
			if (!isatty(STDIN_FILENO))
			{
				ex_status = 127;
				return (ex_status);
			}
		}
		free(prompt);
	}
	free(commands);
	return (ex_status);
}
