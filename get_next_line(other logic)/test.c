#include "get_next_line.h"
char *ft_set_line(char *buffer)
{
	int i = 0;
	char *new_s;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		i++;
	new_s = ft_substr(buffer, i, ft_strlen(buffer) - i);
	if (*new_s == 0)
	{
		free(new_s);
		new_s = NULL;
	}
	buffer[i] = '\0';
	return new_s;
}

char *ft_fill_buffer(int fd, char *s_tab, char *buffer)
{
	ssize_t byte = 1;
	char *temp;
	while (byte > 0)
	{
		byte = read(fd, buffer, BUFFER_SIZE);
		if (byte < 0)
		{
			free(buffer);
			return NULL;
		}
		if (byte == 0)
			break;
		buffer[byte] = '\0';
		temp = s_tab;
		s_tab = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	return s_tab;
}

char *get_next_line(int fd)
{
	static char *s_tab[OPEN_MAX] = {NULL};
	char *buffer;
	char *line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
	{
		return NULL;
	}
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return NULL;
	line = ft_fill_buffer(fd, s_tab[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return NULL;
	s_tab[fd] = ft_set_line(line);
	if (s_tab[fd] == NULL)
	{
		free(s_tab[fd]);
		s_tab[fd] = NULL;
	}
	return line;
}

int main()
{
	int fd = open("example.txt", O_RDONLY);
	int fd1 = open("example1.txt", O_RDONLY);
	char *line;

	// line = get_next_line(fd);
	// printf("fd->%s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1->%s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("fd->%s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1->%s", line);
	// free(line);
	// line = get_next_line(fd);
	// printf("fd->%s", line);
	// free(line);
	// line = get_next_line(fd1);
	// printf("fd1->%s", line);
	// free(line);

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
		while ((line = get_next_line(fd1)) != NULL)
		{
			printf("%s", line);
			free(line);
			break;
		}
	}
	close(fd);
	return 0;
}