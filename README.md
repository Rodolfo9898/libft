*This project has been created as part of the 42 curriculum by rperez-t.*

# libft

## Description

libft is a static C library, `libft.a`, that re-implements part of the C
standard library and adds string, output and linked-list helpers. It is the
first project of the 42 common core: later projects may link it instead of
the standard functions. Its goal is to understand how these functions work
(memory, strings, edge cases) by writing them from scratch.

### Library contents

All prototypes are declared in `libft.h`. Only `malloc`, `free` and `write`
are used from outside the library.

**Libc functions** (same prototype and behaviour as the original, prefixed
with `ft_`):

| Category | Functions |
|---|---|
| Character tests | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Character conversion | `ft_toupper`, `ft_tolower` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Strings | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Conversion | `ft_atoi` |

**Additional functions** (not in the libc, or in a different form):

| Function | Purpose |
|---|---|
| `ft_substr` | New string from `s`, starting at `start`, at most `len` chars |
| `ft_strjoin` | New string `s1` followed by `s2` |
| `ft_strtrim` | New string with characters of `set` removed from both ends |
| `ft_split` | NULL-terminated array of the words of `s` separated by `c` |
| `ft_itoa` | String representation of an `int`, negatives included |
| `ft_strmapi` | New string where each char is `f(index, char)` |
| `ft_striteri` | Calls `f(index, &char)` on each char in place |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a char, string, line or number to a file descriptor |

**Linked list** functions, built on this node type:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
```

| Function | Purpose |
|---|---|
| `ft_lstnew` | Allocates a node holding `content` |
| `ft_lstadd_front` / `ft_lstadd_back` | Adds a node at the start / end of a list |
| `ft_lstsize` / `ft_lstlast` | Counts the nodes / returns the last node |
| `ft_lstdelone` / `ft_lstclear` | Frees one node / a whole list, using `del` on the content |
| `ft_lstiter` | Applies `f` to every node's content |
| `ft_lstmap` | New list with `f` applied to each content; frees everything on failure |

Functions that allocate return `NULL` when the allocation fails and free
anything they had already allocated.

### Technical choices

- **`ft_atoi` overflow:** the digits are accumulated in a `long` that is
  clamped to `LONG_MAX` / `LONG_MIN`, then cast to `int`. This gives the same
  result as glibc's `atoi`, which is `(int)strtol(str, NULL, 10)`.
- **`ft_calloc(0, n)` / `ft_calloc(n, 0)`:** allocates one byte, so the result
  is a unique pointer that can be passed to `free()`, as the subject requires.
  `nmemb * size` is checked for overflow before calling `malloc`.
- **NULL arguments:** the libc copies (`ft_strlen`, `ft_strdup`, ...) behave like
  the originals and do not check for `NULL`. The additional and list functions
  return `NULL` or do nothing when given a `NULL` string, list or callback.
- **`ft_lstmap`** keeps a pointer to the last `next` field, so building the new
  list is linear instead of walking it again for every node.

## Instructions

Requirements: `cc`, `make` and `ar`.

```sh
make        # builds libft.a at the root of the repository
make clean  # removes the object files
make fclean # removes the object files and libft.a
make re     # fclean, then make
```

Every file is compiled with `-Wall -Wextra -Werror`.

To use the library in a program:

```c
#include "libft.h"

int	main(void)
{
	char	*s;

	s = ft_itoa(-42);
	if (!s)
		return (1);
	ft_putendl_fd(s, 1);
	free(s);
	return (0);
}
```

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lft
```

## Resources

- The man pages of each original function (`man 3 strlcat`, `man 3 memmove`, ...).
- The 42 subject `libft.pdf` and the norm `en.norm.pdf`.

**Use of AI.** An AI assistant (Claude) reviewed the finished library against
the subject, pointed out failures and explained why they did not match the
subject, and proposed fixes.
