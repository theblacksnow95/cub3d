# Libft
## 📋 Project Overview

libft is a foundational project at Ecole 42 designed to build a custom C library by reimplementing a selection of standard libc functions, along with additional utility functions. This project lays the groundwork for other projects by offering a personalized implementation of essential functions for string manipulation, memory handling, linked lists, and more.

## 📁 Project Structure

The project is divided into sections, each covering a different functionality:

1. **Standard C Library Functions:** Reimplementation of basic libc functions, such as `memset`, `strdup`, `atoi`, `calloc`, and more.

``` c
// Example function: ft_strlen

size_t ft_strlen(const char *s) {
    size_t len = 0;
    while (s[len] != '\0') {
        len++;
    }
    return len;
}
```
2. **Additional Utility Functions:** Functions that extend the basic ones, like `ft_substr`, `ft_strjoin`, `ft_split`, etc.

``` c
// Example function: ft_strjoin

char *ft_strjoin(char const *s1, char const *s2) {
    size_t len1 = ft_strlen(s1);
    size_t len2 = ft_strlen(s2);
    char *joined = malloc(len1 + len2 + 1);
    if (!joined) return NULL;
    ft_memcpy(joined, s1, len1);
    ft_memcpy(joined + len1, s2, len2 + 1);
    return joined;
}
```
3. **Linked List Functions:** Implementations for handling linked lists, such as `ft_lstnew`, `ft_lstadd_front`, `ft_lstmap`, and others.

```c
// Example function: ft_lstnew

t_list *ft_lstnew(void *content) {
    t_list *new_node = (t_list *)malloc(sizeof(t_list));
    if (!new_node) return NULL;
    new_node->content = content;
    new_node->next = NULL;
    return new_node;
}
```
4. **Optional Functions (if required):** Advanced utilities that further expand the library’s capabilities, possibly including mathematical functions or additional string utilities.

## 🚀 Installation and Usage
To compile the library and generate the `libft.a` file:
``` c
make
```
To use libft in a project, include the header file `libft.h` and link `libft.a` in your project's `Makefile`.

