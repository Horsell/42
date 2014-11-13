/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/14 11:25:21 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/14 21:25:46 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H
# include "ft_structures.h"

t_btree		*P_ops(char *str, int i);
t_btree		*T_ops(char *str, int i);
t_btree		*E_ops(char *str, int i);
t_btree		*exp_parser(char *str);
#endif
