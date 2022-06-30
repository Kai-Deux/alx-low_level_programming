#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>

/* 0x02. C - Functions, nested loops */

int _putchar(char c);

void print_alphabet(void);

void print_alphabet_x10(void);

int _islower(int c);

int _isalpha(int c);

int print_sign(int n);

int _abs(int);

int print_last_digit(int);

void jack_bauer(void);

void times_table(void);

int add(int, int);

void print_to_98(int n);

/* 0x03. C - Debugging */

void positive_or_negative(int i);

int largest_number(int a, int b, int c);

void print_remaining_days(int month, int day, int year);

int convert_day(int month, int day);

/* 0x04. C - More functions, more nested loops */

int _isupper(int c);

int _isdigit(int c);

int mul(int a, int b);

void print_numbers(void);

void print_most_numbers(void);

void more_numbers(void);

void print_line(int n);

void print_diagonal(int n);

void print_square(int size);

void print_triangle(int size);

/* 0x05. C - Pointers, arrays and strings */

void reset_to_98(int *n);

void swap_int(int *a, int *b);

int _strlen(char *s);

void _puts(char *str);

void print_rev(char *s);

void rev_string(char *s);

void puts2(char *str);

void puts_half(char *str);

void print_array(int *a, int n);

char *_strcpy(char *dest, char *src);

int _atoi(char *s);

/* 0x06-pointers_arrays_strings */

char *_strcat(char *dest, char *src);

char *_strncat(char *dest, char *src, int n);

char *_strncpy(char *dest, char *src, int n);

int _strcmp(char *s1, char *s2);

void reverse_array(int *a, int n);

char *string_toupper(char *);

char *cap_string(char *);

char *leet(char *);

char *rot13(char *);

/* 0x07. C - Even more pointers, arrays and strings */

char *_memset(char *s, char b, unsigned int n);

char *_memcpy(char *dest, char *src, unsigned int n);

char *_strchr(char *s, char c);

unsigned int _strspn(char *s, char *accept);

char *_strpbrk(char *s, char *accept);

char *_strstr(char *haystack, char *needle);

void print_chessboard(char (*a)[8]);

void print_diagsums(int *a, int size);

void set_string(char **s, char *to);

/* 0x08. C - Recursion */

void _puts_recursion(char *s);

void _print_rev_recursion(char *s);

int _strlen_recursion(char *s);

int factorial(int n);

int _pow_recursion(int x, int y);

int _sqrt_recursion(int n);

int is_prime_number(int n);

int is_palindrome(char *s);

/* 0x0B-malloc_free */

char *create_array(unsigned int size, char c);

char *_strdup(char *str);

char *str_concat(char *s1, char *s2);

int **alloc_grid(int width, int height);

void free_grid(int **grid, int height);

char *argstostr(int ac, char **av);

char **strtow(char *str);

/* 0x0C. C - More malloc, free */

void *malloc_checked(unsigned int b);

char *string_nconcat(char *s1, char *s2, unsigned int n);

void *_calloc(unsigned int nmemb, unsigned int size);

int *array_range(int min, int max);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

/* 101-mul.c */
unsigned int *initDigitArray(size_t size);
void stringIntMultiply(unsigned int *prod_digits, char *n1_digits,
		       char *n2_digits, size_t n1_len, size_t n2_len);
int stringIsPosInt(char *s);
void error(int status);

/* closes double inclusion protection */

#endif 
