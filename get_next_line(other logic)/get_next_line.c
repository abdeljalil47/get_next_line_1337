#include "get_next_line.h"

char *set_line(char *line_buffer)
{
    char *left_c;
    size_t i = 0;
    while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
        i++;
    if (line_buffer[i] == '\n')
        i++;
    left_c = ft_substr(line_buffer, i, ft_strlen(line_buffer) - i);
    if (*left_c == 0)
    {
        free(left_c);
        left_c = NULL;
    }
    line_buffer[i] = '\0';
    return left_c;
}

char *fill_line_buffer(int fd, char *left_c, char *buffer)
{
    int byte = 1;
    char *tmp;
    ssize_t check;

    while (byte > 0)
    {
        check = read(fd, buffer, BUFFER_SIZE);
        if (check < 0)
        {
            free(buffer);
            return NULL;
        }
        if (check == 0)
            break;
        buffer[check] = '\0';
        tmp = left_c;
        left_c = ft_strjoin(tmp, buffer);
        free(tmp);
        tmp = NULL;
        if (ft_strchr(buffer, '\n'))
            break;
    }
    return left_c;
}

char *get_next_line(int fd)
{
    static char *left_c = NULL;
    char *line;
    char *buffer;
    if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
    {
        free(left_c);
        left_c = NULL;
        return NULL;
    }
    buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (!buffer)
        return NULL;
    line = fill_line_buffer(fd, left_c, buffer);
    free(buffer);
    buffer = NULL;
    if (!line)
        return NULL;
    left_c = set_line(line);
    if (left_c == NULL)
    {
        free(left_c);
        left_c = NULL;
    }
    return line;
}
