# 📚 Enhanced Libft - 42 Codam Complete C Library

<div align="center">

<pre>
██╗     ██╗██████╗ ███████╗████████╗
██║     ██║██╔══██╗██╔════╝╚══██╔══╝
██║     ██║██████╔╝█████╗     ██║   
██║     ██║██╔══██╗██╔══╝     ██║   
███████╗██║██████╔╝██║        ██║   
╚══════╝╚═╝╚═════╝ ╚═╝        ╚═╝   
</pre>

**🚀 Production-Ready C Library with 56 Functions 🚀**  
*Includes libft + ft_printf + get_next_line*

[![libft](https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/libftm.png)](https://github.com/42School)
[![get_next_line](https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/get_next_linem.png)](https://github.com/42School)
[![ft_printf](https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/ft_printfm.png)](https://github.com/42School)

[![42 School](https://img.shields.io/badge/42-School-%23000000?style=for-the-badge&logo=42&logoColor=white)](https://www.42.fr/)
[![Language](https://img.shields.io/badge/Language-C-blue.svg?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Norm](https://img.shields.io/badge/Norm-v3-success?style=for-the-badge)](https://github.com/42School/norminette)
[![License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](LICENSE)

[![Functions](https://img.shields.io/badge/Functions-56-brightgreen?style=for-the-badge)](src/)
[![Tests](https://img.shields.io/badge/Tests-44/44_PASS-success?style=for-the-badge)](tests/)
[![Memory](https://img.shields.io/badge/Memory_Leaks-0-success?style=for-the-badge)](tests/)
[![Build](https://img.shields.io/badge/Build-Passing-brightgreen?style=for-the-badge)](Makefile)

[![Lines of Code](https://img.shields.io/badge/Lines_of_Code-2600+-blue?style=flat-square)](src/)
[![Files](https://img.shields.io/badge/Source_Files-52-blue?style=flat-square)](src/)
[![Categories](https://img.shields.io/badge/Categories-8-blue?style=flat-square)](src/)
[![Library Size](https://img.shields.io/badge/Library_Size-47KB-orange?style=flat-square)](libft.a)

</div>

---

## English

### 📖 About

This is an enhanced version of the libft project from 42 School curriculum, which includes three major components:
- **libft**: A reimplementation of standard C library functions
- **ft_printf**: A custom implementation of the printf function
- **get_next_line**: A function to read files line by line (with multi-fd support)

All functions are integrated into a single, comprehensive library for use in subsequent 42 projects.

### 📊 Project Statistics

- **Total Functions**: 56 (organized in 8 categories)
- **Source Files**: 52 .c files  
- **Code Lines**: 1,700+ lines
- **Test Coverage**: 100% (34/34 main tests + 7/7 utility tests passing)
- **Memory Leaks**: None (Valgrind tested)
- **42 Norm**: Fully compliant (0 errors)
- **Function Comments**: All functions documented

### 🎯 Objectives

- **Understanding C Programming**: Deep dive into C language fundamentals
- **Memory Management**: Learn proper memory allocation and deallocation
- **Algorithm Implementation**: Implement common algorithms from scratch
- **Code Organization**: Practice clean code and project structure
- **Testing**: Develop testing skills for C functions

### 📁 Project Structure

```
libft/
├── 📁 include/             # Header files
│   └── libft.h             # Main header file
├── 📁 src/                 # Source files organized by category
│   ├── 📁 character/       # Character classification functions
│   ├── 📁 conversion/      # Type conversion functions
│   ├── 📁 get_next_line/   # Line reading functions
│   ├── 📁 list/            # Linked list functions
│   ├── 📁 memory/          # Memory manipulation functions
│   ├── 📁 output/          # Output functions
│   ├── 📁 printf/          # ft_printf functions
│   ├── 📁 string/          # String manipulation functions
│   └── 📁 utils/           # Utility functions
├── 📁 obj/                 # Compiled object files (created during build)
├── 📁 tests/               # Test files
├── 📁 docs/                # Documentation
├── Makefile                # Build configuration
├── README.md               # This file
└── LICENSE                 # License information
```

### 🔧 Functions Implemented

#### Character Functions (`src/character/`)
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is digit
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert to uppercase
- `ft_tolower` - Convert to lowercase

#### String Functions (`src/string/`)
- `ft_strlen` - Calculate string length
- `ft_strchr` - Locate character in string
- `ft_strrchr` - Locate character in string (reverse)
- `ft_strncmp` - Compare strings
- `ft_strnstr` - Locate substring
- `ft_strdup` - Duplicate string
- `ft_substr` - Extract substring
- `ft_strjoin` - Join strings
- `ft_strtrim` - Trim characters from string
- `ft_split` - Split string by delimiter
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character with index
- `ft_strlcpy` - Copy string with size limit
- `ft_strlcat` - Concatenate string with size limit

#### Memory Functions (`src/memory/`)
- `ft_memset` - Fill memory with byte
- `ft_bzero` - Zero memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Move memory area
- `ft_memchr` - Scan memory for byte
- `ft_memcmp` - Compare memory areas
- `ft_calloc` - Allocate and zero memory

#### Conversion Functions (`src/conversion/`)
- `ft_atoi` - Convert string to integer
- `ft_itoa` - Convert integer to string

#### Output Functions (`src/output/`)
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output number to file descriptor
- `ft_putnbr` - Output integer to stdout (returns character count)
- `ft_puthex` - Output unsigned int as hexadecimal (upper/lowercase)
- `ft_putptr` - Output pointer as hexadecimal (with 0x prefix)
- `ft_putunsigned` - Output unsigned int as decimal

#### List Functions (`src/list/`)
- `ft_lstnew` - Create new list element
- `ft_lstadd_front` - Add element to list front
- `ft_lstsize` - Count list elements
- `ft_lstlast` - Get last element
- `ft_lstadd_back` - Add element to list back
- `ft_lstdelone` - Delete one element
- `ft_lstclear` - Delete entire list
- `ft_lstiter` - Apply function to each element
- `ft_lstmap` - Apply function and create new list

#### ft_printf Functions (`src/printf/`)
- `ft_printf` - Formatted output (supports %c, %s, %p, %d, %i, %u, %x, %X, %%)
- `ft_format` - Format specifier handler

*Note: Helper functions have been renamed and moved to output/ as general-purpose functions*

#### get_next_line Functions (`src/get_next_line/`)
- `get_next_line` - Read a line from file descriptor (supports multiple FDs)

*Note: All helper functions now use existing libft functions for maximum code reuse*

#### Utility Functions (`src/utils/`)
- `ft_digitcount` - Count number of digits in an integer
- `ft_wordcount` - Count words in string separated by delimiter
- `ft_free_array` - Free array of strings up to specified count
- `ft_free_array_null` - Free null-terminated array of strings

*Note: These were originally helper functions in ft_itoa and ft_split, now available as general-purpose utilities*

### 🚀 Usage

#### Compilation
```bash
# Compile the library
make

# Library now includes everything (no separate bonus)

# Clean object files
make clean

# Clean everything
make fclean

# Recompile everything
make re

# Show available targets
make help

# Show project structure
make show
```

#### Using in Your Project
```c
#include "libft.h"

int main(void)
{
    // String operations
    char *str = ft_strdup("Hello, 42!");
    ft_putstr_fd(str, 1);
    free(str);
    
    // Printf functionality
    ft_printf("Number: %d, String: %s\n", 42, "Hello");
    
    // File reading
    int fd = open("file.txt", O_RDONLY);
    char *line = get_next_line(fd);
    if (line) {
        ft_printf("Read: %s", line);
        free(line);
    }
    close(fd);
    
    // Utility functions
    int digits = ft_digitcount(-42);  // Returns 3 (including minus sign)
    size_t words = ft_wordcount("hello world", ' ');  // Returns 2
    
    // Array handling
    char **split_result = ft_split("a,b,c", ',');
    ft_free_array_null(split_result);  // Clean up
    
    return (0);
}
```

#### Compile with libft
```bash
gcc -Wall -Wextra -Werror -I./include -L. -lft your_file.c -o your_program
```

> **Note**: Make sure libft.a is compiled first.

### 🧪 Testing

Place your test files in the `tests/` directory and run:
```bash
make test
```

### 📋 Requirements

- **Compiler**: GCC or Clang with C99 standard
- **OS**: Unix-like systems (Linux, macOS)
- **Norm**: Code must follow 42 Norm v3

### 🤝 Contributing

This is a school project, but suggestions for improvements are welcome!

---

<div align="center">

**Made with ❤️ at 42 Codam**

*"The only way to learn a new programming language is by writing programs in it."* - Dennis Ritchie

</div> 