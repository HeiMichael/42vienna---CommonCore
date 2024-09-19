/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vschneid <vschneid@student.42vienna.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 13:16:33 by miheider          #+#    #+#             */
/*   Updated: 2024/09/10 16:44:14 by vschneid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H 

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

# ifndef FD
#  define FD 4098
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_isprint(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
int		ft_toupper(int c);
char	*ft_strchr(const char *s, int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_tolower(int c);
void	ft_bzero(void *s, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strdup(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
int		ft_atoi(const char *nptr);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	**ft_split(char const *s, char c);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_itoa(int n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));

// GET NEXT LINE

//char	*get_next_line(int fd, unsigned char *bool);
char	*get_next_line(int fd, unsigned char *bool, char **pot);
char	*vs_buff_to_pot(int fd, char *pot_str, unsigned char *bool);
char	*vs_check_line(char *pot_str, unsigned char *bool);
char	*vs_fresh_pot(char *old_pot, unsigned char *bool);
char	*vs_strchr(const char *s, int c);
int		vs_strlen(const char *str);
char	*vs_strjoint(char *left_str, char *buff, unsigned char *bool);
char	*copy_to_string(char *left_str, char *str, char *buff);
char	*change_bool(unsigned char *bool);
char	*buff_to_pot_error(char *buff, char *pot_str);
int		read_bytes(int fd, int bytes, char *buff, char *pot_str);
void	free_stuff(char *buff, char *pot_str);
void	final_line_error(unsigned char *bool, char *pot_str);
void	new_pot_error(unsigned char *bool, char *new_pot, char *old_pot);

#endif
