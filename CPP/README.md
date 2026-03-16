# 🖥️ CPP Modules  
Language 42  

A comprehensive overview of the C++ modules in the 42 curriculum, summarizing all key concepts and projects.

---

## 🇬🇧 English  

### 📖 About the Project
The CPP modules at 42 cover the essentials and advanced features of C++, including object-oriented programming, memory management, templates, and the Standard Template Library (STL).  

The goal is to build a solid foundation in C++ by implementing projects that demonstrate:

- Class design and object-oriented principles
- Memory management and resource control
- Generic programming with templates
- STL usage for containers and algorithms
- Low-level understanding of C++ constructs

This set of modules focuses on:

- Classes, objects, constructors, and destructors  
- Encapsulation, inheritance, and polymorphism  
- Operator overloading and copy/move semantics  
- Dynamic memory allocation (`new`/`delete`)  
- Templates for functions and classes  
- Exception handling (`try`, `catch`, `throw`)  
- STL containers (`vector`, `list`, `map`, `set`) and algorithms  

---

### ⚙️ Compilation
To compile your projects:

```bash
g++ -Wall -Wextra -Werror main.cpp MyClass.cpp -o my_program
```

Replace `main.cpp` and `MyClass.cpp` with your project files.  

If using multiple modules, it’s recommended to create a Makefile to handle compilation efficiently.

---

### 🚀 Usage
1. Clone the repository:  

```bash
git clone https://github.com/yourusername/cpp_modules_42.git
cd cpp_modules_42
```

2. Compile your program:  

```bash
make
```

3. Run your program:  

```bash
./my_program
```

---

### 🔧 Key Concepts and Examples

#### Classes and Objects

```cpp
class Dog {
private:
    std::string name;
public:
    Dog(std::string n) : name(n) {}
    void bark() { std::cout << name << " says woof!" << std::endl; }
};

int main() {
    Dog dog("Buddy");
    dog.bark();
}
```

#### Inheritance and Polymorphism

```cpp
class Animal {
public:
    virtual void speak() = 0; // abstract class
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Meow" << std::endl; }
};
```

#### Templates

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

#### STL Example

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {3, 1, 4, 2};
    std::sort(v.begin(), v.end());
    for (int n : v)
        std::cout << n << " ";
}
```

---

### 🧠 Learning Outcomes
Through the CPP modules, I learned:

- Object-oriented programming (classes, inheritance, polymorphism)  
- Memory management and dynamic allocation  
- Operator overloading and copy/move semantics  
- Writing generic functions and classes with templates  
- Using STL containers and algorithms efficiently  
- Exception handling and robust error management  
- Writing modular, reusable, and maintainable C++ code

---

# 🇮🇹 Italiano

### 📖 Informazioni sul Progetto

I moduli CPP alla scuola 42 coprono le funzionalità essenziali e avanzate del C++, inclusa la programmazione orientata agli oggetti, la gestione della memoria, i template e la Standard Template Library (STL).

L'obiettivo è costruire una solida base in C++ implementando progetti che dimostrino:

* Progettazione di classi e principi della programmazione orientata agli oggetti
* Gestione della memoria e controllo delle risorse
* Programmazione generica con i template
* Uso della STL per contenitori e algoritmi
* Comprensione a basso livello delle strutture del C++

Questo insieme di moduli si concentra su:

* Classi, oggetti, costruttori e distruttori
* Incapsulamento, ereditarietà e polimorfismo
* Overloading degli operatori e semantica di copia/move
* Allocazione dinamica della memoria (`new`/`delete`)
* Template per funzioni e classi
* Gestione delle eccezioni (`try`, `catch`, `throw`)
* Contenitori STL (`vector`, `list`, `map`, `set`) e algoritmi

---
### ⚙️ Compilazione

Per compilare i tuoi progetti:

```bash
g++ -Wall -Wextra -Werror main.cpp MyClass.cpp -o my_program
```

Sostituisci `main.cpp` e `MyClass.cpp` con i file del tuo progetto.

Se utilizzi più moduli, è consigliato creare un Makefile per gestire la compilazione in modo efficiente.

---
### 🚀 Utilizzo

1. Clona il repository:

```bash
git clone https://github.com/yourusername/cpp_modules_42.git
cd cpp_modules_42
```

2. Compila il tuo programma:

```bash
make
```

3. Esegui il tuo programma:

```bash
./my_program
```

---

### 🔧 Concetti Chiave ed Esempi

#### Classi e Oggetti

```cpp
class Dog {
private:
    std::string name;
public:
    Dog(std::string n) : name(n) {}
    void bark() { std::cout << name << " dice bau!" << std::endl; }
};

int main() {
    Dog dog("Buddy");
    dog.bark();
}
```

#### Ereditarietà e Polimorfismo

```cpp
class Animal {
public:
    virtual void speak() = 0; // classe astratta
};

class Cat : public Animal {
public:
    void speak() override { std::cout << "Miao" << std::endl; }
};
```

#### Template

```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}
```

#### Esempio STL

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {3, 1, 4, 2};
    std::sort(v.begin(), v.end());
    for (int n : v)
        std::cout << n << " ";
}
```

---

### 🧠 Risultati di Apprendimento

Attraverso i moduli CPP, ho imparato:

* Programmazione orientata agli oggetti (classi, ereditarietà, polimorfismo)
* Gestione della memoria e allocazione dinamica
* Overloading degli operatori e semantica di copia/move
* Scrivere funzioni e classi generiche con i template
* Utilizzare efficacemente i contenitori STL e gli algoritmi
* Gestione delle eccezioni e controllo robusto degli errori
* Scrivere codice C++ modulare, riutilizzabile e manutenibile
