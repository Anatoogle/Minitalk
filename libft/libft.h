/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemykin <asemykin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 12:11:05 by asemykin          #+#    #+#             */
/*   Updated: 2024/11/26 10:47:34 by asemykin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
The	atoi(void) function converts a string to an integer.
Functionality: It converts a string representing a number into its integer value.
Conversion stops at the first non-digit character.
Return: It returns the integer value of the converted string.
If the string is not a valid number, it returns 0.
*/
int					ft_atoi(const char *nptr);

/*
The	bzero(void) function is used to set a block of memory to zero.
Functionality: It fills a specified number of bytes in a memory area
with the value zero (0).
Return: It does not return any value (void).
*/
void				ft_bzero(void *s, size_t n);

/*
The	calloc(void) function allocates memory for an array of elements,
initializing the memory to zero.
Functionality: It allocates memory for nmemb elements, each of size size,
and initializes all of the allocated memory to zero.
Return: It returns a pointer to the allocated memory.
If the memory allocation fails, it returns NULL.
*/
void				*ft_calloc(size_t nmemb, size_t size);

/*
The	isalnum(void) function checks if a given character is either an
alphabetic letter (A-Z or a-z) or a digit (0-9).
It returns a non-zero value (true) if the character is alphanumeric,
and 0 (false) if it is not.
*/
int					ft_isalnum(int c);

/*
The	isalpha(void) function checks if a given character is an alphabetic letter.
It returns a non-zero value (true) if the character is alphabetic,
and 0 (false) if it is not.
*/
int					ft_isalpha(int c);

/*
The	isascii(void) function checks if a given character has an ASCII value
(i.e., if the character is within the range of 0 to 127).
It returns a non-zero value (true) if the character is an ASCII character,
and 0 (false) if it is not.
*/
int					ft_isascii(int c);

/*
The	isdigit(void) function checks if a given character is a digit.
It returns a non-zero value (true) if the character is a digit,
and 0 (false) if it is not.
*/
int					ft_isdigit(int c);

/*
The	isprint(void) function checks if a given character is a
printable character, which includes letters, digits, punctuation marks,
and whitespace characters (such as space).
It returns a non-zero value (true) if the character is printable,
and 0 (false) if it is not.
*/
int					ft_isprint(int c);

/*
The	itoa(void) function converts an integer to a string.
Functionality: It converts the given integer n into a null-terminated
string representing the number.
Return: It returns a pointer to the string that represents the integer.
The returned string must be freed by the caller once it's no longer needed.
*/
char				*ft_itoa(int n);

/*
The	memchr(void) function searches for the first occurrence of a
character in a block of memory.
Functionality: It scans the memory block pointed to by s for the first occurrence
of the character c (converted to an unsigned char),
	within the first n bytes of the block.
Return: It returns a pointer to the found character, or NULL if the character
is not found within the specified memory range.
*/
void				*ft_memchr(const void *s, int c, size_t n);

/*
The	memcmp(void) function compares two memory blocks byte by byte.
Functionality:
It compares the first n bytes of memory areas s1 and s2.
The comparison is done byte by byte, and the function returns:
	- A negative value if the first differing byte in s1 is less than the
	corresponding byte in s2.
	- Zero if the memory blocks are identical for the first n bytes.
	- A positive value if the first differing byte in s1 is greater than the
	corresponding byte in s2.
Return: It returns an integer based on the comparison result.
*/
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/*
The	memcpy(void) function is used to copy a specified number of bytes from one
memory location to another.
Functionality: It copies num bytes from the source memory block (src) to
the destination memory block (dest).
Return: It returns a pointer to the destination memory block (dest).
*/
void				*ft_memcpy(void *dest, const void *src, size_t n);

