/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vloddo <vloddo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:02:58 by vloddo            #+#    #+#             */
/*   Updated: 2025/10/27 21:01:10 by vloddo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

int	count_lines(const char *file)
{
	int		fd;
	int		count;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	fill_array(char **array, const char *file, int rows)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (-1);
	i = 0;
	line = get_next_line(fd);
	while (line && i < rows)
	{
		array[i++] = line;
		line = get_next_line(fd);
	}
	array[i] = NULL;
	close(fd);
	return (0);
}

char	**ft_create_array(const char *file)
{
	int		rows;
	char	**array;

	rows = count_lines(file);
	if (rows < 0)
		return (NULL);
	array = malloc(sizeof(char *) * (rows + 1));
	if (!array)
		return (NULL);
	if (fill_array(array, file, rows) < 0)
	{
		free(array);
		return (NULL);
	}
	return (array);
}
