

#include "libft.h"

char    *ft_strtrim(char const *s1, char const *set)
{
    char    *t1;
    int     t1_len;
    int     i;
    char    *str;

    if (!s1 || !set)
      return (NULL);
    t1 = (char *)s1;
    t1_len = ft_strlen(t1);
    i = 0;
    while (i <= (t1_len - 1) && ft_strchr(set, t1[i]))
            i++;
    if (i > t1_len) 
      return (ft_strdup(t1) + (t1_len - 1) + 1);
    while ((t1_len - 1) > 0 && (ft_strchr(set, t1[t1_len - 1])))
        t1_len--;
    str = malloc((t1_len - 1) - i + 2);
    if (str == NULL)
      return (NULL);
    ft_strlcpy(str, &s1[i], (t1_len - 1) - i + 2);
      return (str);
    }
/*
int main(void)
{
char a[] = "xxxxxkjhzgzgxxxxx";
char b[] = "x";

printf("output: %s", ft_strtrim(a, b));
}*/