/*
The	memmove(void) function copies a block of memory from one location to another,
handling potential overlap between the source and destination.
Functionality: It copies n bytes from the memory area src to dest.
Unlike	memcpy(void),
		memmove() ensures that the copying is safe even if the memory
regions overlap. It handles the copying by first determining whether the regions
overlap and then adjusting the copying process accordingly.
Return: It returns a pointer to the destination memory area (dest).
*/
void				*ft_memmove(void *dest, const void *src, size_t n);

/*
The	memset(void) function is used to set a block of memory to a specific value.
Functionality: It fills a specified number of bytes of a memory area with a
given value.
Return: It returns a pointer to the memory area that was set.
*/
void				*ft_memset(void *s, int c, size_t n);

/*
The	ft_putchar_fd(void) function writes a character to a specified
file descriptor.
Functionality: It writes the character c to the file or output stream associated
with the file descriptor fd.
Return: The function does not return any value (void).
*/
void				ft_putchar_fd(char c, int fd);

/*
The	ft_putendl_fd(void) function writes a string followed by a newline to a
specified file descriptor.
Functionality: It writes the string s to the file or output stream associated
with the file descriptor fd, followed by a newline character ('\n').
Return: The function does not return any value (void).
*/
void				ft_putendl_fd(char *s, int fd);

/*
The	ft_putnbr_fd(void) function writes an integer to a specified file descriptor.
Functionality: It converts the integer n to its string representation and writes
it to the file or output stream associated with the file descriptor fd.
Return: The function does not return any value (void).
*/
void				ft_putnbr_fd(int n, int fd);

/*
The	ft_putstr_fd(void) function writes a string to a specified file descriptor.
Functionality: It writes the string s to the file or output stream associated
with the file descriptor fd.
Return: The function does not return any value (void).
*/
void				ft_putstr_fd(char *s, int fd);

/*
The	ft_split(void) function splits a string into an array of substrings,
using a specified delimiter character.
Functionality: It divides the string s into multiple substrings, each
separated by the delimiter character c. The function returns an array of strings,
 where each element is a substring from the original string.
Return: It returns a pointer to an array of strings (array of char*),
	with each string
being a substring of s. The array is terminated by a NULL pointer.
*/
char				**ft_split(char const *s, char c);

/*
The	ft_strchr(void) function locates the first occurrence of a character
in a string.
Functionality: It searches for the first occurrence of the character c
(converted to a char) in the string s. The function returns a pointer
to the first occurrence of c, or NULL if c is not found.
Return: A pointer to the first occurrence of the character c in the string s,
or NULL if c is not found.
*/
char				*ft_strchr(const char *s, int c);

/*
The	ft_strdup(void) function creates a copy of a string.
Functionality: It allocates memory for a new string and copies the contents of
the string s into it, including the null terminator.
Return: It returns a pointer to the newly allocated string,
	which is a copy of s.
If memory allocation fails, it returns NULL.
*/
char				*ft_strdup(const char *s);

/*
The	ft_striteri(void) function applies a given function to each character of
a string, passing its index and the character itself.
Functionality: It iterates over the string s, and for each character,
it calls the function f with the current index and the character's pointer.
This allows the function to modify the string in place.
Return: The function does not return any value (void).
*/
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
The	ft_strjoin(void) function concatenates two strings into a new string.
Functionality: It allocates memory for a new string that is the result of
joining s1 and s2. The function copies both strings into the new string,
with s1 followed by s2.
Return: It returns a pointer to the newly allocated string that contains
the concatenation of s1 and s2. If memory allocation fails, it returns NULL.
*/
char				*ft_strjoin(char const *s1, char const *s2);

/*
The	ft_strlcat(void) function concatenates two strings, ensuring that the total
length of the resulting string does not exceed a specified size.
Functionality: It appends the string src to the string dst, but it ensures
that no more than size - 1 characters are written to dst. The function always
null-terminates the result (if there is space). The function also returns the
total length of the concatenated string (i.e.,
	the length of dst and src combined),
which helps in preventing buffer overflows.
Return: It returns the total length of the string that would have been created
if there were no size limit (i.e., strlen(dst) + strlen(src)).
*/
size_t				ft_strlcat(char *dst, const char *src, size_t size);

