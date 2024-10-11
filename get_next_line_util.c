#include <stdlib.h>
#include <unistd.h>

void *ft_calloc(size_t items, size_t size);
void ft_bzero(void *s, size_t n);
size_t ft_strlen(char const *str);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strchr(const char *str, int search_str);

void *ft_calloc(size_t items, size_t size)
{
    char *array;

    array = (char *)malloc(items * size);
    if (array == NULL)
        return NULL;
    ft_bzero(array, items * size);
    return array;
}

void ft_bzero(void *s, size_t n)
{
    size_t i = 0;
    char *str = s;
    while (i < n)
    {
        str[i] = 0;
        i++;
    }
}

size_t ft_strlen(char const *str)
{
    size_t i = 0;
    while (str[i])
    {
        i++;
    }
    return i;
}

char *ft_strjoin(char const *s1, char const *s2)
{
    char *array;
    int i = 0;
    int j = 0;
    if (!s1 || !s2)
        return 0;
    array = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
    if (array == NULL)
        return NULL;
    while (s1[i])
    {
        array[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        array[i] = s2[j];
        j++;
        i++;
    }
    array[i] = '\0';
    return array;
}

char *ft_strchr(const char *str, int search_str)
{
    size_t i = 0;
    unsigned char c = (unsigned char)search_str;

    if (c == '\0')
        return (char *)(str);
    while (str[i] != '\0')
    {
        if (str[i] == c)
        {
            return (char *)(str + i);
        }
        i++;
    }
    return NULL;
}