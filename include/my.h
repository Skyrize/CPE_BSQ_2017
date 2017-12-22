/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** all prototypes
*/

#ifndef MY_H_
#define MY_H_
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <stdio.h>
#include <ncurses.h>
#include <fcntl.h>
void my_putchar(char);
int my_isneg(int);
int my_put_nbr(int);
void my_put_ull(unsigned long long);
void my_put_llnbr(long long int);
void my_putnbr_base(unsigned long long, char *);
int my_swap(int *, int *);
int my_putstr(char const *);
int my_strlen(char const *);
int my_getnbr(char const *);
void my_sort_int_array(int *, int);
int my_compute_power_rec(int, int);
int my_compute_square_root(int);
int my_is_prime(int);
int my_find_prime_sup(int);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
char *my_revstr(char *);
char *my_strstr(char const *, char const *);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, int);
char *my_strupcase(char *);
char *my_strlowcase(char *);
char *my_strcapitalize(char *);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
int my_str_isprintable(char const *);
int my_showstr(char const *);
char *my_double_strcat(char *, char *);
int my_showmem(char const *, int);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, int);
int my_printf(char *, ...);
void my_printunsignedint(va_list);
void my_printchar(va_list);
void my_printint(va_list);
void my_printstr(va_list);
void my_printlowhexa(va_list);
void my_printuphexa(va_list);
void my_printbinary(va_list);
void my_printadress(va_list);
void my_printoctal(va_list);
void my_printpercent(va_list);
void my_printformatedstring(va_list);
int display_file(char *, int *);
int my_ls_main(int, char **, int *);
int display_dir(char *, char *, int *);
int check_opts(int *, char **, int);
void my_putstr_special(int, char *, int);
char *display_rights(struct stat *);
void type_displayer(struct stat *, char *);
int my_opt_r_display(char *, int *, DIR ***);
int display_total_blocks(struct dirent ****, DIR ****, char **, int *);
void print_current_dir(char **, int *);
void display_opt_l(struct stat *, char *, int *);

typedef struct fnct_s
{
	char balise;
	void (*fptr)(va_list list);
} fnct_t;

typedef struct bsq_map_s
{
	unsigned int start_i;
	unsigned int map_size;
	unsigned int int_map_size;
	unsigned int x_len;
	unsigned int y_len;
	char *map;
	int *int_map;
} bsq_map_t;

#define A map->int_map[i - 1]
#define B map->int_map[i - map->x_len - 1]
#define C map->int_map[i - map->x_len]

#endif /* MY_H_ */
