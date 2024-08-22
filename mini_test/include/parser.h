/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 14:30:34 by trosinsk          #+#    #+#             */
/*   Updated: 2024/08/03 19:14:30 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# define VALID_SET "ACLsplcy +-.0123456789,\n"

typedef enum e_object_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	AMBIENT,
	CAMERA,
	LIGHT,
	UNKNOWN
}	t_object_type;

/**
 * @brief struct to store object data
 * 
 * @param type object type
 * @param position x, y, z coordinates
 * @param orientation i, j, k unit vector
 * @param diameter diameter (sphere and cylinder)
 * @param height height (cylinder)
 * @param intensity light intensity
 * @param color red, green, blue
 * @param fov field of view (camera)
 * @param next pointer to the next object
 */
typedef struct s_object
{
	t_object_type		type;
	double				position[3];
	double				orientation[3];
	double				diameter;
	double				height;
	double				intensity;
	double				color[3];
	double				fov;
	struct s_object		*next;
}						t_object;

// forward declarations to avoid circular dependencies

typedef struct s_main_rt	t_main_rt;

/**
 * @param gc garbage collector
 * @param file_n file name
 * @param m main struct (t_main_rt)
 * @return int 0 if success, 1 if error
 * 
 * @brief parser function to parse the file and store the data in the main struct
 */
int						parser(t_garbage *gc, char *file_n, t_main_rt *m);

#endif
