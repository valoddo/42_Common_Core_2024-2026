# 📄 get_next_line

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A C function that reads a file descriptor line by line, implemented as part of the 42 Common Core.

---

# 🇬🇧 English

## 📖 About the Project

**get_next_line** is a project from the 42 Common Core whose objective is to implement a function capable of reading a file descriptor **one line at a time**.

Each call to the function returns the **next line from the file**, including the newline character (`\n`) if present.

This project helps understand:

* file descriptors
* static variables
* memory management
* buffered reading with `read()`
* handling dynamic strings

---

## ⚙️ Function Prototype

```c
char *get_next_line(int fd);
```

### Parameters

| Parameter | Description                  |
| --------- | ---------------------------- |
| `fd`      | File descriptor to read from |

### Return Value

| Return | Meaning                          |
| ------ | -------------------------------- |
| Line   | The next line read from the file |
| `NULL` | End of file or error             |

---

## ⚙️ Compilation

To compile the project:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` defines how many bytes are read at each `read()` call.

---

## 🚀 Usage

Example:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
```

Example output:

```
First line
Second line
Third line
```

---

## 🔧 How It Works

The function works in several steps:

1. **Read from the file descriptor**
2. Store the data inside a **static buffer**
3. Continue reading until a **newline (`\n`) is found**
4. Extract the current line
5. Keep the remaining content for the next call

Key concepts used:

* `read()`
* dynamic memory allocation (`malloc`)
* string manipulation
* persistent buffers

---

## ⭐ Bonus Part

The bonus version extends the function to support **multiple file descriptors at the same time**.

Instead of using a single static buffer, it uses something like:

```c
static char *buffer[OPEN_MAX];
```

This allows reading from different files simultaneously without mixing their contents.

Example:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

printf("%s", get_next_line(fd1));
printf("%s", get_next_line(fd2));
```

Each file descriptor maintains its own buffer.

---

## 🧠 Concepts Learned

Through this project I learned:

* how **file descriptors** work
* how to use the **read() system call**
* managing **static variables**
* handling **dynamic memory**
* reading files efficiently using buffers
* handling edge cases (EOF, empty files, errors)

---

## 📂 Project Structure

```
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── bonus/
    ├── get_next_line_bonus.c
    ├── get_next_line_utils_bonus.c
    └── get_next_line_bonus.h
```

---

# 🇮🇹 Italiano

## 📖 Descrizione del progetto

**get_next_line** è un progetto del Common Core della 42 che consiste nell'implementare una funzione capace di leggere da un file descriptor **una linea alla volta**.

Ogni chiamata alla funzione restituisce **la linea successiva del file**, incluso il carattere newline (`\n`) se presente.

Questo progetto permette di comprendere meglio:

* i **file descriptor**
* le **variabili statiche**
* la gestione della memoria
* la lettura tramite **buffer**
* la manipolazione delle stringhe dinamiche

---

## ⚙️ Prototipo della funzione

```c
char *get_next_line(int fd);
```

### Parametri

| Parametro | Descrizione                    |
| --------- | ------------------------------ |
| `fd`      | File descriptor da cui leggere |

### Valore di ritorno

| Ritorno | Significato                |
| ------- | -------------------------- |
| Linea   | La prossima linea del file |
| `NULL`  | Fine del file o errore     |

---

## ⚙️ Compilazione

Per compilare il progetto:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

`BUFFER_SIZE` definisce quanti byte vengono letti ad ogni chiamata a `read()`.

---

## 🚀 Utilizzo

Esempio:

```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;

	fd = open("file.txt", O_RDONLY);
	line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}

	close(fd);
	return (0);
}
```

Output di esempio:

```
Prima linea
Seconda linea
Terza linea
```

---

## 🔧 Come funziona

La funzione lavora in diversi passaggi:

1. Legge dal file descriptor tramite `read()`
2. Salva i dati in un **buffer statico**
3. Continua a leggere finché non trova un **newline (`\n`)**
4. Estrae la linea corrente
5. Conserva il resto del buffer per la chiamata successiva

Concetti chiave utilizzati:

* `read()`
* allocazione dinamica (`malloc`)
* manipolazione delle stringhe
* gestione persistente del buffer

---

## ⭐ Parte Bonus

La parte bonus permette di gestire **più file descriptor contemporaneamente**.

Invece di usare un solo buffer statico, si utilizza qualcosa come:

```c
static char *buffer[OPEN_MAX];
```

In questo modo ogni file mantiene il proprio buffer.

Esempio:

```c
int fd1 = open("file1.txt", O_RDONLY);
int fd2 = open("file2.txt", O_RDONLY);

printf("%s", get_next_line(fd1));
printf("%s", get_next_line(fd2));
```

---

## 🎯 Cosa ho imparato

Con questo progetto ho imparato:

* come funzionano i **file descriptor**
* utilizzare la system call **read()**
* gestire **variabili statiche**
* gestire **memoria dinamica**
* leggere file tramite buffer
* gestire casi limite (EOF, file vuoti, errori)

---

## 📂 Struttura del progetto

```
.
├── get_next_line.c
├── get_next_line_utils.c
├── get_next_line.h
└── bonus/
    ├── get_next_line_bonus.c
    ├── get_next_line_utils_bonus.c
    └── get_next_line_bonus.h
```
