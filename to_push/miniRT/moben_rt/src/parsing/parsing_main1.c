/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 10:45:22 by marschul          #+#    #+#             */
/*   Updated: 2024/07/14 06:28:17 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Minirt.h"

/*
Initialzes the scene struct. There can only be 100 objects of every type each.
*/
bool	init_scene(t_scene *scene, t_garbage_collector *gc)
{
	void	*mem;

	mem = (t_sphere *) malloc(100 * sizeof(t_sphere *));
	if (mem == NULL)
		(exit_function(gc, "feheler\n", 1, 1));
	else
		add_pointer_node(gc, mem);
	scene->spheres = mem;
	mem = (t_plane *) malloc(100 * sizeof(t_plane *));
	if (mem == NULL)
		(exit_function(gc, "feheler\n", 1, 1));
	else
		add_pointer_node(gc, mem);
	scene->planes = mem;
	mem = (t_cylinder *) malloc(100 * sizeof(t_cylinder *));
	if (mem == NULL)
		(exit_function(gc, "feheler\n", 1, 1));
	else
		add_pointer_node(gc, mem);
	scene->cylinders = mem;
	scene->nr_spheres = 0;
	scene->nr_planes = 0;
	scene->nr_cylinders = 0;
	return (true);
}

/*
Checks if all the 3 mandatory elements are present.
*/
bool	check_mandatory_elements_present(void)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (check_for_unique(i) == true)
			return (false);
		i++;
	}
	return (true);
}

/*
Helper function to get read_in_elements through Norminette
*/
char	**get_split(char *line, t_garbage_collector *gc)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split == NULL)
		exit_function(gc, "Error\nMalloc failure\n", 1, true);
	return (split);
}

/*
Reads in the element.
In function_pointers are the function pointers to check all elements. 
A line is being checked by all checking functions until one fits.
If a line does not fit on one element, it returns false. If no element fits,
 we give out an error.
*/
void	read_in_element(char *line, t_scene *scene, t_garbage_collector *gc)
{
	const t_function_pointer	function_pointers[6] = {check_ambient, \
	check_camera, check_light, check_sphere, check_plane, check_cylinder};
	int							i;
	char						**split;
	bool						error;

	split = get_split(line, gc);
	i = 0;
	while (i < 6)
	{
		if (split[0] && "ACLspc"[i] == split[0][0])
		{
			error = function_pointers[i](split, scene, gc);
			free_2d(split);
			if (!error)
				exit_function(gc, "", 6, true);
			if (check_for_unique(i) == false)
				exit_function(gc, "Error\nUnique element double\n", 7, true);
			return ;
		}
		i++;
	}
	free_2d(split);
	exit_function(gc, "Error\nMalformed line", 5, true);
}

/*
Main parsing function. Reads in data into scene struct, while checking for
correctness.
Initializes scene struct, opens file, loops over lines.
*/
void	parsing(char *file, t_scene *scene, t_garbage_collector *gc)
{
	char	*line;
	int		fd;

	if (init_scene(scene, gc) == false)
		exit_function(gc, "Error\nMalloc failure\n", 1, true);
	if (check_file_extension(file) == false)
		exit_function(gc, "Error\nWrong file extension\n", 2, true);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_function(gc, "Error\nError while opening file\n", 3, true);
	line = (void *) 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		add_pointer_node(gc, line);
		if (line && line[0] != '\n')
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			read_in_element(line, scene, gc);
		}
	}
	if (check_mandatory_elements_present() == false)
		exit_function(gc, "Error\n3 mandatory elements not there\n", 4, true);
	close(fd);
}
