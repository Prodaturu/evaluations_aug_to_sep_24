/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marschul <marschul@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 16:49:58 by marschul          #+#    #+#             */
/*   Updated: 2023/10/20 19:05:47 by marschul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"

/*
Find NL and return size of distance to next NL.
If there is no NL, we return -1.
*/
ssize_t	seek(t_readbuffer *readbuffer)
{
	char	*pointer;

	if (readbuffer->read_bytes == -1)
		return (-1);
	pointer = readbuffer->start;
	while (pointer < readbuffer->buffer + readbuffer->read_bytes)
	{
		if (*pointer == '\n')
			return (pointer - readbuffer->start + 1);
		pointer++;
	}
	return (-1);
}

/*
Simple copy function.
*/
void	copy(char *newbuffer, char *oldbuffer, size_t size)
{
	while (size != 0)
	{
		*newbuffer = *oldbuffer;
		newbuffer++;
		oldbuffer++;
		size--;
	}
}

/*
Resizes the stash buffer if we need more space.
Amortisized buffer.
*/
void	*stash_resize(t_stash *stash)
{
	size_t	old_buffer_size;
	char	*newbuffer;

	old_buffer_size = stash->size;
	newbuffer = malloc(2 * old_buffer_size);
	if (newbuffer == NULL)
		return (NULL);
	copy(newbuffer, stash->buffer, stash->end - stash->buffer);
	free(stash->buffer);
	stash->buffer = newbuffer;
	stash->end = stash->buffer + old_buffer_size;
	stash->size = 2 * old_buffer_size;
	return (stash->buffer);
}

/*
Handles the write operation to the stash.
Is being used like a public method.
*/
char	*stash_write(t_stash *stash, char *src, ssize_t size)
{
	while (size != 0)
	{
		if (stash->end == stash->buffer + stash->size)
		{
			if (stash_resize(stash) == NULL)
				return (NULL);
		}
		*stash->end = *src;
		stash->end++;
		src++;
		size--;
	}
	return (stash->buffer);
}

/*
Handles memory allocation and freeing of the buffers and structs.
*/
void	*gnl_malloc(t_stash **stash, t_readbuffer **readbuffer)
{
	*stash = malloc(sizeof(t_stash));
	*readbuffer = malloc(sizeof(t_readbuffer));
	if (*stash == NULL || *readbuffer == NULL)
	{
		free(*stash);
		free(*readbuffer);
		return (NULL);
	}
	(*stash)->buffer = malloc(BUFFER_SIZE);
	(*readbuffer)->buffer = malloc(BUFFER_SIZE);
	if ((*stash)->buffer == NULL || (*readbuffer)->buffer == NULL)
	{
		free((*stash)->buffer);
		free((*readbuffer)->buffer);
		free(*stash);
		free(*readbuffer);
		return (NULL);
	}
	return ((void *) 1);
}
