# 📄 Push_Swap

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A sorting algorithm project that sorts integers using two stacks and a limited set of operations. This project is part of the 42 Common Core and focuses on **algorithm design, data structures, and optimization**.

---

# 🇬🇧 English

## 📖 About the Project

**Push_Swap** is a project designed to sort a list of integers using two stacks (stack A and stack B) and a limited set of commands:

- `sa` / `sb` / `ss` — Swap the first two elements of a stack
- `pa` / `pb` — Push the top element from one stack to the other
- `ra` / `rb` / `rr` — Rotate stack (top element becomes last)
- `rra` / `rrb` / `rrr` — Reverse rotate stack (last element becomes top)

The goal is to **sort the stack in ascending order using the fewest possible operations**.

This project demonstrates:

- Understanding of stack data structures
- Algorithm optimization for minimal operations
- Memory management in C
- Modular programming and reusable functions

---

## ⚙️ Program Usage

```bash
./push_swap [list_of_integers]
```

**Example:**

```bash
./push_swap 3 2 1 5 4
```

The program outputs the series of operations needed to sort the stack.

---

## 🧠 Concepts Learned

- Stack data structure manipulation
- Sorting algorithms and optimization
- Calculating operation “cost” to minimize moves
- Pointers and linked list management in C
- Error handling and input validation
- Modular program design

---

## 🔧 How It Works

### Algorithm Overview

Push_Swap uses a **two-stack sorting algorithm** optimized to reduce operations. The main steps are:

1. **Initialization**
   - Stack `A` contains all input integers.
   - Stack `B` starts empty.
   - Each node in stack `A` is indexed according to its sorted position.

2. **Splitting Around Median**
   - Compute the median of `A`.
   - Push elements to `B` based on whether they are above or below the median.
   - This step reduces the number of moves needed later.

3. **Finding Target Nodes**
   - For each element in `B`, determine the **target node** in `A` where it should be inserted.
   - `ft_target_node` finds the smallest value in `A` larger than the current element in `B`. If none exists, the minimum of `A` is chosen.

4. **Calculating Move Cost**
   - Each element in `B` is assigned a **push_price** representing the number of rotations needed to move it to its target in `A`.
   - The cost is computed considering whether nodes are above or below the median to decide between rotation and reverse rotation.

5. **Move the Cheapest Node**
   - Identify the node in `B` with the lowest push price (`ft_cheapest`).
   - Rotate both `A` and `B` as needed to position the node and its target correctly (`finish_rotation`).
   - Push the node from `B` to `A`.

6. **Repeat Until `B` is Empty**
   - Continue moving the cheapest node until all elements from `B` are back in `A` in the correct order.

7. **Final Alignment**
   - After all elements are in `A`, rotate the stack so that the smallest element is at the top (`ft_better_move`).

---

### Stack Operations Used

- `sa`, `sb`, `ss` — Swap
- `pa`, `pb` — Push
- `ra`, `rb`, `rr` — Rotate
- `rra`, `rrb`, `rrr` — Reverse rotate

### Key Functions

- `ft_target_node()` — Assigns target node for each element in `B`
- `ft_min_node()` — Finds the smallest node in a stack
- `ft_move_node()` — Executes the cheapest move from `B` to `A`
- `ft_cheapest()` — Returns the node with the minimal push price
- `finish_rotation()` — Rotates stack to align a node for pushing
- `ft_current_position()` — Updates each node’s position in the stack
- `ft_set_price()` — Calculates cost to move nodes
- `push_swap_loop()` — Iterates moving nodes until `B` is empty
- `ft_push_swap()` — Main algorithm for stacks larger than 5 elements

---

## 📂 Project Structure

```
.
├── include/
│   └── push_swap.h            # Structs and function prototypes
├── src/
│   ├── push_swap.c            # Main program, position and price calculations
│   ├── ft_fill_stack.c        # Stack initialization
│   ├── index_bubble.c         # Indexing and order checking
│   ├── sort_small_stack.c     # Sorting for small stacks (3-5 elements)
│   ├── algorithm.c            # Sorting algorithm and node targeting
│   ├── swap_command.c         # Swap operations
│   ├── rotate_command.c       # Rotate operations
│   ├── reverse_command.c      # Reverse rotate operations
│   ├── push_command.c         # Push operations
│   ├── ft_split.c             # Utility: split string
│   ├── ft_calloc.c            # Utility: memory allocation
│   └── push_swap_utils.c      # Helper functions, free stack, error handling
├── Makefile
└── README.md
```

# 🇮🇹 Italiano

## 📖 Informazioni sul Progetto

**Push_Swap** è un progetto progettato per ordinare una lista di numeri interi usando due stack (stack A e stack B) e un insieme limitato di comandi:

