/*
** EPITECH PROJECT, 2017
** BSQ
** File description:
** main.c
*/
#include "include/my.h"

void check_end_of_line(bsq_map_t *map, int *a, int *i)
{
	if ((*i + 1) % map->x_len == 0) {
		*a += 2;
		(*i)++;
	}
}

void look_for_biggest_square_with_numbers(bsq_map_t *map)
{
	int a = map->start_i + map->x_len + 2;

	for (int i = map->x_len + 1 ; i < map->int_map_size ; i++ , a++) {
		if (A <= C && A <= B) {
			map->int_map[i] = A + 1;
		} else if (B <= A && B <= C) {
			map->int_map[i] = B + 1;
		} else if (C <= A && C <= B) {
			map->int_map[i] = C + 1;
		}
		if (map->map[a] == 'o')
			map->int_map[i] = 0;
		check_end_of_line(map, &a, &i);
	}
}

void fill_first_col(bsq_map_t *map, int i, int a)
{
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
	for (int x = 0 ; x < map->int_map_size ; x++) {
		if (x > 0 && x % map->x_len == 0) {
			printf("\n");
		}
		printf("%d", map->int_map[x]);
	}
	printf("\nmap x_len = %d /// map y_len = %d\n", map->x_len, map->y_len);
}

void create_int_map(bsq_map_t *map)
{
	int i = 0;
	int a = 0;

	map->int_map = malloc(sizeof(int) * (map->y_len * map->x_len));
	if (map->int_map == NULL)
		exit (84);
	for (; map->map[i] != '.' ; i++);
	map->start_i = i;
	for (; map->map[i] != '\n' ; i += 1, a +=1) {
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
	map.int_map_size = map.x_len * map.y_len;
	printf("%s\n", map.map);
	create_int_map(&map);
	return (0);
}
