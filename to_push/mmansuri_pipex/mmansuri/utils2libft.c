/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmansuri <mmansuri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 18:45:45 by mmansuri          #+#    #+#             */
/*   Updated: 2024/07/17 18:03:47 by mmansuri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i1;

	i1 = 0;
	while (str[i1] != '\0')
		i1++;
	return (i1);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result1;
	int		total;
	int		sl1;
	int		sl2;
	char	*s3;

	sl1 = ft_strlen(s1);
	sl2 = ft_strlen(s2);
	total = sl1 + sl2 + 1;
	if (!s1 && !s2)
		return (NULL);
	s3 = (char *)malloc(total * sizeof(char));
	if (!s3)
		return (0);
	result1 = s3;
	while (*s1)
		*s3++ = *s1++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (result1);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i1;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i1 = 0;
	while (n > i1 && str1[i1] != '\0' && str2[i1])
	{
		if (str1[i1] != str2[i1])
			return (str1[i1] - str2[i1]);
		i1++;
	}
	if (i1 < n)
		return (str1[i1] - str2[i1]);
	return (0);
}

int	free_str2(char **str2, int k1)
{
	while (k1 >= 0)
		free(str2[k1--]);
	free(str2);
	return (0);
}

void	ft_freestr(char **str1, int i1)
{
	while (str1[i1])
		free(str1[i1++]);
	free(str1);
}