/*
The	ft_strlcpy(void) function copies a string from src to dst, ensuring that the
destination buffer is not overflowed.
Functionality: It copies up to size - 1 characters from the string src to dst,
 ensuring that dst is null-terminated. If size is greater than the length of src,
 the remaining space in dst is filled with null characters. The function returns
 the total length of the string it tried to copy, which is the length of src.
Return: It returns the total length of the source string src,
which helps in determining if the copy was truncated.
*/
size_t				ft_strlcpy(char *dst, const char *src, size_t size);

/*
The	strlen(void) function calculates the length of a null-terminated string,
excluding the terminating null character ('\0').
It returns the number of characters in the string
(not including the null terminator).
*/
size_t				ft_strlen(const char *s);

/*
The	strmapi(void) function applies a given function to each character of
a string, passing its index and the character to the function.
Functionality: It creates a new string by applying the function f to each
character of the string s. The function f takes the character's index and
the character itself as arguments and returns a transformed character.
The new string is returned.
Return: It returns a pointer to the newly created string.
*/
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
The	ft_strncmp(void) function compares two strings up to a specified number of
characters.
Functionality: It compares the first n characters of the strings s1 and s2.
The comparison stops when either a difference is found or when n characters
have been compared. The function returns:
	- A negative value if s1 is lexicographically less than s2 in the first n
		characters.
	- Zero if the first n characters of both strings are equal.
	- A positive value if s1 is lexicographically greater than s2 in the first
		n characters.
Return: It returns an integer indicating the difference between the first
differing characters, or zero if the strings are equal.
*/
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/*
The	ft_strnstr(void) function locates the first occurrence of a substring within
a string, considering a maximum number of characters.
Functionality: It searches for the substring little within the string big,
	but only
up to len characters of big. If the substring is found,
	it returns a pointer to the first
occurrence of little in big. If little is not found, or if len is zero,
	it returns NULL.
Return: It returns a pointer to the first occurrence of little within the
first len characters of big, or NULL if little is not found.
*/
char				*ft_strnstr(const char *big, const char *little,
						size_t len);

/*
The	ft_strrchr(void) function locates the last occurrence of a character
in a string.
Functionality: It searches for the last occurrence of the character c
(converted to char) in the string s. The search starts from the end of
the string and proceeds backward.
Return: It returns a pointer to the last occurrence of the character c
in the string s, or NULL if c is not found.
*/
char				*ft_strrchr(const char *s, int c);

/*
The	ft_strtrim(void) function removes specified characters from both ends of
a string.
Functionality: It trims characters from the string s1 that are present in the
set string. The function removes all leading and trailing characters from s1
that are in set and returns a new string with the remaining content.
Return: It returns a newly allocated string with the trimmed result.
If no characters are trimmed, it returns a copy of s1.
*/
char				*ft_strtrim(char const *s1, char const *set);

/*
The	ft_substr(void) function extracts a substring from a string.
Functionality: It creates a new string that is a substring of s,
starting at the index start and extending up to len characters.
If the start index is beyond the end of the string, it returns an empty string.
If len is greater than the remaining length of the string from start,
it will extract the rest of the string.
Return: It returns a newly allocated string containing the extracted substring.
*/
char				*ft_substr(char const *s, unsigned int start, size_t len);

/*
The	ft_tolower(void) function converts an uppercase letter to its
lowercase equivalent.
Functionality: It checks if the character c is an uppercase letter
(from 'A' to 'Z'). If it is, the function converts it to the corresponding
lowercase letter.
If c is not an uppercase letter, it returns the character unchanged.
Return: It returns the lowercase equivalent of c if c is an uppercase letter;
otherwise, it returns c unchanged.
*/
int					ft_tolower(int c);

