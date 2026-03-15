# 🖨️ ft_printf

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A custom implementation of the standard `printf` function written in C as part of the 42 Common Core.

---

# 🇬🇧 English

## 📖 About the Project

**ft_printf** is a project from the 42 Common Core that consists of recreating the behavior of the standard C function `printf()`.

The goal is to understand how formatted output works internally by implementing a function capable of parsing a format string and printing the corresponding arguments using **variadic functions**.

This project focuses on:

* variadic arguments (`stdarg.h`)
* format string parsing
* number conversion
* hexadecimal representation
* pointer printing
* low-level output using `write()`

---

## ⚙️ Compilation

To compile the project:

```bash
make
```

This will generate the static library:

```
libftprintf.a
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
git clone https://github.com/yourusername/ft_printf.git
cd ft_printf
```

2. Compile the library

```bash
make
```

3. Include the header in your program

```c
#include "ft_printf.h"
```

4. Compile your program with the library

```bash
gcc main.c libftprintf.a
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s\n", "world");
	ft_printf("Number: %d\n", 42);
	ft_printf("Hex: %x\n", 255);
	return (0);
}
```

---

## 🔧 Supported Format Specifiers

| Specifier | Description              |
| --------- | ------------------------ |
| `%c`      | Character                |
| `%s`      | String                   |
| `%p`      | Pointer address          |
| `%d`      | Signed decimal integer   |
| `%i`      | Integer                  |
| `%u`      | Unsigned decimal integer |
| `%x`      | Hexadecimal (lowercase)  |
| `%X`      | Hexadecimal (uppercase)  |
| `%%`      | Percent sign             |

---

## 🧠 Implemented Functions

| Function             | Description                 |
| -------------------- | --------------------------- |
| `ft_printf`          | Main printf function        |
| `ft_print_char`      | Prints a character          |
| `ft_print_str`       | Prints a string             |
| `ft_print_pointer`   | Prints a memory address     |
| `ft_print_int`       | Prints a signed integer     |
| `ft_print_intunsign` | Prints an unsigned integer  |
| `ft_print_hexa`      | Prints a hexadecimal number |

---

## 🎯 Learning Outcomes

Through this project I learned:

* how **variadic functions** work (`va_list`, `va_start`, `va_arg`, `va_end`)
* how to parse a **format string**
* how to convert integers to different bases
* hexadecimal conversion
* how pointers are represented in memory
* using **low-level output (`write`)**
* writing modular and reusable C functions

---

## 📂 Project Structure

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_char.c
├── ft_print_str.c
├── ft_print_pointer.c
├── ft_print_int.c
├── ft_print_intunsign.c
├── ft_print_hexa.c
└── other helper functions
```

---

# 🇮🇹 Italiano

## 📖 Descrizione del progetto

**ft_printf** è un progetto del Common Core della 42 che consiste nel ricreare il comportamento della funzione standard di C `printf()`.

L'obiettivo è capire come funziona internamente la stampa formattata implementando una funzione capace di analizzare una stringa di formato e stampare gli argomenti corrispondenti utilizzando **funzioni variadiche**.

Il progetto si concentra su:

* gestione degli **argomenti variadici (`stdarg`)**
* parsing della **format string**
* conversione dei numeri
* rappresentazione esadecimale
* stampa dei puntatori
* output a basso livello con `write()`

---

## ⚙️ Compilazione

Per compilare il progetto:

```bash
make
```

Questo genererà la libreria statica:

```
libftprintf.a
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
git clone https://github.com/tuousername/ft_printf.git
cd ft_printf
```

2. Compilare la libreria

```bash
make
```

3. Includere l'header nel programma

```c
#include "ft_printf.h"
```

4. Compilare insieme al proprio programma

```bash
gcc main.c libftprintf.a
```

Esempio:

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s\n", "world");
	ft_printf("Numero: %d\n", 42);
	ft_printf("Hex: %x\n", 255);
	return (0);
}
```

---

## 🔧 Specificatori supportati

| Specificatore | Descrizione             |
| ------------- | ----------------------- |
| `%c`          | Carattere               |
| `%s`          | Stringa                 |
| `%p`          | Indirizzo di memoria    |
| `%d`          | Intero con segno        |
| `%i`          | Intero                  |
| `%u`          | Intero senza segno      |
| `%x`          | Esadecimale (minuscolo) |
| `%X`          | Esadecimale (maiuscolo) |
| `%%`          | Simbolo percentuale     |

---

## 🎯 Cosa ho imparato

Con questo progetto ho imparato:

* come funzionano le **funzioni variadiche (`va_list`)**
* come analizzare una **format string**
* conversione dei numeri in basi diverse
* conversione in **esadecimale**
* rappresentazione dei **puntatori**
* utilizzo dell'output a basso livello con `write`
* scrivere codice modulare e riutilizzabile

---

## 📂 Struttura del progetto

```
.
├── Makefile
├── ft_printf.h
├── ft_printf.c
├── ft_print_char.c
├── ft_print_str.c
├── ft_print_pointer.c
├── ft_print_int.c
├── ft_print_intunsign.c
├── ft_print_hexa.c
└── funzioni di supporto
```
