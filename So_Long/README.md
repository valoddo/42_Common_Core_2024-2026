# 🎮 So_Long

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A 2D game project developed in C using **MiniLibX**, where the player navigates a map, collects items, and reaches the exit. Bonus features include **animated enemies** and **player sprites in multiple directions**.

---

# 🇬🇧 English

## 📖 About the Project

**So_Long** is a small 2D game where the player moves through a map, collects collectibles, and reaches the exit. The project uses:

- **MiniLibX** for graphics and window handling
- **get_next_line** for reading map files
- **ft_printf** for formatted output

The bonus implementation adds:

- Animated enemies (`enemy_n[2]`)
- Player sprite animations in multiple directions (front, back, left, right)
- Exit animations when the player reaches the goal

This project demonstrates:

- 2D game rendering
- Keyboard input handling
- Map parsing and validation
- Pathfinding with flood fill
- Sprite animation and frame handling
- Memory management and cleanup

---

## ⚙️ Program Usage

```bash
./so_long map.ber
```

- `map.ber` is a text file representing the game map.  
- Each character in the map defines a tile:
  - `0` – empty space
  - `1` – wall
  - `C` – collectible
  - `E` – exit
  - `P` – player start
  - `N` – enemy (bonus)

---

## 🧠 Concepts Learned

- 2D game rendering with MiniLibX
- Keyboard input handling and key events
- Sprite animation and multiple frame management
- Map parsing, validation, and flood-fill pathfinding
- Linked list and queue usage for pathfinding
- Memory allocation and cleanup
- Implementing bonus features for more interactive gameplay

---

## 🔧 How It Works

1. **Map Parsing**
   - Reads the `.ber` map file
   - Validates the map (walls, collectibles, player, exit)
   - Creates a map copy for pathfinding

2. **Window and Graphics Initialization**
   - Creates a MiniLibX window
   - Loads sprites for walls, floor, collectibles, exit, player, and enemies
   - Handles player animations in multiple directions

3. **Gameplay Loop**
   - Player moves using keyboard (`WASD` or arrows)
   - Player collects collectibles
   - Player reaches the exit to win
   - Enemies move and animate (bonus)
   - Moves are counted and displayed

4. **Pathfinding**
   - Flood-fill algorithm checks if all collectibles and exit are reachable
   - Ensures the map is solvable

5. **Animation**
   - Player sprites animate according to direction
   - Enemies animate between two frames (bonus)
   - Exit sprite changes when all collectibles are collected (bonus)

6. **Cleanup**
   - Properly frees memory for the map, map copy, and sprite images
   - Closes the window safely on exit

---

## ⌨️ Controls

| Action            | Key                       |
|-------------------|---------------------------|
| Move up           | W / Up Arrow              |
| Move down         | S / Down Arrow            |
| Move left         | A / Left Arrow            |
| Move right        | D / Right Arrow           |
| Exit game         | ESC                       |

---

## 📂 Project Structure

```
.
├── assets/                   # Sprites for player, enemies, collectibles, walls, exit
├── include/
│   └── so_long.h             # Structs and function prototypes
├── src/
│   ├── so_long.c             # Main loop, window and sprite initialization
│   ├── map_so_long.c         # Map reading and parsing
│   ├── map_checks_so_long.c  # Map validation functions
│   ├── pathfinding_so_long.c # Pathfinding functions for player, exit, enemies
│   ├── pathfinding_utils_so_long.c # Flood fill and helper functions
│   ├── queue_and_free_so_long.c    # Queue management and memory cleanup
│   ├── movement_close_so_long.c    # Player movement and key events
│   ├── sprite_so_long.c      # Player and enemy animations
│   ├── so_long.utils.c       # Utility functions
│   ├── error_free_so_long.c  # Error handling and memory free
│   ├── itoa.c                # Integer to string utility
├── Makefile
└── README.md
```

---

## 🎯 Learning Outcomes

- Rendering 2D graphics with MiniLibX
- Handling keyboard input for interactive games
- Implementing animations and frame management
- Validating map correctness and pathfinding
- Memory management and cleanup in C
- Adding bonus gameplay features: enemy animations, multiple sprite directions, dynamic exit

---

# 🇮🇹 Italiano

## 📖 Informazioni sul Progetto

**So_Long** è un piccolo gioco 2D in cui il giocatore si muove all'interno di una mappa, raccoglie collezionabili e raggiunge l'uscita. Il progetto utilizza:

- **MiniLibX** per la grafica e la gestione della finestra
- **get_next_line** per leggere i file della mappa
- **ft_printf** per output formattato

L'implementazione bonus aggiunge:

