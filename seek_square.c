/*
** EPITECH PROJECT, 2017
** CPE_BSQ_2017
** File description:
** (seek_square functions)
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
