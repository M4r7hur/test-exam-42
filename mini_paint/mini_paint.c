/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:15:32 by armendes          #+#    #+#             */
/*   Updated: 2022/02/04 17:47:05 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_paint.h"

int	main(int argc, void **argv)
{
	FILE	*stream;

	if (argc != 2)
	{
		write(1, "Error: argument\n", 16);
		return (1);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		write(1, "Error: Operation file corrupted\n", 32);
		return (1);
	}
	
	return (0);
}