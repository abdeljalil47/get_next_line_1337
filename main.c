#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char *get_next_line(int fd);
void *ft_calloc(size_t items, size_t size);
char *ft_strchr(const char *str, int search_str);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_line(char *buffer);

#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char *line;
    while ((line = get_next_line(fd)) != NULL) {
        printf("%s", line);
        free(line);
    }

    close(fd);
    return 0;
}
