# 📋 Libft Functions Reference

## 📚 Function Categories

### 🔤 Character Functions (`src/character/`)

Functions for character classification and transformation.

| Function | Description | Prototype | Return Value |
|----------|-------------|-----------|--------------|
| `ft_isalpha` | Checks if character is alphabetic | `int ft_isalpha(int c)` | Non-zero if true, 0 if false |
| `ft_isdigit` | Checks if character is a digit | `int ft_isdigit(int c)` | Non-zero if true, 0 if false |
| `ft_isalnum` | Checks if character is alphanumeric | `int ft_isalnum(int c)` | Non-zero if true, 0 if false |
| `ft_isascii` | Checks if character is ASCII | `int ft_isascii(int c)` | Non-zero if true, 0 if false |
| `ft_isprint` | Checks if character is printable | `int ft_isprint(int c)` | Non-zero if true, 0 if false |
| `ft_toupper` | Converts to uppercase | `int ft_toupper(int c)` | Uppercase character or unchanged |
| `ft_tolower` | Converts to lowercase | `int ft_tolower(int c)` | Lowercase character or unchanged |

### 🧵 String Functions (`src/string/`)

Functions for string manipulation and analysis.

| Function | Description | Prototype | Return Value |
|----------|-------------|-----------|--------------|
| `ft_strlen` | Calculates string length | `size_t ft_strlen(const char *s)` | Length of string |
| `ft_strchr` | Locates first occurrence of char | `char *ft_strchr(const char *s, int c)` | Pointer to char or NULL |
| `ft_strrchr` | Locates last occurrence of char | `char *ft_strrchr(const char *s, int c)` | Pointer to char or NULL |
| `ft_strncmp` | Compares strings up to n chars | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Difference value |
| `ft_strnstr` | Locates substring | `char *ft_strnstr(const char *haystack, const char *needle, size_t len)` | Pointer to substring or NULL |
| `ft_strdup` | Duplicates string | `char *ft_strdup(const char *s1)` | Pointer to new string or NULL |
| `ft_substr` | Extracts substring | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Pointer to substring or NULL |
| `ft_strjoin` | Joins two strings | `char *ft_strjoin(char const *s1, char const *s2)` | Pointer to new string or NULL |
| `ft_strtrim` | Trims characters from string | `char *ft_strtrim(char const *s1, char const *set)` | Pointer to trimmed string or NULL |
| `ft_split` | Splits string by delimiter | `char **ft_split(char const *s, char c)` | Array of strings or NULL |
| `ft_strmapi` | Applies function to each char | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Pointer to new string or NULL |
| `ft_striteri` | Applies function to each char with index | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | None (void) |
| `ft_strlcpy` | Copies string with size limit | `size_t ft_strlcpy(char *dst, const char *src, size_t dstsize)` | Length of source |
| `ft_strlcat` | Concatenates with size limit | `size_t ft_strlcat(char *dst, const char *src, size_t dstsize)` | Total length attempted |

### 🧠 Memory Functions (`src/memory/`)

Functions for memory manipulation and management.

| Function | Description | Prototype | Return Value |
|----------|-------------|-----------|--------------|
| `ft_memset` | Fills memory with byte | `void *ft_memset(void *b, int c, size_t len)` | Pointer to memory area |
| `ft_bzero` | Zeros memory | `void ft_bzero(void *s, size_t n)` | None (void) |
| `ft_memcpy` | Copies memory area | `void *ft_memcpy(void *dst, const void *src, size_t n)` | Pointer to destination |
| `ft_memmove` | Moves memory area safely | `void *ft_memmove(void *dst, const void *src, size_t len)` | Pointer to destination |
| `ft_memchr` | Scans memory for byte | `void *ft_memchr(const void *s, int c, size_t n)` | Pointer to byte or NULL |
| `ft_memcmp` | Compares memory areas | `int ft_memcmp(const void *s1, const void *s2, size_t n)` | Difference value |
| `ft_calloc` | Allocates and zeros memory | `void *ft_calloc(size_t count, size_t size)` | Pointer to allocated memory or NULL |

