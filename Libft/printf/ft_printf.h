/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:06:26 by cmatos-a          #+#    #+#             */
/*   Updated: 2024/11/14 18:02:07 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stddef.h>

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb, int fd);
int		ft_printunsignd(unsigned int nb, int fd);
int		ft_printhexa(unsigned long n, const char t, int count);
int		ft_printptr(unsigned long p);
int		ft_printf(const char *s, ...);

#endif