/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpirsch <jpirsch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 17:20:04 by jpirsch           #+#    #+#             */
/*   Updated: 2014/09/07 23:16:26 by jpirsch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		backtrack(char **tab, int position);
int		test_value(char **tab, int i, int j, char n);
int		exist_in_row(char **tab, char n, int i);
int		exist_in_column(char **tab, char n, int j);
int		exist_in_square(char **tab, char n, int i, int j);
