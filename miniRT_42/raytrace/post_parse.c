/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   post_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:21:20 by sprodatu          #+#    #+#             */
/*   Updated: 2024/07/28 07:36:14 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	scene_render(t_main_rt *main_rt);
t_ray	*get_ray(t_scene *scene, double x, double y);

void	scene_render(t_main_rt *main_rt)
{
	t_scene		*scene;
	t_ray		*ray;
	t_color		*color;
	int			x;
	int			y;

	x = 0;
	y = 0;
	scene = main_rt->scene;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ray = get_ray(scene, x, y);
			color = ray_color(ray, scene, main_rt->parser->light);
			printf("color: r %f\t g %f\t b %f a %f\n", color->red, \
			color->green, color->blue, color->alpha);
			ray->col = get_rgba(color->red, color->green, color->blue, \
			color->alpha);
			printf("ray->col: %d\n", ray->col);
			mlx_put_pixel(main_rt->img, x, y, ray->col);
			x++;
		}
		y++;
	}
}

/**
 * @brief Creates a ray based on the given scene and pixel coordinates.
 * 
 * @remarks 
 * @param scene The scene containing the camera and other objects.
 * @param x The x-coordinate of the pixel.
 * @param y The y-coordinate of the pixel.
 * @return A pointer to the created ray.
 * @note Calculate scene's pixel co-ords based on given pixel co-ords.
 * @note --> done using the formula: (2 * ((x + 0.5) / WIDTH) - 1) * fov * ar
 * @note --> and (1 - 2 * ((y + 0.5) / HEIGHT)) * fov
 * @note Calculate the origin of the ray.
 * @note Calculate the direction of the ray.
 * @note Normalize the direction of the ray.
 */
t_ray	*get_ray(t_scene *scene, double x, double y)
{
	t_ray		*ray;
	t_vec		dir;
	double		aspect_ratio;
	int			len;

	ray = (t_ray *)malloc(sizeof(t_ray));
	if (!ray)
		return (ft_putendl_fd("Error: malloc error", 2), NULL);
	aspect_ratio = (double)WIDTH / (double)HEIGHT;
	ray->scene_pixel_x = (2 * ((x + 0.5) / WIDTH) - 1) * aspect_ratio * scene->fov;
	ray->scene_pixel_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * scene->fov;
	dir.vec_x = ray->scene_pixel_x * scene->v_width->vec_x + \
				ray->scene_pixel_y * scene->v_height->vec_x + \
				scene->v_cam_canvas->vec_x;
	dir.vec_y = ray->scene_pixel_x * scene->v_width->vec_y + \
				ray->scene_pixel_y * scene->v_height->vec_y + \
				scene->v_cam_canvas->vec_y;
	dir.vec_z = ray->scene_pixel_x * scene->v_width->vec_z + \
				ray->scene_pixel_y * scene->v_height->vec_z + \
				scene->v_cam_canvas->vec_z;
	len = sqrt(dir.vec_x * dir.vec_x + dir.vec_y * dir.vec_y + \
						dir.vec_z * dir.vec_z);
	if (len > 0)
	{
		dir.vec_x /= len;
		dir.vec_y /= len;
		dir.vec_z /= len;
	}
	ray->origin = scene->pov;
	ray->direction = &dir;
	return (ray);
}

// t_ray	*get_ray(t_scene *scene, double x, double y)
// {
// 	t_ray		*ray;
// 	t_vector	*origin;
// 	t_vector	*dir;
// 	t_garbage	*gc;
// 	double		aspect_ratio;

// 	ray = malloc(sizeof(t_ray));
// 	if (!ray)
// 		return (ft_putendl_fd("Error: malloc error", 2), (void *)0);
// 	gc = scene->garbage_col;
// 	aspect_ratio = (double)WIDTH / (double)HEIGHT;
// 	ray->scene_pixel_x = (2 * ((x + 0.5) / WIDTH) - 1) * \
// 	scene->fov * aspect_ratio;
// 	ray->scene_pixel_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * scene->fov;
// 	origin = scene->pov;
// 	dir = normalize(get_vec(ray->scene_pixel_x * scene->v_width->vec_x + \
// 	ray->scene_pixel_y * scene->v_height->vec_x + scene->v_cam_canvas->vec_x, \
// 	ray->scene_pixel_x * scene->v_width->vec_y + ray->scene_pixel_y * \
// 	scene->v_height->vec_y + scene->v_cam_canvas->vec_y, \
// 	ray->scene_pixel_x * scene->v_width->vec_z + ray->scene_pixel_y * \
// 	scene->v_height->vec_z + scene->v_cam_canvas->vec_z, gc), gc);
// 	ray->origin = (t_vec *)origin;
// 	ray->direction = (t_vec *)dir;
// 	add_to_garb_col(gc, ray);
// 	return (ray);
// }

// t_ray	*get_ray(t_scene *scene, double x, double y)
// {
// 	t_ray		*ray;
// 	t_vector	*origin;
// 	t_vector	*dir;
// 	t_garbage	*gc;
// 	double		aspect_ratio;

// 	ray = malloc(sizeof(t_ray));
// 	if (!ray)
// 		return (ft_putendl_fd("Error: malloc error", 2), (void *)0);
// 	gc = scene->garbage_col;
// 	aspect_ratio = (double)WIDTH / (double)HEIGHT;
// 	ray->scene_pixel_x = (2 * ((x + 0.5) / WIDTH) - 1) * \
// 	tan(scene->fov / 2 * M_PI / 180) * aspect_ratio;
// 	ray->scene_pixel_y = (1 - 2 * ((y + 0.5) / HEIGHT)) * \
// 	tan(scene->fov / 2 * M_PI / 180);
// 	origin = scene->pov;
// 	dir = get_vec(scene->v_cam_canvas->vec_x + ray->scene_pixel_x * \
// 	scene->v_width->vec_x + ray->scene_pixel_y * scene->v_height->vec_x, \
// 	scene->v_cam_canvas->vec_y + ray->scene_pixel_x * scene->v_width->vec_y + \
// 	ray->scene_pixel_y * scene->v_height->vec_y, scene->v_cam_canvas->vec_z + \
// 	ray->scene_pixel_x * scene->v_width->vec_z + ray->scene_pixel_y * \
// 	scene->v_height->vec_z, gc);
// 	// dir = normalize(dir, gc);
// 	ray->origin = (t_vec *)origin;
// 	ray->direction = (t_vec *)dir;
// 	add_to_garb_col(gc, ray);
// 	return (ray);
// }
