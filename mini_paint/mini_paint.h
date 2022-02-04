/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:15:49 by armendes          #+#    #+#             */
/*   Updated: 2022/02/04 17:36:19 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdio.h>

typedef struct	s_config
{
	int		w;
	int		h;
	char	bc
}				t_config;

typedef struct	s_ope
{
	char	c;
	float	x;
	float	y;
	float	radius;
	char	cc;
}				t_ope;

#endif