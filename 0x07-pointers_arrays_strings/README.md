`main.h Prototypes added`
# TASKS
0. Write a function that fills memory with a constant byte.
	- Prototype: `char *_memset(char *s, char b, unsigned int n);`
	- The `_memset()`  function fills the first `n` bytes of the memory area pointed to by `s`  with the constant byte `b`.
	- Returns a pointer to the memory area `s`
1. Write a function that copies memory area.
	- Prototype: `char *_memcpy(char *dest, char *src, unsigned int n);`
	- The `_memcpy()` function copies `n`  bytes from memory area `src` to memory area `dest`
	- Returns a pointer to `dest`
2. Write a function that locates a character in a string.
	- Prototype: `char *_strchr(char *s, char c);`
	- Returns a pointer to the first occurrence of the character `c`  in the string `s` , or `NULL` if the character is not found
3. Write a function that gets the length of a prefix substring.
