/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:45:45 by mmansuri          #+#    #+#             */
/*   Updated: 2024/07/17 21:10:28 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*create_path(char *envs, char **cmd1, int i1)
{
	char	*sub_path;
	char	*pathf;
	char	**paths;

	paths = ft_split(envs, ':');
	while (paths[i1])
	{
		sub_path = ft_strjoin(paths[i1], "/");
		pathf = ft_strjoin(sub_path, cmd1[0]);
		free(sub_path);
		if (access(pathf, X_OK | F_OK) == 0)
		{
			ft_freestr(paths, 0);
			return (pathf);
		}
		free(pathf);
		i1++;
	}
	ft_freestr(paths, 0);
	return (cmd1[0]);
}

void	path_execute(char *argv, char **envp, int i1)
{
	char	*pathf;
	char	*envs;
	char	**cmd1;

	cmd1 = ft_split(argv, ' ');
	while (envp[++i1])
	{
		if (ft_strncmp(envp[i1], "PATH", 4) == 0)
			break ;
	}
	envs = envp[i1] + 5;
	pathf = create_path(envs, cmd1, 0);
	if (execve(pathf, cmd1, envp) == -1)
	{
		ft_putstr_fd(RED "COMMAND NOT FOUND.", 2);
		write(2, "\n", 1);
		ft_freestr(cmd1, 0);
		exit(127);
	}
}

void	child_sub(int fdc[], char **argv, char **envp)
{
	int	file1;

	file1 = open(argv[1], O_RDONLY);
	if (file1 < 0)
		ft_error();
	dup2(fdc[1], 1);
	dup2(file1, 0);
	close(file1);
	close(fdc[0]);
	close(fdc[1]);
	path_execute(argv[2], envp, -1);
}

void	parent_sub(int fdp[], char **argv, char **envp)
{
	int		file2;
	pid_t	pidp;
	int		status;

	file2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (file2 < 0)
		ft_error();
	pidp = fork();
	if (pidp == -1)
		ft_error();
	if (pidp == 0)
	{
		dup2(fdp[0], 0);
		dup2(file2, 1);
		close(fdp[1]);
		path_execute(argv[3], envp, -1);
	}
	close(fdp[1]);
	close(file2);
	waitpid(pidp, &status, 0);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	else
		exit(1);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd_pc[2];
	pid_t	pid1;

	if (argc != 5)
	{
		ft_putendl_fd(RED "BAD ARGUMENTS", STDERR_FILENO);
		exit(1);
	}
	if (pipe(fd_pc) == -1)
		ft_error();
	pid1 = fork();
	if (pid1 == -1)
		ft_error();
	if (pid1 == 0)
		child_sub(fd_pc, argv, envp);
	else
	{
		parent_sub(fd_pc, argv, envp);
		waitpid(pid1, NULL, 0);
	}
	return (0);
}

// cc -Wall -Werror -Wextra *.c
// ./a.out main.c "grep main" "wc -l" outfile1.txt
// ./pipex main.c "grep main" "wc -l" outfile1.txt
// < main.c grep main | wc -l > outfile2.txt
// valgrind ./a.out main.c "grep main" "wc -l" outfile1.txt
// valgrind --leak-check=full ./a.out main.c "grep main" "wc -l" outfile1.txt