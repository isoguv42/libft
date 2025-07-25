/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igyuveni <igyuveni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 19:48:40 by igyuveni          #+#    #+#             */
/*   Updated: 2024/10/29 20:15:15 by igyuveni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

/* BUFFER_SIZE for get_next_line */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# if BUFFER_SIZE < 1
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ========================================================================== */
/*                           CHARACTER FUNCTIONS                             */
/* ========================================================================== */

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_isnum(char *str);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ========================================================================== */
/*                            STRING FUNCTIONS                               */
/* ========================================================================== */

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/* ========================================================================== */
/*                            MEMORY FUNCTIONS                               */
/* ========================================================================== */

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* ========================================================================== */
/*                          CONVERSION FUNCTIONS                             */
/* ========================================================================== */

int		ft_atoi(const char *str);
char	*ft_itoa(int n);

/* ========================================================================== */
/*                            OUTPUT FUNCTIONS                               */
/* ========================================================================== */

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, char c);
int		ft_putptr(unsigned long ptr, int sign);
int		ft_putunsigned(unsigned int n);

/* ========================================================================== */
/*                            PRINTF FUNCTIONS                               */
/* ========================================================================== */

int		ft_printf(const char *str, ...);
int		ft_format(va_list *args, char c);

/* ========================================================================== */
/*                             LIST FUNCTIONS                                */
/* ========================================================================== */

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ========================================================================== */
/*                         GET_NEXT_LINE FUNCTIONS                           */
/* ========================================================================== */

char	*get_next_line(int fd);

/* ========================================================================== */
/*                            UTILITY FUNCTIONS                              */
/* ========================================================================== */

int		ft_digitcount(int n);
size_t	ft_wordcount(const char *s, char delimiter);
void	ft_free_array(char **array, size_t count);
void	ft_free_array_null(char **array);
void	ft_free_split(char **split);

#endif 