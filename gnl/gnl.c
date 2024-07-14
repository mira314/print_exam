#include "gnl.h"

char *ft_strchar(char *str, int c)
{
	int i;
	i = 0;

	while (str[i])
	{
		if (str[i] == (char )c)
		{
			return (str);
		}
		i++;
	}
	return (0);
}
unsigned int ft_strlen(char *str)
{
	unsigned int i;
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
char *ft_strcpy(char *dest, char *src)
{
	int i;
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}
char *ft_strdup(char *str)
{
	char *result;
	int len;

	len = ft_strlen(str);
	result = malloc(sizeof(char) + 1);
	if (!result)
		return (0);
	result = ft_strcpy(result, str);
	return (result);
}
char *ft_strjoin(char *s1, char *s2)
{
	unsigned int len1;
	unsigned int len2;
	char *result;
	int i;
	int j;
	i = 0;
	j = 0;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = malloc(sizeof(char) * (len1 + len2 + 1));
		if (!result || !s1 || !s2)
			return (0);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	return (result);
}
char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	char *line;
	char *new;
	int readed;
	int to_copy;

	readed = read(fd, buffer, BUFFER_SIZE);
	line = ft_strdup(buffer);
	new = ft_strchar(line, '\n');
	while (!new && readed)
	{
		buffer[readed] = 0;
		line = ft_strjoin(line, buffer);
		readed = read(fd, buffer, BUFFER_SIZE);
		new = ft_strchar(line, '\n');
	}
	if (ft_strlen(line) == 0)
	{
		return (free(line), 0);
	}
	if (new != 0)
	{
		to_copy = new - line + 1;
		buffer = ft_strcpy(buffer, new + 1);
	}
	else
	{
		to_copy = ft_strlen(line);
		buffer[0] = 0;
	}
	line[to_copy] = 0;
	return (line);
}

#include <stdio.h>
int main(int argc, char *argv[])
{
	char *s1;
	char *s2;
	char *s;

	s1 = "mirado";
	s2 = "valisoa";
	s = ft_strjoin(s1, s2);
	printf("%s\n",s);
	free(s);
	return 0;
}