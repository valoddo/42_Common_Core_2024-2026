# 📄 Pipex

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A minimal Unix pipe simulator implemented in C. This project is part of the 42 Common Core curriculum and focuses on **processes, pipes, and redirections**.

---
# 🇬🇧 English

## 📖 About the Project

**Pipex** simulates the behavior of the Unix shell when using **pipes** between commands.  
The program executes two commands in a pipeline, redirecting input and output files:

- Reads input from a file
- Executes the first command
- Pipes its output to the second command
- Writes the final output to another file

This project demonstrates:

- Process creation using `fork`
- Command execution using `execve`
- Pipe communication with `pipe()`
- File redirection using `open`, `dup2`, `close`
- Memory management in C

---

## ⚙️ Program Usage

```bash
./pipex infile "cmd1" "cmd2" outfile
```

# Parameters
| Parameter | Description                                              |
|-----------|----------------------------------------------------------|
| infile    | Path to the input file                                   |
| cmd1      | First command to execute (with arguments)                |
| cmd2      | Second command to execute (with arguments)               |
| outfile   | Path to the output file (will be created or overwritten) |

**Example**
```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

This simulates:
```bash
< input.txt grep hello | wc -l > output.txt
```

---

## 🧠 Concepts Learned

- Process management (`fork`, `waitpid`)
- Inter-process communication using pipes
- Redirection of stdin and stdout with `dup2`
- Executing commands with `execve`
- Dynamic memory allocation and cleanup
- Parsing environment variables to resolve command paths

---

## 🔧 How It Works

1. The program reads the input file (`infile`) and prepares the output file (`outfile`).
2. A pipe is created to connect two processes.
3. The first child process executes the first command (`cmd1`):
   - Redirects stdin from `infile`
   - Redirects stdout to the pipe
4. The second child process executes the second command (`cmd2`):
   - Redirects stdin from the pipe
   - Redirects stdout to `outfile`
5. Parent process waits for both children to finish.
6. Memory and file descriptors are properly freed and closed.

---

## 📂 Project Structure
```
.
├── include/
│   └── pipex.h               # Structs and function prototypes
├── src/
│   ├── main.c                # Program entry point
│   ├── execute.c             # Command execution functions
│   ├── utils.c               # Utility functions
```
---
# 🇮🇹 Italiano

## 📖 Informazioni sul Progetto

**Pipex** simula il comportamento della shell Unix nell'uso delle **pipe** tra comandi.  
Il programma esegue due comandi in una pipeline, reindirizzando i file di input e output:

- Legge l'input da un file
- Esegue il primo comando
- Invia l'output al secondo comando tramite pipe
- Scrive l'output finale in un altro file

Questo progetto dimostra:

- Creazione di processi usando `fork`
- Esecuzione di comandi usando `execve`
- Comunicazione tra processi tramite `pipe()`
- Redirezione dei file usando `open`, `dup2`, `close`
- Gestione della memoria in C

---

## ⚙️ Utilizzo del Programma

```bash
./pipex infile "cmd1" "cmd2" outfile
```

# Parameters
| Parametro | Descrizione                                              |
|-----------|----------------------------------------------------------|
| infile    | Percorso del file di input                                |
| cmd1      | Primo comando da eseguire (con eventuali argomenti)      |
| cmd2      | Secondo comando da eseguire (con eventuali argomenti)    |
| outfile   | Percorso del file di output (verrà creato o sovrascritto)|

**Esempio**
```bash
./pipex input.txt "grep hello" "wc -l" output.txt
```

Questo simula:
```bash
< input.txt grep hello | wc -l > output.txt
```

---

## 🧠 Concetti Apprenditi

- Gestione dei processi (`fork`, `waitpid`)
- Comunicazione tra processi tramite pipe
- Redirezione di stdin e stdout con `dup2`
- Esecuzione di comandi con `execve`
- Allocazione dinamica della memoria e pulizia
- Parsing delle variabili d'ambiente per risolvere i percorsi dei comandi

---

## 🔧 Come Funziona

1. Il programma legge il file di input (`infile`) e prepara il file di output (`outfile`).
2. Viene creata una pipe per collegare due processi.
3. Il primo processo figlio esegue il primo comando (`cmd1`):
   - Redirige stdin dal file `infile`
   - Redirige stdout verso la pipe
4. Il secondo processo figlio esegue il secondo comando (`cmd2`):
   - Redirige stdin dalla pipe
   - Redirige stdout verso il file `outfile`
5. Il processo padre aspetta che entrambi i figli terminino.
6. Memoria e descrittori di file vengono liberati e chiusi correttamente.

---

## 📂 Project Structure
```
.
├── include/
│   └── pipex.h               # Strutture e prototipi delle funzioni
├── src/
│   ├── main.c                # Punto di ingresso del programma
│   ├── execute.c             # Funzioni per l'esecuzione dei comandi
│   ├── utils.c               # Funzioni di utilità
```
