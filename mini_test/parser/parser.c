/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 18:31:08 by trosinsk          #+#    #+#             */
/*   Updated: 2024/08/09 09:04:53 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_object	init_obj_struct(void)
{
	t_object	obj;

	obj.type = UNKNOWN;
	obj.position[0] = 0;
	obj.position[1] = 0;
	obj.position[2] = 0;
	obj.orientation[0] = 0;
	obj.orientation[1] = 0;
	obj.orientation[2] = 0;
	obj.diameter = 0;
	obj.height = 0;
	obj.intensity = 0;
	obj.color[0] = 0;
	obj.color[1] = 0;
	obj.color[2] = 0;
	obj.fov = 0;
	obj.next = NULL;
}

t_object	*alloc_and_init_obj(t_garbage *gc)
{
	t_object	*obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (free_all(gc), err_msg(gc, "Error: failed to allocate memory", NULL));
	*obj = init_obj_struct();
	return (obj);
}

int	parse_line(char *line, t_object *rt)
{
	
}

int	parser(t_garbage *gc, char *file_n, t_main_rt *m)
{
	int			fd;
	char		*line_read;
	t_object	*parser;

	if (!gc || !file_n || !m)
		return (err_msg(gc, "Error: invalid arguments", 1));
	fd = open(file_n, O_RDONLY);
	if (fd < 0)
		return (err_msg(gc, "Error: failed to open file", 1));
	parser = m->objects;
	line_read = get_next_line(fd);
	while (line_read)
	{
		if (!parse_line(line_read, parser))
		{
			free(line_read);
			line_read = get_next_line(fd);
		}
		else
			return (free(line_read), err_msg(gc, "Error: check syntax!", 1));
	}
	return (close(fd), free(line_read), 0);
}
