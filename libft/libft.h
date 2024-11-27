#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);

void	ft_putendl_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char const *s);

#endif
