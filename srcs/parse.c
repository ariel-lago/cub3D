/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbestman <rbestman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:00:37 by alago-ga          #+#    #+#             */
/*   Updated: 2026/03/16 18:53:43 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Gets sent the line with the identifier and returns its path/color values.
Increases identifiers by one if it's found the info.
*/
static char	*get_info(char *line, int *identifiers)
{
	int		i;
	char	*ret;
	size_t	len;

	i = 0;
	while (line[i] == ' ')
		i++;
	ret = ft_strdup(&line[i]);
	if (!ret)
		return (NULL);
	len = ft_strlen(ret);
	if (ret && (ret[len - 1] == '\n'))
		ret[len - 1] = '\0';
	if (ret[0] == '\0')
	{
		free(ret);
		return (NULL);
	}
	(*identifiers)++;
	return (ret);
}

/*
 */
static int	compare_identifier(t_map *map, char *line, int *identifiers)
{
	if (ft_strncmp(line, "NO ", 3) == 0 && !map->walls[NORTH])
		map->walls[NORTH] = get_info(&line[3], identifiers);
	else if (ft_strncmp(line, "SO ", 3) == 0 && !map->walls[SOUTH])
		map->walls[SOUTH] = get_info(&line[3], identifiers);
	else if (ft_strncmp(line, "WE ", 3) == 0 && !map->walls[WEST])
		map->walls[WEST] = get_info(&line[3], identifiers);
	else if (ft_strncmp(line, "EA ", 3) == 0 && !map->walls[EAST])
		map->walls[EAST] = get_info(&line[3], identifiers);
	else if (ft_strncmp(line, "F ", 2) == 0 && !map->floor_color)
		map->floor_color = parse_rgb(get_info(&line[2], identifiers));
	else if (ft_strncmp(line, "C ", 2) == 0 && !map->ceiling_color)
		map->ceiling_color = parse_rgb(get_info(&line[2], identifiers));
	else
		return (FAILURE);
	return (SUCCESS);
}

/*
Reads the file line by line and searches for identifiers in each line. 
If it finds an identifier it assigns its value to the struct
It counts the identifiers, if there's a missing identifier it returns failure. 
*/
static int	find_identifiers(int fd, t_map *map)
{
	char	*line;
	int		identifiers;
	int		i;

	identifiers = 0;
	line = get_next_line(fd);
	while (line && identifiers < 6)
	{
		if (compare_identifier(map, line, &identifiers) == FAILURE)
		{
			i = 0;
			while (line[i] == ' ')
				i++;
			if ((line[i] != '\0' && line[i] != '\n') && identifiers < 6)
				return (free(line), error("Wrong identifier", 0), FAILURE);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (!valid_identifiers(map, identifiers))
		return (free(line), FAILURE);
	return (free(line), SUCCESS);
}

/*
Opens the map file, does sets memory to 0 for the map struct.
Looks for identifiers
Finds the max size of the map and loads the map
(strdups it into a string array in the struct)
*/
int	parse(t_map *map, char *map_name)
{
	int	fd;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (error("Open() failed", 1), FAILURE);
	ft_memset(map, 0, sizeof (t_map));
	if (find_identifiers(fd, map) == FAILURE)
		return (flush_gnl(fd), clean_map(map), close(fd), FAILURE);
	if (get_map_size(fd, &map->map_height, &map->map_width) == FAILURE)
		return (flush_gnl(fd), clean_map(map), close(fd), FAILURE);
	close(fd);
	if (load_map(map_name, map) == FAILURE)
		return (clean_map(map), FAILURE);
	if (is_valid_map(map) == FALSE)
		return (clean_map(map), FAILURE);
	if (get_player_start(map) == FAILURE)
		return (clean_map(map), error("Player not found", 0), FAILURE);
	printf("player pos_x: %d\n", map->player_x);
	printf("player pos_y:%d\n", map->player_y);
	printf("player start direction: %c\n", map->player_dir);
	return (SUCCESS);
}
