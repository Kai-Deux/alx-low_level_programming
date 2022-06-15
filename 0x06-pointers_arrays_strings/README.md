``` main.h Prototypes added ```
# TASKS
0. Write a function that concatenates two strings.
	- Prototype: ```char *_strcat(char *dest, char *src);```
	- This function appends the src string to the dest string, overwriting the terminating null byte (\0) at the end of dest, and then adds a terminating null byte
	- Returns a pointer to the resulting string dest
2. Write a function that concatenates two strings.
	- Prototype: ```char *_strncat(char *dest, char *src, int n);```
	- The _strncat function is similar to the _strcat function, except that
		- it will use at most n bytes from ```src;``` and
		- src does not need to be null-terminated if it contains n or more bytes
	- Return a pointer to the resulting string dest
2. Write a function that copies a string.
	- Prototype: ```char *_strncpy(char *dest, char *src, int n);```
	- Your function should work exactly like strncpy
3. Write a function that compares two strings.
	- Prototype: ```int _strcmp(char *s1, char *s2);```
	- Your function should work exactly like ```strcmp```
4. Write a function that reverses the content of an array of integers.
	- Prototype: ```void reverse_array(int *a, int n);```
	- Where ```n```  is the number of elements of the array
5. Write a function that changes all lowercase letters of a string to uppercase.
	- Prototype: ```char *string_toupper(char *);```
6. Write a function that capitalizes all words of a string.
	- Prototype: ```char *cap_string(char *);```
	- Separators of words: space, tabulation, new line, ```,```, ```;```, ```.```, ```!```, ```?```, ```"```, ```(```, ```),``` ```{```, and ```}```
7. Write a function that encodes a string into ```1337```
	- Letters ```a```  and ```A```  should be replaced by ```4```
	- Letters ```e``` and ```E``` should be replaced by ```3```
	- Letters ```o``` and ```O``` should be replaced by ```0```
	- Letters ```t``` and ```T``` should be replaced by ```7```
	- Letters ```l``` and ```L``` should be replaced by ```1```
	- Prototype: ```char *leet(char *);```
	- You can only use one ```if```in your code
	- You can only use two loops in your code
	- You are not allowed to use ```switch```
	- You are not allowed to use any ternary operation
8. Write a function that encodes a string using rot13.
	- Prototype: ```char *rot13(char *);```
	- You can only use ```if``` statement once in your code
	- You can only use two loops in your code
	- You are not allowed to use ```switch```
	- You are not allowed to use any ternary operation
9. Write a function that prints an integer.
	- Prototype: ```void print_number(int n);```
	- You can only use ```if``` statement once in your code
	- You can only use two loops in your code
	- You are not allowed to use ```switch```
	- You are not allowed to use any ternary operation
10. Add one line to this code, so that the program prints ```a[2] = 98```, followed by a new line.
	- You are not allowed to use the variable ```a``` in your new line of code
	- You are not allowed to modify the variable ```p```
	- You can only write one statement
	- You are not allowed to use ```,```
	- You are not allowed to code anything else than the line of expected line of code at the expected line
	- Your code should be written at line 19, before the ```;```
	- Do not remove anything from the initial code (not even the comments)
	- and don’t change anything but the line of code you are adding (don’t change the spaces to tabs!)
	- You are allowed to use the standard library
11. Write a function that adds two numbers.
	- Prototype: ```char *infinite_add(char *n1, char *n2, char *r, int size_r);```
	- Where ```n1``` and ```n2``` are the two numbers
	- ```r``` is the buffer that the function will use to store the result
	- ```size_r``` is the buffer size
	- The function returns a pointer to the result
	- You can assume that you will always get positive numbers, or ```0```
	- You can assume that there will be only digits in the strings ```n1``` and ```n2```
	- ```n1``` and ```n2``` will never be empty
	- If the result can not be stored in ```r ```the function must return ```0```
!!! ```_putchar``` file added
12. Write a function that prints a buffer.
	- Prototype: ```void print_buffer(char *b, int size);```
	- The function must print the content of ```size```bytes of the buffer pointed by ``` b```
	- The output should print 10 bytes per line
	- Each line starts with the position of the first byte of the line in hexadecimal (8 chars), starting with 0
	- Each line shows the hexadecimal content (2 chars) of the buffer, 2 bytes at a time, separated by a space
	- Each line shows the content of the buffer. If the byte is a printable character, print the letter, if not, print .
	- Each line ends with a new line ```\n```
	- If ```size``` is 0 or less, the output should be a new line only ```\n```
	- You are allowed to use the standard library
	- The output should look like the following example, and formatted exactly the same way:
``` julien@ubuntu:~/0x06$ cat 104-main.c
#include "main.h"
#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    char buffer[] = "This is a string!\0And this is the rest of the #buffer :)\1\2\3\4\5\6\7#cisfun\n\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\x20\x21\x34\x56#pointersarefun #infernumisfun\n";

    printf("%s\n", buffer);
    printf("---------------------------------\n");
    print_buffer(buffer, sizeof(buffer));
    return (0);
}
julien@ubuntu:~/0x06$ gcc -Wall -pedantic -Werror -Wextra -std=gnu89 104-main.c 104-print_buffer.c -o 104-buffer
julien@ubuntu:~/0x06$ ./104-buffer 
This is a string!
---------------------------------
00000000: 5468 6973 2069 7320 6120 This is a 
0000000a: 7374 7269 6e67 2100 416e string!.An
00000014: 6420 7468 6973 2069 7320 d this is 
0000001e: 7468 6520 7265 7374 206f the rest o
00000028: 6620 7468 6520 2362 7566 f the #buf
00000032: 6665 7220 3a29 0102 0304 fer :)....
0000003c: 0506 0723 6369 7366 756e ...#cisfun
00000046: 0a00 0000 0000 0000 0000 ..........
00000050: 0000 0000 0000 0000 0000 ..........
0000005a: 2021 3456 2370 6f69 6e74  !4V#point
00000064: 6572 7361 7265 6675 6e20 ersarefun 
0000006e: 2369 6e66 6572 6e75 6d69 #infernumi
00000078: 7366 756e 0a00           sfun..
julien@ubuntu:~/0x06$ ```
