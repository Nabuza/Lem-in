/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nagaloul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:04:05 by nagaloul          #+#    #+#             */
/*   Updated: 2017/05/11 17:04:33 by nagaloul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIBFT_H
# define FT_LIBFT_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_strncpy(char *dst, const char *src, size_t len);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strcat(char *s1, const char *s2);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *big, const char *little);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_atoi(const char *str);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
void		*ft_memset(void *b, int c, size_t len);
void		ft_bzero(void *s, size_t c);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
void		ft_putchar(char c);
void		ft_putstr(char *str);
char		*ft_strtrim(char const *s);
char		**ft_remp(char **tab, char const *s, char c, int g);
char		**ft_taille(char **tab, char const *s, char c, int g);
int			ft_decoupe(char const *s, char c);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putnbr(int n);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl(char *str);
size_t		ft_strlen(const char *s);
int			get_next_line(const int fd, char **line);
int			ft_countchar(char *str, char c);
int			ft_strnlen(char *str, char c);
int			ft_isint(char *c);

#endif
