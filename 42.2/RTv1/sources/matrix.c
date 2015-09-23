/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sven <jpirsch@student.42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/07 16:17:02 by sven              #+#    #+#             */
/*   Updated: 2015/05/11 19:24:02 by sven             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

t_mat	matrix_product(t_mat mat_a, t_mat_b)
{
	t_mat	mat_c;

	mat_c.a.x = mat_b.a.x * mat_a.a.x;
	mat_c.a.x += mat_b.a.y * mat_a.b.x;
	mat_c.a.x += mat_b.a.z * mat_a.c.x;
	mat_c.a.y = mat_b.a.x * mat_a.a.y;
	mat_c.a.y += mat_b.a.y * mat_a.b.y;
	mat_c.a.y += mat_b.a.z * mat_a.c.y;
	mat_c.a.z = mat_b.a.x * mat_a.a.z;
	mat_c.a.z += mat_b.a.y * mat_a.b.z;
	mat_c.a.z += mat_b.a.z * mat_a.c.z;
	mat_c.b.x = mat_b.b.x * mat_a.a.x;
	mat_c.b.x += mat_b.b.y * mat_a.b.x;
	mat_c.b.x += mat_b.b.z * mat_a.c.x;
	mat_c.b.y = mat_b.b.x * mat_a.a.y;
	mat_c.b.y += mat_b.b.y * mat_a.b.y;
	mat_c.b.y += mat_b.b.z * mat_a.c.y;
	mat_c.b.z = mat_b.b.x * mat_a.a.z;
	mat_c.b.z += mat_b.b.y * mat_a.b.z;
	mat_c.b.z += mat_b.b.z * mat_a.c.z;
	mat_c.c.x = mat_b.c.x * mat_a.a.x;
	mat_c.c.x += mat_b.c.y * mat_a.b.x;
	mat_c.c.x += mat_b.c.z * mat_a.c.x;
	mat_c.c.y = mat_b.c.x * mat_a.a.y;
	mat_c.c.y += mat_b.c.y * mat_a.b.y;
	mat_c.c.y += mat_b.c.z * mat_a.c.y;
	mat_c.c.z = mat_b.c.x * mat_a.a.z;
	mat_c.c.z += mat_b.c.y * mat_a.b.z;
	mat_c.c.z += mat_b.c.z * mat_a.c.z;
	return (mat_c);
}

t_mat	matrix_vector_product(t_mat mat, t_point ray)
{
	t_point	result_ray;

	result_ray.x = mat.a.x * ray.x;
	result_ray.x += mat.b.x * ray.y;
	result_ray.x += mat.c.x * ray.z;
	result_ray.y = mat.a.y * ray.x;
	result_ray.y += mat.b.y * ray.y;
	result_ray.y += mat.c.y * ray.z;
	result_ray.z = mat.a.z * ray.x;
	result_ray.z += mat.b.z * ray.y;
	result_ray.z += mat.c.z * ray.z;
	return (result_ray);
}

void	matrix_init_id(t_mat *mat)
{
	mat->a.x = 1;
	mat->a.y = 0;
	mat->a.z = 0;
	mat->b.x = 0;
	mat->b.y = 1;
	mat->b.z = 0;
	mat->c.x = 0;
	mat->c.y = 0;
	mat->c.z = 1;
}

void	matrix_init_rotx(t_mat *mat, float theta)
{
	mat->a.x = 1;
	mat->a.y = 0;
	mat->a.z = 0;
	mat->b.x = 0;
	mat->b.y = cos(theta);
	mat->b.z = sin(theta);
	mat->c.x = 0;
	mat->c.y = -mat->b.z;
	mat->c.z = mat->b.y;
}

void	matrix_init_roty(t_mat *mat, float theta)
{
	mat->a.x = cos(theta);
	mat->a.y = 0;
	mat->a.z = -sin(theta);
	mat->b.x = 0;
	mat->b.y = 1;
	mat->b.z = 0;
	mat->c.x = -mat->a.z;
	mat->c.y = 0;
	mat->c.z = mat->a.x;
}

void	matrix_init_rotz(t_mat *mat, float theta)
{
	mat->a.x = cos(theta);
	mat->a.y = sin(theta);
	mat->a.z = 0;
	mat->b.x = -mat->a.y;
	mat->b.y = mat->a.x;
	mat->b.z = 0;
	mat->c.x = 0;
	mat->c.y = 0;
	mat->c.z = 1;
}
