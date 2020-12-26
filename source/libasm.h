#ifndef LIBASM_H
# define LIBASM_H
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_list
{
	void	*data;
	struct	s_list *next;
}				t_list;

size_t		 	ft_strlen(char *str);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t 		ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *s);
#endif