- `sa` / `sb` / `ss` — Scambia i primi due elementi di uno stack
- `pa` / `pb` — Spinge l'elemento in cima da uno stack all'altro
- `ra` / `rb` / `rr` — Ruota lo stack (l'elemento in cima diventa l'ultimo)
- `rra` / `rrb` / `rrr` — Ruota inversamente lo stack (l'ultimo elemento diventa il primo)

L'obiettivo è **ordinare lo stack in ordine crescente usando il minor numero possibile di operazioni**.

Questo progetto dimostra:

- Comprensione delle strutture dati a stack
- Ottimizzazione degli algoritmi per minimizzare le operazioni
- Gestione della memoria in C
- Programmazione modulare e creazione di funzioni riutilizzabili

---

## ⚙️ Utilizzo del progetto

```bash
./push_swap [lista_di_interi]
```

**Esempio:**

```bash
./push_swap 3 2 1 5 4
```

Il programma stampa la serie di operazioni necessarie per ordinare lo stack.

---

## 🧠 Concetti Appresi

- Manipolazione di strutture dati stack
- Algoritmi di ordinamento e ottimizzazione
- Calcolo del “costo” delle operazioni per minimizzare le mosse
- Gestione di puntatori e liste collegate in C
- Gestione degli errori e validazione degli input
- Progettazione modulare del programma

---

## 🔧 Come Funziona

### Panoramica dell’Algoritmo

Push_Swap utilizza un **algoritmo di ordinamento a due stack** ottimizzato per ridurre il numero di operazioni. I passaggi principali sono:

1. **Inizializzazione**
   - Lo stack `A` contiene tutti gli interi in input.
   - Lo stack `B` parte vuoto.
   - Ogni nodo nello stack `A` viene indicizzato secondo la sua posizione nell’ordine ordinato.

2. **Divisione intorno alla mediana**
   - Calcolare la mediana di `A`.
   - Spostare elementi in `B` a seconda che siano sopra o sotto la mediana.
   - Questo passaggio riduce il numero di mosse necessarie successivamente.

3. **Individuazione dei nodi target**
   - Per ogni elemento in `B`, determinare il **nodo target** in `A` dove dovrebbe essere inserito.
   - `ft_target_node` trova il valore più piccolo in `A` maggiore dell’elemento corrente in `B`. Se non esiste, viene scelto il minimo di `A`.

4. **Calcolo del costo della mossa**
   - Ad ogni elemento in `B` viene assegnato un **push_price** che rappresenta il numero di rotazioni necessarie per portarlo al suo target in `A`.
   - Il costo viene calcolato considerando se i nodi sono sopra o sotto la mediana per decidere tra rotazione e rotazione inversa.

5. **Spostare il nodo meno “costoso”**
   - Identificare il nodo in `B` con il push price più basso (`ft_cheapest`).
   - Ruotare sia `A` che `B` secondo necessità per posizionare correttamente il nodo e il suo target (`finish_rotation`).
   - Spostare il nodo da `B` a `A`.

6. **Ripetere fino a svuotare `B`**
   - Continuare a muovere il nodo meno costoso finché tutti gli elementi di `B` non sono tornati in `A` nell’ordine corretto.

7. **Allineamento finale**
   - Dopo che tutti gli elementi sono in `A`, ruotare lo stack affinché il valore più piccolo sia in cima (`ft_better_move`).
---

### Operazioni sugli Stack Utilizzate

- `sa`, `sb`, `ss` — Swap (scambio dei primi due elementi)
- `pa`, `pb` — Push (spostamento dell’elemento in cima da uno stack all’altro)
- `ra`, `rb`, `rr` — Rotate (rotazione dello stack: il primo elemento diventa l’ultimo)
- `rra`, `rrb`, `rrr` — Reverse rotate (rotazione inversa: l’ultimo elemento diventa il primo)

### Funzioni Chiave

- `ft_target_node()` — Assegna il nodo target per ogni elemento in `B`
- `ft_min_node()` — Trova il nodo più piccolo in uno stack
- `ft_move_node()` — Esegue la mossa meno “costosa” da `B` a `A`
- `ft_cheapest()` — Restituisce il nodo con il push price minimo
- `finish_rotation()` — Ruota lo stack per allineare un nodo prima di spingerlo
- `ft_current_position()` — Aggiorna la posizione di ciascun nodo nello stack
- `ft_set_price()` — Calcola il costo per muovere i nodi
- `push_swap_loop()` — Itera lo spostamento dei nodi fino a svuotare `B`
- `ft_push_swap()` — Algoritmo principale per stack con più di 5 elementi
---

## 📂 Struttura del Progetto

```
.
├── include/
│   └── push_swap.h            # Strutture e prototipi delle funzioni
├── src/
│   ├── push_swap.c            # Programma principale, calcolo posizione e prezzo
│   ├── ft_fill_stack.c        # Inizializzazione dello stack
│   ├── index_bubble.c         # Indicizzazione e controllo ordine
│   ├── sort_small_stack.c     # Ordinamento per stack piccoli (3-5 elementi)
│   ├── algorithm.c            # Algoritmo di ordinamento e targeting dei nodi
│   ├── swap_command.c         # Operazioni di swap
│   ├── rotate_command.c       # Operazioni di rotazione
│   ├── reverse_command.c      # Operazioni di rotazione inversa
│   ├── push_command.c         # Operazioni di push
│   ├── ft_split.c             # Utility: suddivisione stringhe
│   ├── ft_calloc.c            # Utility: allocazione memoria
│   └── push_swap_utils.c      # Funzioni di supporto, gestione stack e errori
├── Makefile
└── README.md
```