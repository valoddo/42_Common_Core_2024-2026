# 🌌 MiniRT — Minimal Ray Tracer

![Language](https://img.shields.io/badge/language-C-blue)
![Graphics](https://img.shields.io/badge/graphics-raytracing-orange)
![Library](https://img.shields.io/badge/library-MiniLibX-green)
![42](https://img.shields.io/badge/school-42-black)

A **minimal ray tracer written in C**, developed as part of the 42 Common Core.
The program renders a 3D scene described in a `.rt` file using ray tracing techniques and displays it in a graphical window.

---

# 🇬🇧 English

## 📖 Overview

**MiniRT** is a simple ray tracing engine that generates images by simulating light rays interacting with objects in a 3D scene.

Rays are traced from the camera into the scene, computing pixel colors based on intersections, normals, and lighting.

The project is implemented using **MiniLibX**, the graphics library provided by 42.

---

## 🖥️ Rendering Example

Include your rendered scene here:

```id="2e5zmh"
assets/render.png
```

---

## ⚙️ Compilation

Compile the project:

```bash
make
```

Dependencies:

* MiniLibX
* math library (`-lm`)
* X11 libraries (Linux)

---

## 🚀 Usage

Run the program with a scene file:

```bash
./miniRT scene.rt
```

A window will open showing the rendered scene.

---

# 🎬 Scene Description (.rt)

Example `.rt` file:

```c id="wo9lbg"
A 0.2 255,255,255
C 0,0,20 0,0,-1 70
L 10,10,10 0.7 255,255,255

sp 0,0,0 10 255,0,0
pl 0,-10,0 0,1,0 0,255,0
cy 20,0,0 0,1,0 5 20 0,0,255
```

### Scene Elements

| Identifier | Description   |
| ---------- | ------------- |
| A          | Ambient light |
| C          | Camera        |
| L          | Light source  |
| sp         | Sphere        |
| pl         | Plane         |
| cy         | Cylinder      |
| co         | Cone (bonus)  |

---

# 🎥 Ray Tracing Pipeline

For every pixel:

1️⃣ Generate a ray from the camera
2️⃣ Compute intersections with scene objects
3️⃣ Find the **closest intersection**
4️⃣ Compute surface normal
5️⃣ Apply lighting model (Phong)
6️⃣ Cast **shadow rays** to check occlusion
7️⃣ Determine final pixel color

---

# 💡 Lighting Model

### Mandatory

* Ambient
* Diffuse
* Specular (Phong)
* Shadow rays (objects cast shadows)

### Bonus

* Multiple light sources
* Cone object
* Enhanced Phong (multiple light contributions)

Final color:

```c id="2ezn3t"
color = ambient + diffuse + specular + shadows
```

---

# 📐 Mathematical Concepts

* Vector operations (add, sub, mul, div, normalize)
* Dot and cross product
* Ray equation: `P(t) = origin + t * direction`
* Quadratic equations for intersections
* Surface normals calculation

---

# 🔺 Supported Objects

### Mandatory

| Object   | Description     |
| -------- | --------------- |
| Sphere   | Center + radius |
| Plane    | Infinite plane  |
| Cylinder | Radius + height |

### Bonus

| Object          | Description               |
| --------------- | ------------------------- |
| Cone            | Finite cone               |
| Multiple lights | Summed Phong contribution |

---

# 🎮 Interactive Controls (Bonus)

| Key           | Action        |
| ------------- | ------------- |
| ESC           | Exit          |
| W / A / S / D | Move camera   |
| Arrow Keys    | Rotate camera |
| Q / E         | Rotate object |
| N / M         | Zoom          |
| Mouse Click   | Select object |
| C             | Select camera |
| L             | Select light  |

---

# 🧠 Architecture

```text
miniRT
│
├── parsing        → read .rt scene file
├── math           → vectors and geometry
├── intersection   → ray-object intersection
├── lighting       → phong lighting & shadows
├── rendering      → ray generation and pixel color
├── events         → keyboard & mouse interactions
├── utils          → helper functions
├── get_next_line  → file reading
└── minilibx-linux → graphics library
```

---

# 📂 Project Structure

```text
.
├── includes/
├── src/
├── parsing/
├── lighting/
├── intersections/
├── utils/
├── get_next_line/
├── minilibx-linux/
├── scenes/
└── Makefile
```

---

# 🎯 Learning Outcomes

* Fundamentals of **ray tracing**
* 3D **rendering pipelines**
* Vector & geometric mathematics
* Implementing **lighting models** with shadows
* Parsing structured scene files
* Interactive graphics programming
* Using a low-level graphics library

---

# 🇮🇹 Italiano

## 📖 Descrizione

**MiniRT** è un semplice ray tracer scritto in C che renderizza una scena 3D descritta in un file `.rt`.

Il programma genera un raggio per ogni pixel, calcola l’intersezione con gli oggetti e determina il colore finale usando modelli di illuminazione Phong e calcolando le ombre.

Il rendering viene visualizzato tramite **MiniLibX**.

---

## 🖥️ Esempio di Render

Includi qui la tua scena renderizzata:

```id="2e5zmh"
assets/render.png
```

---

## ⚙️ Compilazione

Compila il progetto:

```bash
make
```

Dipendenze:

* MiniLibX
* libreria matematica (`-lm`)
* librerie X11 (Linux)

---

## 🚀 Utilizzo

Esegui il programma con un file di scena:

```bash
./miniRT scene.rt
```

Si aprirà una finestra che mostra la scena renderizzata.

---

# 🎬 Descrizione del File di Scena (.rt)

Esempio di file `.rt` :

```c id="wo9lbg"
A 0.2 255,255,255
C 0,0,20 0,0,-1 70
L 10,10,10 0.7 255,255,255

sp 0,0,0 10 255,0,0
pl 0,-10,0 0,1,0 0,255,0
cy 20,0,0 0,1,0 5 20 0,0,255
```

### Elementi della Scena

| Identificatore | Descrizione        |
| -------------- | ------------------ |
| A              | Luce ambientale    |
| C              | Camera             |
| L              | Sorgente luminosa  |
| sp             | Sfere              |
| pl             | Piano              |
| cy             | Cilindro           |
| co             | Cono (bonus)       |

---

# 🎥 Pipeline del Ray Tracing
Per ogni pixel:

1️⃣ Genera un raggio dalla camera
2️⃣ Calcola le intersezioni con gli oggetti della scena
3️⃣ Trova **l'intersezione più vicina**
4️⃣ Calcola la normale alla superficie
5️⃣ Applica il modello di illuminazione (Phong)
6️⃣ Genera **raggi d'ombra** per verificare l'occlusione
7️⃣ Determina il colore finale del pixel

---

# 💡 Modello di Illuminazione

### Obbligatorio

* Ambientale
* Diffusa
* Speculare (Phong)
* Raggi d'ombra (gli oggetti proiettano ombre)

### Bonus

* Molteplici sorgenti luminose
* Oggetto cono
* Phong avanzato (contributo di più luci)

Colore finale:

```c id="2ezn3t"
colore = ambientale + diffusa + speculare + ombre
```

---

# 📐 Concetti Matematici

* Operazioni vettoriali (addizione, sottrazione, moltiplicazione, divisione, normalizzazione)
* Prodotto scalare e vettoriale
* Equazione del raggio:  `P(t) = origine + t * direzione`
* Equazioni quadratiche per le intersezioni
* Calcolo delle normali alle superfici

---

# 🔺 Oggetti Supportati

### Obbligatori

| Oggetto   | Descrizione      |
| --------- | ---------------- |
| Sfere     | Centro + raggio  |
| Piano     | Piano infinito   |
| Cilindro  | Raggio + altezza |

### Bonus

| Oggetto          | Descrizione               |
| ---------------- | ------------------------- |
| Cono             | Cono finito               |
| Luci multiple    | Somma contributi Phong    |

---

# 🎮 Controlli Interattivi (Bonus)

| Tasto           | Azione            |
| --------------- | ----------------- |
| ESC             | Esci              |
| W / A / S / D   | Muovi camera      |
| Arrow Keys      | Ruota camera      |
| Q / E           | Ruota oggetto     |
| N / M           | Zoom              |
| Mouse Click     | Seleziona oggetto |
| C               | Seleziona camera  |
| L               | Seleziona luce    |

---

# 🧠 Architettura

```text
miniRT
│
├── parsing        → lettura file .rt
├── math           → vettori e geometria
├── intersezione   → intersezione raggio-oggetto
├── illuminazione  → illuminazione Phong e ombre
├── rendering      → generazione raggi e colore pixel
├── eventi         → interazioni tastiera e mouse
├── utils          → funzioni di supporto
├── get_next_line  → lettura file
└── minilibx-linux → libreria grafica
```

---

# 📂 Struttura del Progetto

```text
.
├── includes/
├── src/
├── parsing/
├── illuminazione/
├── intersezioni/
├── utils/
├── get_next_line/
├── minilibx-linux/
├── scenes/
└── Makefile
```

---

# 🎯 Risultati dell'Apprendimento

* Fondamenti del **ray tracing**
* 3D **rendering pipeline**
* Matematica vettoriale e geometrica
* Implementazione di modelli di **illuminazione** con ombre
* Parsing di file di scena strutturati
* Programmazione grafica interattiva
* Utilizzo di una libreria grafica di basso livello

---