/*
The	ft_toupper(void) function converts a lowercase letter to its
uppercase equivalent.
Functionality: It checks if the character c is a lowercase letter
(from 'a' to 'z').
If it is, the function converts it to the corresponding uppercase letter.
If c is not a lowercase letter, it returns the character unchanged.
Return: It returns the uppercase equivalent of c if c is a lowercase letter;
otherwise, it returns c unchanged.
*/
int					ft_toupper(int c);

/*
Parameters
	lst: The address of a pointer to the first link of a list.
	new: The address of a pointer to the node to be
	added to the list.
Description
	Adds the node ’new’ at the end of the list.
*/
void				ft_lstadd_back(t_list **lst, t_list *new);

/*
Adds the node ’new’ at the beginning of the list.
lst:
	The address of a pointer to the first link of a list.
new:
	The address of a pointer to the node to be added to the list.
*/
void				ft_lstadd_front(t_list **lst, t_list *new);

/*
Parameters
	lst: The address of a pointer to a node.
	del: The address of the function used to delete
	the content of the node.
External functs.
	free
Description
	Deletes and frees the given node and every successor
	of that node, using the function ’del’ and free(3).
	Finally, the pointer to the list must be set to NULL.
*/
void				ft_lstclear(t_list **lst, void (*del)(void *));

/*
Parameters
	lst: The node to free.
	del: The address of the function used to delete the content.
External functs.
	free
Description
	Takes as a parameter a node and frees the memory of
	the node’s content using the function ’del’ given
	as a parameter and free the node. The memory of
	’next’ must not be freed.
*/
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/*
Parameters
	lst: The address of a pointer to a node.
	f: The address of the function used to iterate on the list.
Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node.
*/
void				ft_lstiter(t_list *lst, void (*f)(void *));

/*
Parameters
	lst: The beginning of the list.
Return value
	Last node of the list
Description
	Returns the last node of the list.
*/
t_list				*ft_lstlast(t_list *lst);

/*
Parameters
	lst:    The address of a pointer to a node.
	f:      The address of the function used to iterate on the list.
	del:    The address of the function used to delete the content of
			a node if needed.

Return value
	The new list.
	NULL if the allocation fails.

External functs.
	malloc, free

Description
	Iterates the list ’lst’ and applies the function
	’f’ on the content of each node. Creates a new
	list resulting of the successive applications of
	the function ’f’. The ’del’ function is used to
	delete the content of a node if needed.
*/
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

/*
Parameters
	content: The content to create the node with.
Return value
	The new node
External functs.
	malloc
Description
	Allocates (with malloc(3)) and returns a new node.
	The member variable ’content’ is initialized with
	the value of the parameter ’content’. The variable
	’next’ is initialized to NULL.
*/
t_list				*ft_lstnew(void *content);

/*
Parameters
	lst: The beginning of the list.
Return value
	The length of the list
Description
	Counts the number of nodes in a list.
	*/
int					ft_lstsize(t_list *lst);

/*
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

- defining a linked list node structure

content:
	The data contained in the node.
void *
	allows to store any kind of data.
next
	The address of the next node, or NULL if the next node is the last one.


struct
	- user defined data type that groups together variables
		(called members or fields) under one name


- typedef struct s_list
	- The typedef keyword allows the definition of a type alias.
	- typedef creates an alias t_list for the struct s_list
		- meaning you can use t_list as a shorthand for declaring
			variables of this structure type.
	- The structure is also called a node because it represents a
		single element in the linked list.

- Structure definition
  The structure s_list has two fields:
	- void *content
		- pointer to void. meaning points to any type of data (int, float, ...)
	- "struct s_list *next"
		- pointer to another s_list structure
- Alias t_list
	- with the alias, you can use t_list instead of struct s_list
	- t_list *node;   instead of   struct s_list *node;

*/

#endif