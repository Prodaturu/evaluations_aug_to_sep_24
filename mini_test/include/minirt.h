/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 01:29:10 by trosinsk          #+#    #+#             */
/*   Updated: 2024/08/02 21:05:25 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

# include "../libft/include/libft.h"
# include "../gnl42/include/get_next_line.h"
# include "../MLX42/include/MLX42/MLX42.h"

# include "garbage_collector.h"
# include "parser.h"
# include "render_structs.h"

# define DEBUG 1
// # define DEBUG 0 // uncomment this line to disable debug mode

# define PI 3.14159265358979323846
# define WIDTH 2
# define HEIGHT 2
# define YPSILON 0.000001

# define RESET "\x1B[0m"
# define RED "\x1B[31m"
# define GREEN "\x1B[32m"
# define YELLOW "\x1B[33m"
# define BLUE "\x1B[34m"
# define MAGENTA "\x1B[35m"
# define CYAN "\x1B[36m"
# define WHITE "\x1B[37m"

typedef struct s_color
{
	double		red;
	double		green;
	double		blue;
	double		alpha;
}				t_color;

/**
 * @brief s_vec_rt struct to store object vectors
 * 
 * @param vc_x vector component in x direction
 * @param vc_y vector component in y direction
 * @param vc_z vector component in z direction
 */
typedef struct s_vector
{
	double			vec_x;
	double			vec_y;
	double			vec_z;
}				t_vector;

/**
 * @brief struct to store the scene data
 * 
 * @param sphere_count number of spheres in the scene
 * @param plane_count number of planes in the scene
 * @param cylinder_count number of cylinders in the scene
 */
typedef struct s_scene
{
	t_vec			*start_pixel;
	t_vec			*orientation;
	t_vec			*v_cam_canvas;
	t_vec			*v_width;
	t_vec			*v_height;
	t_vec			*pov;
	t_object		*objects;
	t_color			*background_color;
	void			*garbage_col;
	double			focal_length;
	double			pixel_width;
	double			pixel_height;
	double			half_width;
	double			half_height;
	double			fov;
	int				depth;

}			t_scene;

// --- --- --- Main miniRT struct --- --- --- //

/**
 * @brief s_main_rt struct to store all data related to the scene
 * @param gc pointer to garbage collector
 * @param objects pointer to objects struct(s)
 * @param object_count number of objects in the scene
 */
typedef struct s_main_rt
{
	t_object		**objects;
	size_t			object_count;
}					t_main_rt;

// --- --- --- --- main.c --- --- --- --- //

/**
 * @brief Main function to run the program
 * checks the syntax of the input file,
 * parses the objects in the scene,
 * updates the scene struct
 * draws the scene using the mlx library
 * and returns 0 if successful
 * and 1 if there is an error anywhere during execution
 * 
 * @param argc number of arguments
 * @param argv arguments
 * @return int 0 if successful, 1 if error
 */
int			main(int argc, char**argv);

/**
 * @brief Initializes the main_rt struct,
 * and sets the sphere, plane and cylinder counters to 0,
 * and sets the img and color pointers to NULL,
 * finally adds the main_rt struct to the garbage collector
 * 
 * @param main_rt pointer to main_rt struct that will be initialized
 * @param garb_col pointer to garbage collector
 * @return void
 */
t_main_rt	*main_rt_init(t_garbage *gc);

/**
 * @brief function to check the syntax of the input file
 * 
 * @param argc number of arguments
 * @param argv arguments
 */
void		file_checker(int argc, char **argv);

// int			parser(t_main_rt *rt, char *file_name, t_garbage *gc);

#endif
