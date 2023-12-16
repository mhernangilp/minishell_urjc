#ifndef MINISHELL_H
#define MINISHELL_H

#include "parser.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <dirent.h>

#define INPUT_PRINT "\033[93mmsh > \033[0;0m"
#define ERR_MEMORY "Error allocating memory\n"

extern int	g_sig;

typedef struct s_exec
{
	pid_t	*pid;
	int	**pipe;
	int	in_fd;
	int	out_fd;
	int	err_fd;
	tline	*line;
}	t_exec;

//execution.c
void	execute(tline *line);
void	close_all(t_exec *exec);
int		is_builtin(char *name);
void	do_builtin(tcommand command);

//child_process.c
void	child_process(t_exec exec, int num);

//error.c
void	exit_msg(char *msg, int val);
void	error_msg(char *msg, int val);

#endif
