#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);
void *ft_calloc(size_t items, size_t size);
char *ft_strchr(const char *str, int search_str);
size_t ft_strlen(char const *str);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_handle_loc(char *tab, char *buffer);
char *ft_line(char *buffer);
char *ft_next_call(char *buffer);

char *ft_handle_loc(char *tab, char *buffer)
{
    char *temp;
    temp = ft_strjoin(tab, buffer);
    free(tab);
    return temp;
}

char *ft_line(char *buffer)
{
    int i = 0;
    int j = 0;
    char *line;
    if (!buffer[i])
        return NULL;
    
    while (buffer[i] && buffer[i] != '\n')
        i++;
    line = ft_calloc((i + 2), sizeof(char));
    if (!line)
        return NULL;
    while (j < i)
    {
        line[j] = buffer[j];
        j++;
    }
    if (buffer[i] == '\n')
    {
        line[j++] = '\n';
    }
    line[j] = '\0';
    return line;
}

char *ft_next_call(char *buffer)
{
    /*
        -= first it loop with 'i' to find the newline '\n' or '\0' then count the lengths of buffer all buffer and make the 
            oper 'lenght - i + 1' to copy the next characters after the '\n' or '\0'.
    */
    int i = 0;
    int j = 0;
    char *new_buffer;

    if (!buffer[i])
        return NULL;
    while (buffer[i] && buffer[i] != '\n')
        i++;
    new_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
    if (!new_buffer)
    {
        free(buffer);
        return NULL;
    }
    i++;
    while (buffer[i]) {
        new_buffer[j++] = buffer[i++];
    }
    free(buffer);
    return new_buffer;
}


char *ft_read_line(int fd, char *tab)
{
    char *buffer;
    int byte;

    if (!tab)
        tab = ft_calloc(1, 1);

    buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
    byte = 1;
    while (byte > 0)
    {
        byte = read(fd, buffer, BUFFER_SIZE);
        if (byte == -1)
        {
            free(buffer);
            return NULL;
        }
        buffer[byte] = '\0';
        tab = ft_handle_loc(tab, buffer);
        if (ft_strchr(buffer, '\n'))
            break;
    }
    free(buffer);
    return tab;
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
        return 0;
    buffer = ft_read_line(fd, buffer);
    if (!buffer)
        return NULL;
    line = ft_line(buffer);
    buffer = ft_next_call(buffer);
    return line;
}