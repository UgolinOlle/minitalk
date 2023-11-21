# Libft - 42 School

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)

Welcome to the Libft repository. This project is part of the curriculum at 42 School and involves recreating several standard C library functions as well as other useful utilities.

## Table of Contents

- [Introduction](#introduction)
- [Installation](#installation)
- [Usage](#usage)
- [Functions](#functions)
  - [srcs/file](#srcsfile)
  - [srcs/mem](#srcsmem)
  - [srcs/misc](#srcsmisc)
  - [srcs/nbr](#srcsnbr)
  - [srcs/str](#srcsstr)
- [Contribution](#contribution)
- [License](#license)

## Introduction

The Libft library is a fundamental project at 42 School aimed at strengthening your C programming skills. It contains custom implementations of many standard C library functions, as well as other useful functions that you can use in your projects.

## Installation

To use the Libft library, follow these steps:

1. Clone this repository to your computer.

```bash
git clone https://github.com/yourusername/libft.git
```

2. Compile the library by running the make command at the root of the project.

```bash
make
```

3. You will get a `libft.a` file that you can link to your projects.

## Usage

To use the Libft library in your projects, you need to include the libft.h header file in your source files and link the libft.a library during compilation.

Example compilation:

```bash
gcc -o my_program my_program.c -L. -lft
```

## Functions

The Libft library contains many useful functions organized into directories. Here are the directories and their respective functions:

```
- srcs/file
  - ft_putchar_fd.c
  - ft_putendl_fd.c
  - ft_putnbr_fd.c
  - ft_putstr_fd.c
- srcs/mem
  - ft_bzero.c
  - ft_calloc.c
  - ft_memchr.c
  - ft_memcmp.c
  - ft_memcpy.c
  - ft_memmove.c
  - ft_memset.c
- srcs/misc
  - ft_isalnum.c
  - ft_isalpha.c
  - ft_isascii.c
  - ft_isdigit.c
  - ft_isprint.c
- srcs/nbr
  - ft_atoi.c
  - ft_itoa.c
- srcs/str
  - ft_split.c
  - ft_strchr.c
  - ft_strdup.c
  - ft_striteri.c
  - ft_strjoin.c
  - ft_strlcat.c
  - ft_strlcpy.c
  - ft_strlen.c
  - ft_strmapi.c
  - ft_strncmp.c
  - ft_strnstr.c
  - ft_strrchr.c
  - ft_strtrim.c
  - ft_substr.c
  - ft_tolower.c
  - ft_toupper.c
```

Feel free to explore the library to discover all available functions.

## Contribution

Contributions are welcome! If you'd like to contribute to this project, please follow these steps:

1. Fork this repository.
2. Create a branch for your feature or fix.
3. Make your changes.
4. Submit a pull request to the master branch of this repository.

## License

This project is licensed under the MIT License - see the LICENSE file for details.
