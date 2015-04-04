/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/09 12:17:52 by jpirsch           #+#    #+#             */
/*   Updated: 2015/04/04 13:49:27 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "rtv1.h"

void	init_t_key(t_keys *key)
{
	key->esc = 0;
	key->up = 0;
	key->down = 0;
	key->right = 0;
	key->left = 0;
}

int		key_press(int keycode, t_env *e)
{
	(keycode == 53) ? e->key.esc = 1 : 1;
	(keycode == 125) ? e->key.down = 1 : 1;
	(keycode == 126) ? e->key.up = 1 : 1;
	(keycode == 124) ? e->key.right = 1 : 1;
	(keycode == 123) ? e->key.left = 1 : 1;
	return (1);
}

int		key_release(int keycode, t_env *e)
{
	(keycode == 53) ? e->key.esc = 0 : 1;
	(keycode == 125) ? e->key.down = 0 : 1;
	(keycode == 126) ? e->key.up = 0 : 1;
	(keycode == 124) ? e->key.right = 0 : 1;
	(keycode == 123) ? e->key.left = 0 : 1;
	return (1);
}

int		loop_hook(t_env *e)
{
	(e->key.esc == 1) ? exit(0) : 1;
	(e->key.down == 1) ? e->decaly -= e->zoom / 2 : 1;
	(e->key.up == 1) ? e->decaly += e->zoom / 2 : 1;
	(e->key.right == 1) ? e->decalx -= e->zoom / 2 : 1;
	(e->key.left == 1) ? e->decalx += e->zoom / 2 : 1;
	ft_bzero(e->data, e->size_line * 900);
	draw(e);
	return (1);
}
