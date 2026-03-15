# 📄 Philosophers

![Language](https://img.shields.io/badge/language-C-blue)
![42](https://img.shields.io/badge/school-42-black)

A simulation of the dining philosophers problem implemented in C using **threads** and **mutexes**. This project is part of the 42 Common Core curriculum and focuses on **concurrent programming and synchronization**.

---
# 🇬🇧 English

## 📖 About the Project

The **Philosophers** project simulates the classic **Dining Philosophers Problem**:

- Philosophers sit at a table with one fork between each of them.
- They alternately **think, eat, and sleep**.
- To eat, a philosopher must pick up both the left and right forks.
- The simulation ensures no philosopher **starves** and prevents **deadlocks** using mutexes.

This project demonstrates:

- Thread creation and management (`pthread_create`, `pthread_join`)
- Synchronization with mutexes
- Accurate timing using `gettimeofday`
- Memory safety and proper cleanup

---

## ⚙️ Program Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

# Parameters
| Parameter                                            | Description                                                          |
|------------------------------------------------------|----------------------------------------------------------------------|
| number_of_philosophers                               | Total number of philosophers at the table                            |
| time_to_die                                          | Time in milliseconds before a philosopher dies if they don't eat     |
| time_to_eat                                          | Time in milliseconds a philosopher spends eating                     |
| time_to_sleep                                        | Time in milliseconds a philosopher spends sleeping                   |
| number_of_times_each_philosopher_must_eat (optional) | Number of times each philosopher must eat before the simulation ends |

**Example**
```bash
./philo 5 800 200 200
./philo 4 410 200 200 7
```

## 🧠 Concepts Learned

- Thread management with pthread_t
- Mutex usage (pthread_mutex_t) for forks and shared resources
- Implementing deadlock prevention
- Accurate time measurement and usleep handling
- Managing shared data safely in concurrent environments
- Logging and synchronization of outputs

## 🔧 How It Works

Each philosopher is represented by a t_philo struct containing their id, meals eaten, and fork mutexes.

The t_program struct holds global data: all philosophers, forks, and synchronization mutexes.

Each philosopher runs a routine in a separate thread, looping through:

- Taking forks
- Eating
- Sleeping
- Thinking

A monitoring thread checks for death conditions and meal completion.

Mutexes prevent multiple philosophers from using the same fork simultaneously and ensure clean logging.

## 📂 Project Structure
```
.
├── include/
│   └── philo.h                 # Structs and function prototypes
├── src/
│   ├── main.c                  # Program entry point
│   ├── philo_routine.c         # Philosopher thread routines
│   ├── actions_philo.c         # Eating, sleeping, thinking, fork handling
│   ├── monitor_philo.c         # Monitoring philosophers and completion
│   ├── philo_check.c           # Input validation and initialization
│   ├── error_free_time_philo.c # Error handling, cleanup, timing
│   └── utils.c                 # Utility functions
├── Makefile
└── README.md
```

# 🇮🇹 Italiano

## 📖 Descrizione del Progetto

Il progetto **Philosophers** simula il classico **Problema dei Filosofi a Cena**:

- I filosofi sono seduti attorno a un tavolo con una forchetta tra ciascuno di loro.  
- Alternano fasi di **pensiero, pasto e sonno**.  
- Per mangiare, un filosofo deve prendere sia la forchetta a sinistra sia quella a destra.  
- La simulazione garantisce che nessun filosofo **muoia di fame** e previene i **deadlock** usando mutex.  

Questo progetto dimostra:

- Creazione e gestione dei thread (`pthread_create`, `pthread_join`)  
- Sincronizzazione tramite mutex  
- Misurazione accurata del tempo con `gettimeofday`  
- Sicurezza della memoria e pulizia corretta

---

## ⚙️ Utilizzo del programma

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

# Parameters

| Parametro                                            | Descrizione                                                          |
|------------------------------------------------------|----------------------------------------------------------------------|
| numero_di_filosofi                                   | Numero totale di filosofi al tavolo                                   |
| tempo_per_morire                                     | Tempo in millisecondi prima che un filosofo muoia se non mangia      |
| tempo_per_mangiare                                   | Tempo in millisecondi che un filosofo impiega per mangiare           |
| tempo_per_dormire                                    | Tempo in millisecondi che un filosofo impiega per dormire            |
| numero_di_volte_ogni_filosofo_deve_mangiare (opzionale) | Numero di volte che ogni filosofo deve mangiare prima che la simulazione finisca |

**Example**
```bash
./philo 5 800 200 200
./philo 4 410 200 200 7
```

## 🧠 Concetti Appresi

- Gestione dei thread con `pthread_t`
- Uso dei mutex (`pthread_mutex_t`) per le forchette e le risorse condivise
- Implementazione della prevenzione dei deadlock
- Misurazione accurata del tempo e gestione di `usleep`
- Gestione sicura dei dati condivisi in ambienti concorrenti
- Logging e sincronizzazione delle uscite

## 🔧 Come Funziona

Ogni filosofo è rappresentato da una struct `t_philo` contenente il suo id, i pasti consumati e i mutex delle forchette.

La struct `t_program` contiene i dati globali: tutti i filosofi, le forchette e i mutex di sincronizzazione.

Ogni filosofo esegue una routine in un thread separato, ciclano attraverso:

- Prendere le forchette
- Mangiare
- Dormire
- Pensare

Un thread di monitoraggio verifica le condizioni di morte e il completamento dei pasti.

I mutex impediscono a più filosofi di usare simultaneamente la stessa forchetta e garantiscono un logging ordinato.

## 📂 Struttura del Progetto
```
.
├── include/
│   └── philo.h                 # Struct e prototipi delle funzioni
├── src/
│   ├── main.c                  # Punto di ingresso del programma
│   ├── philo_routine.c         # Routine dei thread dei filosofi
│   ├── actions_philo.c         # Mangiare, dormire, pensare, gestione delle forchette
│   ├── monitor_philo.c         # Monitoraggio dei filosofi e completamento
│   ├── philo_check.c           # Validazione input e inizializzazione
│   ├── error_free_time_philo.c # Gestione errori, pulizia, temporizzazione
│   └── utils.c                 # Funzioni di utilità
├── Makefile
└── README.md
```
