#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lenght;

	i = 0;
	lenght = ft_strlen(src);
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (lenght);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;
	size_t	y;

	i = 0;
	j = 0;
	y = ft_strlen(src);
	if (!dst && size == 0)
		return (y);
	while (dst[j] != '\0')
	{
		j++;
	}
	x = j;
	if (size == 0 || size <= x)
		return (y + size);
	while (src [i] != '\0' && i < size - x - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (x + y);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*array;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	array = (char *)malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	while (s[i])
	{
		array[i] = s[i];
		i++;
	}
	array[i] = '\0';
	return (array);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	size_t	len1;
	size_t	len2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = (char *)malloc((len1 + len2 + 1));
	if (array == NULL)
		return (NULL);
	ft_strlcpy(array, s1, len1 + 1);
	ft_strlcat(array, s2, len1 + len2 + 1);
	return (array);
}
static void	ft_cpy(const char *s, unsigned int start, char	*array, size_t len)
{
	size_t	j;
	size_t	i;

	j = 0;
	i = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			array[j] = s[i];
			j++;
		}
		i++;
	}
	array[j] = '\0';
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*array;

	if (!s)
		return (0);
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	if (start >= ft_strlen(s))
	{
		array = (char *)malloc(sizeof(char));
		if (array != NULL)
			array[0] = '\0';
		return (array);
	}
	array = (char *)malloc((len + 1) * sizeof(char));
	if (array == NULL)
		return (NULL);
	ft_cpy(s, start, array, len);
	return (array);
}