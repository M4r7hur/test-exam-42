/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armendes <armendes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 21:39:38 by armendes          #+#    #+#             */
/*   Updated: 2022/01/18 17:40:06 by armendes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	nbr_len(long long n, int base_len)
{
	int		i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= base_len;
		i++;
	}
	return (i);
}

char	*ft_itoa_base(long long n, char *base)
{
	char		*str;
	int			n_len;
	int			base_len;
	int			tmp;

	base_len = ft_strlen(base);
	n_len = nbr_len(n, base_len);
	str = malloc(sizeof(char) * n_len + 1);
	if (str == NULL)
		return (NULL);
	str[n_len] = '\0';
	while (--n_len >= 0)
	{
		tmp = (n % base_len);
		if (tmp < 0)
			tmp *= -1;
		str[n_len] = base[tmp];
		n /= base_len;
	}
	return (str);
}

int	print_format(char *format, va_list *vargs)
{
	int		c_disp;
	int		i;
	char	*str;
	int		n;
	unsigned int x;

	c_disp = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] != '%')
		{
			++c_disp;
			write(1, &format[i], 1);
		}
		else
		{
			i++;

			if (format[i] == 's')
			{
				str = va_arg(*vargs, char *);
				if (str != NULL)
				{
					write(1, str, ft_strlen(str));
					c_disp += ft_strlen(str);
				}
				else
				{
					write(1, "(null)", ft_strlen("(null)"));
					c_disp += ft_strlen("(null)");
				}
			}

			else if (format[i] == 'd')
			{
				n = va_arg(*vargs, int);
				if (n < 0)
				{
					write(1, "-", 1);
					c_disp++;
					n *= -1;
				}
				str = ft_itoa_base(n, "0123456789");
				write(1, str, ft_strlen(str));
				c_disp += ft_strlen(str);
			}

			else if (format[i] == 'x')
			{
				x = va_arg(*vargs, unsigned int);
				str = ft_itoa_base(x, "0123456789abcdef");
				write(1, str, ft_strlen(str));
				c_disp += ft_strlen(str);
			}

		}
		i++;
	}
	return (c_disp);
}

int	ft_printf(char *format, ...)
{
	va_list		vargs;
	int			c_disp;

	if (format == NULL)
		return (-1);
	else if (ft_strlen(format) == 0)
		return (0);
	va_start(vargs, format);
	c_disp = print_format(format, &vargs);
	va_end(vargs);
	return (c_disp);
}

int	main(void)
{
	int n = -42;
	printf("F---%d--- | ", ft_printf("%x", n));
	printf("V---%d---", printf("%x", n));
}
