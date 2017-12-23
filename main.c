/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** main.c
*/
#include "include/my.h"

void put_x_in_map(bsq_map_t *map)
{
	int a = 0;

	for (unsigned int i = map->pos; a < map->square_size * map->square_size; i--) {
		if (a > 0 && a % map->square_size == 0) {
			i = i - map->x_len + map->square_size - 1;
		}
		map->map[i] = 'x';
		a++;
	}
}

void check_end_of_line(bsq_map_t *map, int *a, int *i)
{
	if ((*i + 1) % map->x_len == 0) {
		*a += 2;
		(*i)++;
	}
}

void stock_square_size_and_pos(bsq_map_t *map, int i, int a)
{
	if (map->int_map[i] > map->square_size) {
		map->square_size = map->int_map[i];
		map->pos = a;
	}
}

void look_for_biggest_square_with_numbers(bsq_map_t *map)
{
	int a = map->starter + map->x_len + 2;

	for (int i = map->x_len + 1; i < map->int_map_length; i++, a++) {
		if (map->map[a] == 'o') {
			map->int_map[i] = 0;
			check_end_of_line(map, &a, &i);
			continue;
		}
		if (A <= C && A <= B) {
			map->int_map[i] = A + 1;
		} else if (B <= A && B <= C) {
			map->int_map[i] = B + 1;
		} else if (C <= A && C <= B) {
			map->int_map[i] = C + 1;
		}
		stock_square_size_and_pos(map, i, a);
		check_end_of_line(map, &a, &i);
	}
	put_x_in_map(map);
}

void fill_first_col(bsq_map_t *map, int i, int a)
{
	map->square_size = 0;
	map->pos = 0;
	while (i < map->y_len * map->x_len + map->x_len) {
		switch (map->map[i]) {
			case '.':
			map->int_map[a] = 1;
			break;
			case 'o':
			map->int_map[a] = 0;
			break;
		}
		a += map->x_len;
		i += map->x_len + 1;
	}
	look_for_biggest_square_with_numbers(map);
}

void create_int_map(bsq_map_t *map)
{
	int i = 0;
	int a = 0;

	map->int_map = malloc(sizeof(int) * (map->y_len * map->x_len));
	if (map->int_map == NULL)
		exit (84);
	for (; map->map[i] != '.' && map->map[i] != 'o'; i++)
		map->map[i] = 0;
	map->starter = i;
	for (; map->map[i] != '\n'; i += 1, a +=1) {
		switch (map->map[i]) {
			case '.':
			map->int_map[a] = 1;
			break;
			case 'o':
			map->int_map[a] = 0;
			break;
		}
	}
	fill_first_col(map, i + 1, a);
}

int main(int ac, char **av)
{
	int fd = 0;
	int error_no = 0;
	struct stat buf;
	bsq_map_t map;

	if (ac != 2)
		return (84);
	fd = open(av[1], O_RDONLY);
	error_no = stat(av[1], &buf);
	if (fd == -1 || error_no == -1)
		return (84);
	map.map = malloc(sizeof(char) * (buf.st_size + 1));
	read(fd, map.map, buf.st_size);
	map.map[buf.st_size] = 0;
	map.y_len = my_getnbr(map.map);
	map.x_len = (buf.st_size - map.y_len - 1) / map.y_len;
	map.int_map_length = map.x_len * map.y_len;
	create_int_map(&map);
	write(1, map.map, buf.st_size);
	return (0);
}