- Nemici animati (`enemy_n[2]`)
- Animazioni del giocatore in più direzioni (fronte, retro, sinistra, destra)
- Animazioni dell'uscita quando il giocatore raggiunge l'obiettivo

Questo progetto dimostra:

- Rendering di giochi 2D
- Gestione dell'input da tastiera
- Parsing e validazione della mappa
- Ricerca del percorso con flood fill
- Animazione degli sprite e gestione dei frame
- Gestione della memoria e cleanup

---

## ⚙️ Utilizzo del programma

```bash
./so_long map.ber
```

- `map.ber` è un file di testo che rappresenta la mappa di gioco.  
- Ogni carattere nella mappa definisce una casella:
  - `0` – spazio vuoto
  - `1` – muro
  - `C` – collezionabile
  - `E` – uscita
  - `P` – posizione iniziale del giocatore
  - `N` – nemico (bonus)

---

## 🧠 Concetti Appresi

- Rendering di giochi 2D con MiniLibX
- Gestione dell’input da tastiera e degli eventi dei tasti
- Animazione degli sprite e gestione di più frame
- Parsing della mappa, validazione e pathfinding con flood-fill
- Uso di liste collegate e code per il pathfinding
- Allocazione e gestione della memoria
- Implementazione di funzionalità bonus per un gameplay più interattivo

---

## 🔧 Come Funziona

1. **Parsing della Mappa**
   - Legge il file mappa `.ber`
   - Valida la mappa (muri, collectible, giocatore, uscita)
   - Crea una copia della mappa per il pathfinding

2. **Inizializzazione della Finestra e Grafica**
   - Crea una finestra con MiniLibX
   - Carica gli sprite per muri, pavimento, collectible, uscita, giocatore e nemici
   - Gestisce le animazioni del giocatore in più direzioni

3. **Loop di Gioco**
   - Il giocatore si muove tramite tastiera (`WASD` o frecce)
   - Il giocatore raccoglie i collectible
   - Il giocatore raggiunge l’uscita per vincere
   - I nemici si muovono e animano (bonus)
   - I movimenti vengono contati e visualizzati

4. **Pathfinding**
   - L’algoritmo flood-fill verifica che tutti i collectible e l’uscita siano raggiungibili
   - Garantisce che la mappa sia risolvibile

5. **Animazione**
   - Gli sprite del giocatore animano in base alla direzione
   - I nemici animano tra due frame (bonus)
   - Lo sprite dell’uscita cambia quando tutti i collectible sono raccolti (bonus)

6. **Pulizia**
   - Libera correttamente la memoria della mappa, della copia della mappa e degli sprite
   - Chiude la finestra in sicurezza all’uscita

---

## ⌨️ Controllo

| Azione            | Tasto                     |
|-------------------|---------------------------|
| Muovi su          | W / Freccia Su            |
| Muovi giù         | S / Freccia Giù           |
| Muovi a sinistra  | A / Freccia Sinistra      |
| Muovi a destra    | D / Freccia Destra        |
| Esci dal gioco    | ESC                       |

---

## 📂 Struttura del Progetto

```
.
├── assets/                       # Sprite per giocatore, nemici, collezionabili, muri, uscita
├── include/
│   └── so_long.h                 # Strutture e prototipi delle funzioni
├── src/
│   ├── so_long.c                 # Ciclo principale, inizializzazione finestra e sprite
│   ├── map_so_long.c             # Lettura e parsing della mappa
│   ├── map_checks_so_long.c      # Funzioni di validazione della mappa
│   ├── pathfinding_so_long.c     # Funzioni di pathfinding per giocatore, uscita, nemici
│   ├── pathfinding_utils_so_long.c # Flood fill e funzioni di supporto
│   ├── queue_and_free_so_long.c  # Gestione della coda e pulizia memoria
│   ├── movement_close_so_long.c  # Movimento del giocatore e gestione tasti
│   ├── sprite_so_long.c          # Animazioni del giocatore e nemici
│   ├── so_long.utils.c           # Funzioni di utilità
│   ├── error_free_so_long.c      # Gestione errori e liberazione memoria
│   ├── itoa.c                    # Utility conversione intero -> stringa
├── Makefile
└── README.md
```

---

## 🎯 Risultati dell'Apprendimento

- Rendering di grafica 2D con MiniLibX
- Gestione dell'input da tastiera per giochi interattivi
- Implementazione di animazioni e gestione dei frame
- Validazione della correttezza della mappa e pathfinding
- Gestione della memoria e pulizia in C
- Aggiunta di funzionalità bonus: animazioni dei nemici, sprite del giocatore in più direzioni, uscita dinamica

---