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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (malloc(1));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_fill(int fd, char *readed, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(readed);
			return (0);
		}
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!readed)
			readed = ft_strdup("");
		temp = readed;
		readed = ft_strjoin(temp, buffer);
		free (temp);
		temp = 0;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (readed);
}
char	*ft_set_line(char *line)
{
	char	*readed;
	int		i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == 0 || line[1] == 0)
		return (0);
	readed = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (*readed == 0)
	{
		free(readed);
		readed = 0;
	}
	line[i + 1] = 0;
	return (readed);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		free(readed);
		readed = 0;
		buffer = 0;
		return (0);
	}
	if (!buffer)
		return (0);
	line = ft_fill(fd, readed, buffer);
	free(buffer);
	buffer = 0;
	if (!line)
		return (0);
	readed = ft_set_line(line);
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