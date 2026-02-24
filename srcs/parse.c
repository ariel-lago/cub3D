/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alago-ga <alago-ga@student.42berlin.d>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 17:00:37 by alago-ga          #+#    #+#             */
/*   Updated: 2026/02/23 19:51:17 by alago-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//looks for the identifier and returns the path/color values attached
//note: should I add an is space function or do we accept the subjet means a normal ' ' space?
static char	*get_info(char *map_name, char *id)
{
	int		fd;
	int		i;
	char	*line;
	char	*ret;

	fd = open(map_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (ft_strncmp(&line[i], id, ft_strlen(id)) == SUCCESS)
		{
			i += ft_strlen(id);
			while (line[i] == ' ')
				i++;
			ret = ft_strdup(&line[i]);
			if (ret && (ret[ft_strlen(ret) - 1] == '\n'))
				ret[ft_strlen(ret) - 1] = '\0';
			free(line);
			close(fd);
			return (ret);
		}
		free (line);
		line = get_next_line(fd);
	}
	close(fd);
	return (error("Error\nMissing identifier"), NULL);
}

static int	get_wall_paths(char *map_name, char *wall_paths[])
{
	wall_paths[0] = get_info(map_name, "NO");
	printf("NO: %s\n", wall_paths[0]);
	wall_paths[1] = get_info(map_name, "SO");
	printf("SO: %s\n", wall_paths[1]);
	wall_paths[2] = get_info(map_name, "WE");
	printf("WE: %s\n", wall_paths[2]);
	wall_paths[3] = get_info(map_name, "EA");
	printf("EA: %s\n", wall_paths[3]);
	if (!wall_paths[0] || !wall_paths[1] || !wall_paths[2] || !wall_paths[3])
		return (FAILURE);
	return (SUCCESS);
}

int	parse(t_map *map, char *map_name)
{
	ft_memset(map, 0, sizeof (t_map));
//	map.width = get_map_width(map_name);
//	map.length = get_map_length(map_name);
//	map.player_x = get_x_pos(map_name);
//	map.player_y = get_y_pos(map_name);
//	map.player_dir = get_player_dir(map_name);
	if (get_wall_paths(map_name, map->walls) == FAILURE)
		return (error("Error"), FAILURE);
	map->floor_color = get_info(map_name, "F");
	printf("floor color: %s\n", map->floor_color);
	map->ceiling_color = get_info(map_name, "C");
	printf("ceiling color: %s\n", map->ceiling_color);
	if (!map->floor_color || !map->ceiling_color)
		return (FAILURE);
	if (get_map_size(map_name, &map->map_height, &map->map_width) == FAILURE)
		return (FAILURE);
	if (load_map(map_name, map) == FAILURE)
		return (error("Error\nCould not load map"), FAILURE);
	return (SUCCESS);
}

/*
int	parse(t_map *map, char *map_name)
{
	(void)map_name;
	(void)map;

	return (0);
}*/
