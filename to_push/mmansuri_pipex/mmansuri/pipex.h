/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:45:45 by mmansuri          #+#    #+#             */
/*   Updated: 2024/07/17 21:11:35 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define RED "\x1B[31m"

void	*ft_calloc(size_t count, size_t size);
size_t	ft_total_words(char const *str, char c1);
int		search_str(char c, char const *s, char **array);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		free_str2(char **str2, int k1);
void	ft_freestr(char **str1, int i1);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(void);
char	*create_path(char *envs, char **cmd1, int i1);
void	path_execute(char *argv, char **envp, int i1);
void	child_sub(int fdc[], char **argv, char **envp);
void	parent_sub(int fdp[], char **argv, char **envp);

#endif