/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 01:29:10 by trosinsk          #+#    #+#             */
/*   Updated: 2024/07/28 05:48:05 by sprodatu         ###   ########.fr       */
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
# include "render_structs.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include "garbage_collector.h"
# include "parser.h"

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
	t_vector		*start_pixel;
	t_vector		*orientation;
	t_vector		*v_cam_canvas;
	t_vector		*v_width;
	t_vector		*v_height;
	t_vector		*pov;
	t_objects		*objects;
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
 * @struct s_main_rt t_main_rt
 * @brief s_main_rt struct to store main miniRT data
 * 
 * @param sphere_counter sphere counter
 * @param plane_counter plane counter
 * @param cyl_counter cylinder counter
 * @param num_windows number of windows
 * @param img pointer to mlx_image_t struct
 * @param parser pointer to parser struct
 * @param garb_col pointer to garbage collector
 * @param vector pointer to vector struct
 * @param scene pointer to scene struct
 * @param color pointer to combined color
 */
typedef struct s_main_rt
{
	int				sphere_counter;
	int				plane_counter;
	int				cyl_counter;
	int				num_windows;
	mlx_t			*mlx;
	mlx_image_t		*img;
	t_parser		*parser;
	t_objects		*objects;
	t_garbage		*garb_col;
	t_vector		*vector;
	t_scene			*scene;
	t_color			*color;
}				t_main_rt;

// --- --- --- main.c --- --- --- //

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
void		main_rt_init(t_main_rt *main_rt, t_garbage *garb_col);

/**
 * @brief function to check the syntax of the input file
 * 
 * @param argc number of arguments
 * @param argv arguments
 */
void		file_checker(int argc, char **argv);

/**
 * @brief Checks if the garbage collector is initialized and
 * If correct filetype, returns error message if not. 
 * 
 * Then opens the file and returns error message if fd is -1.
 * 
 * Call parser_init function to initialize parser struct
 * In a loop reads the file line by line and calls parse_line function
 * if anywhere an error occurs, returns an error message 
 * and closes the file descriptor and frees the line_read pointerw
 */
int			parser(t_garbage *g_c, char *f_n, t_main_rt *m_rt);

/**
 * @brief function to check if the point is on sphere.0
 */
int			is_on_sphere(t_vector center, int diameter, t_vector point);

//build_scene
int			init_scene_struct(t_main_rt *main_rt, t_garbage *gc);
t_vector	*get_vec(double x, double y, double z, t_garbage *gc);

t_vector	*normalize(t_vector *vector, t_garbage *gc);
t_vector	*vector_add(t_vector *vector, t_vector *help_vec, t_garbage *gc);
t_vector	*vector_sub(t_vector *v_height, t_vector *v_width, t_garbage *gc);
t_vector	*vector_mult(t_vector *vector, double mult, t_garbage *gc);
t_vector	*cross(t_vector *a, t_vector *b, t_garbage *gc);
t_vector	*scalar_mult(t_vector *a, double c, t_garbage *gc);
t_vector	*set_orientation(t_vec_rt *orientation, t_garbage *gc);
t_vector	*set_pov(t_pov_rt *pov, t_garbage *gc);
t_objects	*objects_init(t_main_rt *main_rt, t_garbage *gc);
t_object	*obj_sphere(t_objects *obj, t_parser *parser, \
t_garbage *gc, int *id);
t_object	*obj_cylinder(t_objects *obj, t_parser *parser, \
t_garbage *gc, int *id);
t_object	*obj_plane(t_objects *obj, t_parser *parser, \
t_garbage *gc, int *id);

//
//
mlx_t		*renderer(t_main_rt *main_rt);
void		scene_render(t_main_rt *main_rt);
t_color		*ray_color(t_ray *ray, t_scene *scene, t_light_rt *light);
int			get_rgba(int r, int g, int b, int a);

#endif