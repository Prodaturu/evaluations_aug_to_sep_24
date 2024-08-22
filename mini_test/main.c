/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 14:21:02 by sprodatu          #+#    #+#             */
/*   Updated: 2024/07/31 06:18:20 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minirt.h"

t_main_rt	*main_rt_init(t_garbage *gc)
{
	t_main_rt	*main_rt;

	main_rt = (t_main_rt *)malloc(sizeof(t_main_rt));
	if (!main_rt)
		return (err_msg(gc, "Error: malloc fail", 1), NULL);
	add_to_gc(gc, main_rt);
	return (main_rt);
}

	// main_rt->gc = gc;

void	file_checker(int argc, char **argv)
{
	char	*file_type;

	if (argc != 2)
	{
		ft_putendl_fd("Error: path to file expected", 2);
		exit(1);
	}
	file_type = ft_strrchr(argv[1], '.');
	if (!file_type || (ft_strncmp(file_type, ".rt", 3) != 0)
		|| (ft_strlen(file_type) != 3))
	{
		ft_putendl_fd("Error: provide a .rt file", 2);
		if (file_type)
			printf(RED "Provided: %s file, use .rt file\n" RESET, file_type);
		else
			printf(RED "File type not found, use .rt file\n" RESET);
		exit(1);
	}
	if (DEBUG)
		printf(GREEN "File type is: %s\n" RESET, file_type);
}

int	main(int argc, char **argv)
{
	t_garbage	*gc;
	t_main_rt	*rt;

	file_checker(argc, argv);
	gc = garbage_collector_init();
	rt = main_rt_init(gc);
	parser(rt, argv[1], gc);
	// rendering(rt);
	free_garbage(gc);
	return (0);
}
