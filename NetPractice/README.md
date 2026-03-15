# 🌐 NetPractice

![School](https://img.shields.io/badge/school-42-black)
![Topic](https://img.shields.io/badge/topic-networking-blue)

A networking fundamentals project from the **42 Common Core** focused on understanding how computer networks operate through practical configuration exercises.

---

# 🇬🇧 English

## 📖 About the Project

**NetPractice** is a networking project from the 42 Common Core designed to teach the fundamentals of **TCP/IP networking**.

Unlike programming projects, NetPractice focuses on **analyzing and configuring network topologies**.  
The goal is to correctly configure **IP addresses, subnet masks, and routing information** so that all devices in a network can communicate with each other.

Through a series of progressively more complex exercises, students learn how **hosts, routers, and networks interact**, and how incorrect configurations can prevent communication.

This project builds a strong foundation in:

- IPv4 addressing
- subnetting
- routing
- gateways
- network troubleshooting

---

## ⚙️ How It Works

NetPractice consists of several **interactive networking exercises**.

Each exercise presents a **network diagram** containing multiple devices such as:

- hosts
- routers
- network interfaces

Some configuration parameters are intentionally missing or incorrect.  
The objective is to analyze the topology and fix the configuration so that **all hosts in the network can communicate successfully**.

Typical configuration tasks include:

- assigning correct IP addresses
- selecting appropriate subnet masks
- configuring default gateways
- ensuring proper routing between networks

When the configuration is correct, the system validates the solution.

---

## 🚀 Usage

1. Open the NetPractice project in the **42 intra platform**.

2. Select a level.

3. Analyze the network diagram.

4. Configure the missing or incorrect values:

- IP addresses
- subnet masks
- gateways

5. Validate the configuration.

If all devices can communicate correctly, the level is completed.

---

## 🧠 Networking Concepts Learned

### IPv4 Addressing

Each device in a network must have a unique **IP address**.

Example:

```bash
192.168.1.10
```

An IPv4 address contains **32 bits divided into four octets**.

---

### Subnet Masks

A subnet mask determines which part of an IP address identifies the **network** and which part identifies the **host**.

Example:
```bash
IP Address : 192.168.1.10
Subnet Mask: 255.255.255.0
```

Network range:
```bash
192.168.1.0 – 192.168.1.255
```

---

### Default Gateway

The **default gateway** is the router used to communicate with other networks.

Example configuration:
```bash
Host IP: 192.168.1.10
Subnet Mask: 255.255.255.0
Gateway: 192.168.1.1
```

---

### Routing

Routers use **routing tables** to decide where to forward packets between networks.

Example route:
```bash
Destination: 10.0.0.0
Mask: 255.255.255.0
Gateway: 192.168.1.1
```

---

## 🎯 Learning Outcomes

Through this project I learned:

* the fundamentals of **TCP/IP networking**
* how IPv4 addressing and subnetting work
* how routers connect different networks
* how packets travel between hosts
* how to troubleshoot network connectivity issues
* how incorrect configurations break communication

These concepts are fundamental for understanding:

- system administration
- backend infrastructure
- DevOps environments
- distributed systems
- network security

---

## 📂 Project Structure
```text
.
├── netpractice/
│ ├── level1
│ ├── level2
│ ├── level3
│ └── ...
└── en.subject.pdf
```

# 🇮🇹 Italiano

## 📖 Informazioni sul Progetto

**NetPractice** è un progetto di networking del **42 Common Core** progettato per insegnare i fondamenti del **networking TCP/IP**.

A differenza dei progetti di programmazione, NetPractice si concentra sull’**analisi e configurazione delle topologie di rete**.  
L'obiettivo è configurare correttamente **indirizzi IP, subnet mask e informazioni di routing** affinché tutti i dispositivi nella rete possano comunicare tra loro.

Attraverso una serie di esercizi progressivamente più complessi, gli studenti imparano come **host, router e reti interagiscono**, e come configurazioni errate possano impedire la comunicazione.

Questo progetto costruisce una solida base in:

- indirizzamento IPv4
- subnetting
- routing
- gateway
- risoluzione dei problemi di rete

---

## ⚙️ Come Funziona

NetPractice consiste in diversi **esercizi interattivi di networking**.

Ogni esercizio presenta un **diagramma di rete** che contiene diversi dispositivi, come:

- host
- router
- interfacce di rete

Alcuni parametri di configurazione sono intenzionalmente mancanti o errati.  
L’obiettivo è analizzare la topologia e correggere la configurazione affinché **tutti gli host nella rete possano comunicare correttamente tra loro**.

Le attività di configurazione tipiche includono:

- assegnare indirizzi IP corretti
- selezionare subnet mask appropriate
- configurare i gateway predefiniti
- assicurare un corretto routing tra le reti

Quando la configurazione è corretta, il sistema convalida la soluzione.

---

## 🚀 Utilizzo

1. Apri il progetto NetPractice nella **piattaforma intra 42**.

2. Seleziona un livello.

3. Analizza il diagramma di rete.

4. Configura i valori mancanti o errati:

- indirizzi IP
- subnet mask
- gateway

5. Convalida la configurazione.

Se tutti i dispositivi possono comunicare correttamente, il livello è completato.

---

## 🧠 Concetti di Networking Apprendibili

### Indirizzamento IPv4

Ogni dispositivo in una rete deve avere un **indirizzo IP** unico.

Esempio:

```bash
192.168.1.10
```

Un indirizzo IPv4 contiene **32 bit divisi in quattro ottetti**.

---

### Subnet Mask

Una subnet mask determina quale parte di un indirizzo IP identifica la **rete** e quale parte identifica l’**host**.

Esempio:
```bash
Indirizzo IP : 192.168.1.10
Subnet Mask   : 255.255.255.0
```

Range di rete:
```bash
192.168.1.0 – 192.168.1.255
```

---

### Gateway Predefinito

Il **gateway predefinito** è il router utilizzato per comunicare con altre reti.

Esempio di configurazione:
```bash
IP Host     : 192.168.1.10
Subnet Mask : 255.255.255.0
Gateway     : 192.168.1.1
```

---

### Routing

I router utilizzano le **tabelle di routing** per decidere dove instradare i pacchetti tra le reti.

Esempio di rotta:
```bash
Destinazione: 10.0.0.0
Mask        : 255.255.255.0
Gateway     : 192.168.1.1
```

---

## 🎯 Risultati dell'Apprendimento

Attraverso questo progetto ho appreso:

* i fondamenti del **networking TCP/IP**
* come funzionano l’indirizzamento IPv4 e il subnetting
* come i router collegano reti diverse
* come i pacchetti viaggiano tra gli host
* come risolvere problemi di connettività di rete
* come configurazioni errate interrompono la comunicazione

Questi concetti sono fondamentali per comprendere:

- amministrazione di sistema
- infrastrutture backend
- ambienti DevOps
- sistemi distribuiti
- sicurezza di rete

---

## 📂 Struttura del Progetto
```text
.
├── netpractice/
│ ├── level1
│ ├── level2
│ ├── level3
│ └── ...
└── en.subject.pdf
```