### 🔄 Conversion Functions (`src/conversion/`)

Functions for type conversion.

| Function | Description | Prototype | Return Value |
|----------|-------------|-----------|--------------|
| `ft_atoi` | Converts string to integer | `int ft_atoi(const char *str)` | Integer value |
| `ft_itoa` | Converts integer to string | `char *ft_itoa(int n)` | Pointer to string or NULL |

### 📤 Output Functions (`src/output/`)

Functions for output operations.

| Function | Description | Prototype | Return Value |
|----------|-------------|-----------|--------------|
| `ft_putchar_fd` | Outputs char to file descriptor | `void ft_putchar_fd(char c, int fd)` | None (void) |
| `ft_putstr_fd` | Outputs string to file descriptor | `void ft_putstr_fd(char *s, int fd)` | None (void) |
| `ft_putendl_fd` | Outputs string + newline to fd | `void ft_putendl_fd(char *s, int fd)` | None (void) |
| `ft_putnbr_fd` | Outputs number to file descriptor | `void ft_putnbr_fd(int n, int fd)` | None (void) |

### 📋 List Functions (`src/list/`) - Bonus

Functions for linked list manipulation.

| Function | Description | Prototype | Return Value |
|----------|-------------|-----------|--------------|
| `ft_lstnew` | Creates new list element | `t_list *ft_lstnew(void *content)` | Pointer to new element or NULL |
| `ft_lstadd_front` | Adds element to list front | `void ft_lstadd_front(t_list **lst, t_list *new)` | None (void) |
| `ft_lstsize` | Counts list elements | `int ft_lstsize(t_list *lst)` | Number of elements |
| `ft_lstlast` | Gets last element | `t_list *ft_lstlast(t_list *lst)` | Pointer to last element or NULL |
| `ft_lstadd_back` | Adds element to list back | `void ft_lstadd_back(t_list **lst, t_list *new)` | None (void) |
| `ft_lstdelone` | Deletes one element | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | None (void) |
| `ft_lstclear` | Deletes entire list | `void ft_lstclear(t_list **lst, void (*del)(void *))` | None (void) |
| `ft_lstiter` | Applies function to each element | `void ft_lstiter(t_list *lst, void (*f)(void *))` | None (void) |
| `ft_lstmap` | Applies function and creates new list | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Pointer to new list or NULL |

## 📝 Usage Examples

### String Manipulation
```c
#include "libft.h"

int main(void)
{
    char *str = "Hello World";
    char *substr = ft_substr(str, 6, 5); // "World"
    char *joined = ft_strjoin("42 ", substr); // "42 World"
    
    ft_putstr_fd(joined, 1);
    ft_putchar_fd('\n', 1);
    
    free(substr);
    free(joined);
    return (0);
}
```

### Memory Management
```c
#include "libft.h"

int main(void)
{
    // Allocate and zero memory for 10 integers
    int *array = (int *)ft_calloc(10, sizeof(int));
    
    // Fill with a specific value
    ft_memset(array, 0, 10 * sizeof(int));
    
    // Use the array...
    
    free(array);
    return (0);
}
```

### Linked Lists
```c
#include "libft.h"

int main(void)
{
    t_list *list = NULL;
    
    // Create and add elements
    ft_lstadd_back(&list, ft_lstnew("First"));
    ft_lstadd_back(&list, ft_lstnew("Second"));
    ft_lstadd_back(&list, ft_lstnew("Third"));
    
    // Print list size
    printf("List size: %d\n", ft_lstsize(list));
    
    // Clean up
    ft_lstclear(&list, free);
    return (0);
}
```

## ⚠️ Important Notes

1. **Memory Management**: Always free memory allocated by functions like `ft_strdup`, `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, and `ft_itoa`.

2. **NULL Protection**: Most functions handle NULL parameters gracefully, but always check documentation for specific behavior.

3. **Error Handling**: Functions that allocate memory return NULL on failure.

4. **42 Norm Compliance**: All functions follow 42 School coding standards.

5. **Performance**: These implementations prioritize correctness and readability over extreme optimization. 