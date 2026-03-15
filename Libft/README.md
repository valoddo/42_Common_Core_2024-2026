# 📚 Libft

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A custom implementation of a standard C library created as part of the 42 Common Core.

---

# 🇬🇧 English

## 📖 About the Project

**Libft** is the first project of the 42 Common Core.
The objective is to recreate a personal C library by reimplementing several functions from the standard C library, along with additional utility functions.

This library will be reused in many future projects, making it an essential foundation for understanding **memory management, strings, and low-level programming in C**.

---

## ⚙️ Compilation

To compile the library:

```bash
make
```

This will generate:

```
libft.a
```

To remove object files:

```bash
make clean
```

To remove all generated files:

```bash
make fclean
```

To recompile everything:

```bash
make re
```

---

## 🚀 Usage

1. Clone the repository

```bash
git clone https://github.com/yourusername/libft.git
cd libft
```

2. Compile the library

```bash
make
```

3. Include the header in your project

```c
#include "libft.h"
```

4. Compile with your program

```bash
gcc main.c libft.a
```

---

## 🧠 Functions Implemented

### Character checks

| Function   |
| ---------- |
| ft_isalpha |
| ft_isdigit |
| ft_isalnum |
| ft_isascii |
| ft_isprint |

---

### String functions

| Function    |
| ----------- |
| ft_strlen   |
| ft_strdup   |
| ft_strchr   |
| ft_strrchr  |
| ft_strncmp  |
| ft_strnstr  |
| ft_strjoin  |
| ft_strtrim  |
| ft_split    |
| ft_substr   |
| ft_strlcpy  |
| ft_strlcat  |
| ft_striteri |
| ft_strmapi  |

---

### Memory functions

| Function   |
| ---------- |
| ft_memset  |
| ft_bzero   |
| ft_memcpy  |
| ft_memmove |
| ft_memchr  |
| ft_memcmp  |
| ft_calloc  |

---

### Conversion

| Function |
| -------- |
| ft_atoi  |
| ft_itoa  |

---

### File descriptor output

| Function      |
| ------------- |
| ft_putchar_fd |
| ft_putstr_fd  |
| ft_putendl_fd |
| ft_putnbr_fd  |

---

### Character conversion

| Function   |
| ---------- |
| ft_tolower |
| ft_toupper |

---

## 🎯 Learning Outcomes

Through this project I learned:

* how standard C library functions work internally
* memory allocation and management
* pointer manipulation
* string processing in C
* writing reusable and modular code
* creating and managing static libraries
* using Makefiles for automated compilation

---

## 📂 Project Structure

```
.
├── Makefile
├── libft.h
├── ft_*.c
└── en.subject.pdf
```

---

# 🇮🇹 Italiano

## 📖 Descrizione del progetto

**Libft** è il primo progetto del Common Core della 42.
L'obiettivo è ricreare una libreria personale in C reimplementando diverse funzioni della libreria standard, insieme ad alcune funzioni di utilità.

Questa libreria verrà riutilizzata in molti progetti successivi ed è quindi una base fondamentale per comprendere **gestione della memoria, stringhe e programmazione a basso livello in C**.

---

## ⚙️ Compilazione

Per compilare la libreria:

```bash
make
```

Questo genererà:

```
libft.a
```

Per rimuovere gli object file:

```bash
make clean
```

Per rimuovere tutti i file generati:

```bash
make fclean
```

Per ricompilare tutto:

```bash
make re
```

---

## 🚀 Utilizzo

1. Clonare il repository

```bash
git clone https://github.com/tuousername/libft.git
cd libft
```

2. Compilare la libreria

```bash
make
```

3. Includere l'header nel progetto

```c
#include "libft.h"
```

4. Compilare insieme al proprio programma

```bash
gcc main.c libft.a
```

---

## 🧠 Funzioni implementate

### Controllo caratteri

| Funzioni   |
| ---------- |
| ft_isalpha |
| ft_isdigit |
| ft_isalnum |
| ft_isascii |
| ft_isprint |

---

### Funzioni sulle stringhe

| Funzioni    |
| ----------- |
| ft_strlen   |
| ft_strdup   |
| ft_strchr   |
| ft_strrchr  |
| ft_strncmp  |
| ft_strnstr  |
| ft_strjoin  |
| ft_strtrim  |
| ft_split    |
| ft_substr   |
| ft_strlcpy  |
| ft_strlcat  |
| ft_striteri |
| ft_strmapi  |

---

### Gestione memoria

| Funzioni   |
| ---------- |
| ft_memset  |
| ft_bzero   |
| ft_memcpy  |
| ft_memmove |
| ft_memchr  |
| ft_memcmp  |
| ft_calloc  |

---

### Conversioni

| Funzioni |
| -------- |
| ft_atoi  |
| ft_itoa  |

---

### Output su file descriptor

| Funzioni      |
| ------------- |
| ft_putchar_fd |
| ft_putstr_fd  |
| ft_putendl_fd |
| ft_putnbr_fd  |

---

### Conversione caratteri

| Funzioni   |
| ---------- |
| ft_tolower |
| ft_toupper |

---

## 🎯 Cosa ho imparato

Con questo progetto ho imparato:

* come funzionano internamente le funzioni della libreria standard
* gestione della memoria in C
* manipolazione dei puntatori
* gestione delle stringhe
* scrivere codice modulare e riutilizzabile
* creare librerie statiche
* usare i Makefile per automatizzare la compilazione

---

## 📂 Struttura del progetto

```
.
├── Makefile
├── libft.h
├── ft_*.c
└── en.subject.pdf
```
