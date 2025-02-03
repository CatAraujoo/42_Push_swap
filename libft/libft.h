/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmatos-a <cmatos-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:16:01 by cmatos-a          #+#    #+#             */
/*   Updated: 2025/02/03 10:52:52 by cmatos-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_list
{
	struct s_list			*next;
	void					*content;
}					t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int a);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int i);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *dest, size_t size);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
void	*ft_calloc(size_t n, size_t size);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_toupper(int a);
int		ft_tolower(int b);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *str, int c, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strnstr(const char *b, const char *s, size_t size);
int		ft_atoi(const char *str);
char	*ft_strdup(char *src);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *str1, char const *str2);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strtrim(const char *str, const char *set);
void	ft_putendl_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	**ft_split(char const *s, char d);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char	*read_file(int fd, char *s);
char	*ft_strjoin(char const *str1, char const *str2);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *str1, char const *str2);
char	*ft_strdup(char *src);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);

int		ft_printchar(int c);
int		ft_printstr(char *str);
int		ft_printnbr(int nb, int fd);
int		ft_printunsignd(unsigned int nb, int fd);
int		ft_printhexa(unsigned long n, const char t, int count);
int		ft_printptr(unsigned long p);
int		ft_printf(const char *s, ...);

#endif
