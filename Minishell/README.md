# 📄 minishell

![Language](https://img.shields.io/badge/language-C-blue)
![Library](https://img.shields.io/badge/library-readline-green)
![42](https://img.shields.io/badge/school-42-black)

A minimal UNIX shell implemented in C, developed as part of the 42 Common Core mandatory projects.  
This project implements a functional shell that supports **built-in commands, pipelines, redirections, heredocs, and environment variable expansion**.

---

# 🇬🇧 English

## 📖 About the Project

**minishell** is a lightweight shell that emulates basic behavior of bash. It supports:

- Command parsing and tokenization
- Environment variable expansion (`$VAR`)
- Built-in commands (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- Execution of external commands
- File redirections (`>`, `>>`, `<`) and heredocs (`<<`)
- Pipelines (`|`)
- Signal handling (`Ctrl+C`, `Ctrl+\`)

The shell demonstrates **process control, I/O redirection, memory management, and parsing in C**.

---

## ⚙️ Features Implemented (Mandatory)

- Interactive prompt using **readline** with history
- Command parsing and tokenization
- Built-in commands executed in parent or child process
- External commands executed using **fork** + **execve**
- Single and multiple **pipe support**
- Input/output redirection
- Heredoc support
- Environment variable management
- Basic **syntax validation**
- Signal handling (`SIGINT`, `SIGQUIT`)

---

## 🔧 How It Works – Portfolio Overview

The shell has a **modular architecture**:

1. **Read Input**
   - User input is read via `readline()`  
   - History is automatically handled

2. **Tokenization**
   - Input string is split into tokens: words, operators, quotes, and variables  
   - Token types include: `WORD`, `PIPE`, `REDIRECT_IN`, `REDIRECT_OUT`, `HEREDOC`, `SQUOTE`, `DQUOTE`, `DOLLAR`

3. **Syntax Validation**
   - Checks for:
     - Unmatched quotes
     - Misplaced pipes or redirections
     - Invalid syntax sequences

4. **Node/AST Construction**
   - Tokens are converted into a **command node** structure
   - Each node contains:
     - Arguments (`argv`)
     - Redirections
     - Links to next commands for pipelines

5. **Execution Loop**
   - Built-ins executed in parent or child
   - External commands executed in child process
   - File descriptors handled for redirections and pipes
   - Heredoc buffers preprocessed

6. **Environment Variables**
   - `$VAR` expansion
   - Exported variables managed with `export` and `unset`

7. **Signal Handling**
   - `Ctrl+C` interrupts current command
   - `Ctrl+\` ignored in interactive mode
   - Heredoc has special SIGINT handling

---

### Portfolio Diagrams

**Tokenization Flow**

Input: cat file.txt | grep hello > out.txt

```
+-------------------+
| Raw Input String  |
+-------------------+
|
v
+-------------------+
| Tokenization       |
| -> WORD            |
| -> PIPE            |
| -> WORD            |
| -> REDIR_OUT       |
| -> WORD            |
+-------------------+
```

**AST / Node Construction**

```
[Node1: cat file.txt] -> [Node2: grep hello > out.txt]
Node1.argv = ["cat", "file.txt"]
Node2.argv = ["grep", "hello"]
Node2.redirs = [REDIR_OUT -> "out.txt"]
```

**Execution Pipeline**

```
Node1 (cat) --pipe--> Node2 (grep)
stdout redirected to pipe
Node2 stdout redirected to out.txt
```

**Heredoc Flow**

Command: cat << EOF
Heredoc input lines
EOF

```
+-------------------+
| Detect HEREDOC    |
+-------------------+
|
v
+-------------------+
| Read heredoc lines |
+-------------------+
|
v
+-------------------+
| Store in buffer   |
+-------------------+
|
v
+-------------------+
| Redirect stdin    |
+-------------------+
```

---

## 🚀 Usage

Start the shell:

```bash
./minishell

echo "Hello World"
cd ..
pwd
export PATH=/usr/bin
unset VAR
env
exit 0
```

Redirections and pipelines:

```bash
ls -l | grep minishell > output.txt
cat < input.txt | wc -l
```

Heredoc:

```bash
cat << EOF
Hello
World
EOF
```

---

## 🧠 Concepts Learned

- Process control (`fork`, `execve`, `waitpid`)
- Pipes and redirections (`dup2`, `close`)
- Tokenization and parsing
- Memory management
- Environment variable expansion
- Signal handling in interactive programs
- Implementing a shell architecture from scratch

---

## 📂 Project Structure

```
.
├── include/
│   └── minishell.h         # Main structs and prototypes
├── src/
│   ├── main.c              # Shell loop
│   ├── tokenize_mini.c     # Tokenization
│   ├── node_mini.c         # AST / command nodes
│   ├── executor_loop.c     # Execution logic
│   ├── btin_apply.c        # Built-in commands
│   ├── heredoc_buffer.c    # Heredoc handling
│   ├── utils.c             # Utilities
│   └── ...                 # Supporting files
├── Makefile
└── README.md
```
---

# 🇮🇹 Italiano

## 📖 Informazioni sul Progetto

**minishell** è una shell leggera che emula il comportamento di base di **bash**. Supporta:

- Parsing e tokenizzazione dei comandi
- Espansione delle variabili d'ambiente (`$VAR`)
- Comandi built-in (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- Esecuzione di comandi esterni
- Redirezioni dei file (`>`, `>>`, `<`) e heredoc (`<<`)
- Pipeline (`|`)
- Gestione dei segnali (`Ctrl+C`, `Ctrl+\`)

La shell dimostra **controllo dei processi, redirezione dell'I/O, gestione della memoria e parsing in C**.

---

## ⚙️ Funzionalità Implementate (Obbligatorie)

- Prompt interattivo usando **readline** con cronologia dei comandi
- Parsing e tokenizzazione dei comandi
- Comandi built-in eseguiti nel processo parent o nel processo child
- Comandi esterni eseguiti utilizzando **fork** + **execve**
- Supporto a **pipe singole e multiple**
- Redirezione di input/output
- Supporto **heredoc**
- Gestione delle variabili d'ambiente
- **Validazione di base della sintassi**
- Gestione dei segnali (`SIGINT`, `SIGQUIT`)

---

## 🔧 Come Funziona – Panoramica dell’Implementazione

La shell ha un'**architettura modulare**:

1. **Lettura dell’Input**
   - L’input dell’utente viene letto tramite `readline()`
   - La cronologia dei comandi viene gestita automaticamente

2. **Tokenizzazione**
   - La stringa di input viene suddivisa in token: parole, operatori, virgolette e variabili
   - I tipi di token includono: `WORD`, `PIPE`, `REDIRECT_IN`, `REDIRECT_OUT`, `HEREDOC`, `SQUOTE`, `DQUOTE`, `DOLLAR`

3. **Validazione della Sintassi**
   - Controlli effettuati:
     - Virgolette non chiuse
     - Pipe o redirezioni posizionate in modo errato
     - Sequenze sintattiche non valide

4. **Costruzione dei Node / AST**
   - I token vengono convertiti in una **struttura di nodi di comando**
   - Ogni nodo contiene:
     - Gli argomenti (`argv`)
     - Le redirezioni
     - Collegamenti ai comandi successivi nelle pipeline

5. **Loop di Esecuzione**
   - I built-in vengono eseguiti nel processo parent o child
   - I comandi esterni vengono eseguiti in un processo figlio
   - I file descriptor vengono gestiti per redirezioni e pipe
   - I buffer degli heredoc vengono preprocessati

6. **Variabili d’Ambiente**
   - Espansione delle variabili `$VAR`
   - Le variabili esportate sono gestite tramite `export` e `unset`

7. **Gestione dei Segnali**
   - `Ctrl+C` interrompe il comando corrente
   - `Ctrl+\` viene ignorato in modalità interattiva
   - Gli heredoc hanno una gestione speciale del segnale `SIGINT`

---

### Diagrammi del Portfolio

**Flusso di Tokenizzazione**

Input: `cat file.txt | grep hello > out.txt`


```
+-------------------+
| Stringa di Input |
+-------------------+
|
v
+-------------------+
| Tokenizzazione |
| -> WORD |
| -> PIPE |
| -> WORD |
| -> REDIR_OUT |
| -> WORD |
+-------------------+
```


**Costruzione AST / Nodi**

```
[Node1: cat file.txt] -> [Node2: grep hello > out.txt]
Node1.argv = ["cat", "file.txt"]
Node2.argv = ["grep", "hello"]
Node2.redirs = [REDIR_OUT -> "out.txt"]
```
**Esecuzione della Pipeline**

```
Node1 (cat) --pipe--> Node2 (grep)
stdout reindirizzato alla pipe
Node2 stdout reindirizzato su out.txt
```

**Flusso Heredoc**

Comando: cat << EOF
Heredoc input lines
EOF

```
+-------------------+
| Rileva HEREDOC |
+-------------------+
|
v
+-------------------+
| Legge le linee |
| dell'heredoc |
+-------------------+
|
v
+-------------------+
| Salva nel buffer |
+-------------------+
|
v
+-------------------+
| Reindirizza stdin |
+-------------------+
```

---

## 🚀 Utilizzo

Avvia la shell:

```bash
./minishell

echo "Hello World"
cd ..
pwd
export PATH=/usr/bin
unset VAR
env
exit 0
```

Redirezioni e pipeline:

```bash
ls -l | grep minishell > output.txt
cat < input.txt | wc -l
```

Heredoc:

```bash
cat << EOF
Hello
World
EOF
```

---

## 🧠 Concetti Appresi

- Controllo dei processi (`fork`, `execve`, `waitpid`)
- Pipe e redirezioni (`dup2`, `close`)
- Tokenizzazione e parsing
- Gestione della memoria
- Espansione delle variabili d’ambiente
- Gestione dei segnali nei programmi interattivi
- Implementazione dell’architettura di una shell da zero

---

## 📂 Struttura del Progetto

```
.
├── include/
│   └── minishell.h         # Strutture principali e prototipi
├── src/
│   ├── main.c              # Loop principale della shell
│   ├── tokenize_mini.c     # Tokenizzazione
│   ├── node_mini.c         # AST / nodi dei comandi
│   ├── executor_loop.c     # Logica di esecuzione
│   ├── btin_apply.c        # Comandi built-in
│   ├── heredoc_buffer.c    # Gestione heredoc
│   ├── utils.c             # Funzioni di utilità
│   └── ...                 # File di supporto
├── Makefile
└── README.md
```
---
