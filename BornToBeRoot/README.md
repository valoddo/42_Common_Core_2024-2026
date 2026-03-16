# 🖥️ Born2BeRoot
![42](https://img.shields.io/badge/school-42-black)

This project has been created as part of the 42 Common Core.

---
# 🇬🇧 English

## 📖 Description
Born2BeRoot is a project designed to teach students the fundamentals of system administration and server setup. The main goal is to configure a Linux server (Debian or Rocky) from scratch, following strict security and configuration requirements. Students learn to manage users, partitions, services, firewalls, and implement a monitoring script, all without a graphical interface.

Key objectives include:

- Install a minimal Linux server (Debian or Rocky) without GUI.
- Configure encrypted partitions using LVM.
- Set up a strong password policy.
- Configure sudo with strict rules.
- Set up SSH on port 4242 without root login.
- Configure firewall (UFW for Debian, firewalld for Rocky) and leave only port 4242 open.
- Implement a monitoring script (monitoring.sh) displaying system status.

This project emphasizes understanding Linux services, security policies, system monitoring, and best practices for server administration.

### Operating System Choice
Debian is recommended for beginners due to simplicity and wide documentation. Rocky Linux provides enterprise-level tools and SELinux management but is more complex to configure.

**Comparison:**
- Debian vs Rocky Linux: Debian is easier for newcomers, Rocky is closer to enterprise environments.
- AppArmor (Debian) vs SELinux (Rocky): Both enforce security policies; AppArmor is simpler, SELinux is more flexible.
- UFW vs firewalld: Both manage firewall rules; firewalld is used in Rocky, UFW in Debian.
- VirtualBox vs UTM: VirtualBox is widely used, UTM supports M1 Macs.

---

## ⚙️ Instructions
### Compilation / Setup
1. Install your chosen OS on a VM (VirtualBox or UTM).
2. Create at least two encrypted partitions using LVM.
3. Configure the hostname to your login ending with 42.
4. Create a user with your login, belonging to `user42` and `sudo` groups.
5. Configure SSH on port 4242 and disable root login.
6. Set up firewall (UFW/firewalld) allowing only port 4242.
7. Configure strong password policies:
   - Password expires every 30 days.
   - Minimum 2 days between changes.
   - 7-day warning before expiration.
   - Minimum 10 characters with uppercase, lowercase, number.
   - No more than 3 consecutive identical characters.
   - Must not contain username.
8. Configure sudo with:
   - Maximum 3 authentication attempts.
   - Custom error message for failed attempts.
   - Logging of all commands in `/var/log/sudo/`.
   - Restricted TTY and paths.
9. Create `monitoring.sh` script to display:
   - OS architecture and kernel version.
   - Number of physical and virtual CPUs.
   - RAM usage and percentage.
   - Disk usage and percentage.
   - CPU load percentage.
   - Last reboot date and time.
   - LVM status.
   - Active TCP connections.
   - Logged users.
   - Server IP and MAC address.
   - Number of sudo commands executed.

### Usage
Run the monitoring script every 10 minutes using `cron` or `watch`.

---

## 📚 Resources
- Debian and Rocky Linux official documentation
- SSH, UFW, firewalld, LVM, and sudo manuals
- Bash scripting tutorials for `monitoring.sh`

---

## 💡 Notes
- No graphical environment allowed (X.org, Wayland, etc.).
- Snapshots are restricted; defense starts without snapshots.
- Only `README.md` and `signature.txt` must be submitted.
- Signature.txt contains the SHA1 of the VM disk.
- Bonus features (optional) include setting up WordPress or other services after mandatory tasks are perfectly completed.

---

# 🇮🇹 Italiano

## 📖 Descrizione

Born2BeRoot è un progetto progettato per insegnare agli studenti le basi dell'amministrazione di sistema e della configurazione di un server. L'obiettivo principale è configurare un server Linux (Debian o Rocky) da zero, seguendo rigidi requisiti di sicurezza e configurazione. Gli studenti imparano a gestire utenti, partizioni, servizi, firewall e a implementare uno script di monitoraggio, tutto senza interfaccia grafica.

Gli obiettivi principali includono:

* Installare un server Linux minimale (Debian o Rocky) senza GUI.
* Configurare partizioni criptate usando LVM.
* Impostare una politica di password sicura.
* Configurare sudo con regole rigide.
* Configurare SSH sulla porta 4242 senza login root.
* Configurare il firewall (UFW per Debian, firewalld per Rocky) lasciando aperta solo la porta 4242.
* Implementare uno script di monitoraggio (monitoring.sh) che visualizzi lo stato del sistema.

Questo progetto enfatizza la comprensione dei servizi Linux, delle politiche di sicurezza, del monitoraggio del sistema e delle migliori pratiche per l'amministrazione dei server.

### Scelta del Sistema Operativo

Debian è consigliato ai principianti per la sua semplicità e la vasta documentazione. Rocky Linux fornisce strumenti di livello enterprise e gestione SELinux, ma è più complesso da configurare.

**Confronto:**

* Debian vs Rocky Linux: Debian è più facile per i principianti, Rocky è più vicino agli ambienti enterprise.
* AppArmor (Debian) vs SELinux (Rocky): Entrambi applicano politiche di sicurezza; AppArmor è più semplice, SELinux più flessibile.
* UFW vs firewalld: Entrambi gestiscono le regole del firewall; firewalld è usato in Rocky, UFW in Debian.
* VirtualBox vs UTM: VirtualBox è ampiamente utilizzato, UTM supporta i Mac M1.

---

## ⚙️ Istruzioni

### Compilazione / Configurazione

1. Installa il sistema operativo scelto su una VM (VirtualBox o UTM).
2. Crea almeno due partizioni criptate usando LVM.
3. Configura l'hostname con il tuo login terminante con 42.
4. Crea un utente con il tuo login, appartenente ai gruppi `user42` e `sudo`.
5. Configura SSH sulla porta 4242 e disabilita il login root.
6. Configura il firewall (UFW/firewalld) consentendo solo la porta 4242.
7. Configura una politica di password forte:

   * La password scade ogni 30 giorni.
   * Minimo 2 giorni tra un cambio e l'altro.
   * Avviso 7 giorni prima della scadenza.
   * Minimo 10 caratteri con lettere maiuscole, minuscole e numeri.
   * Non più di 3 caratteri identici consecutivi.
   * Non deve contenere il nome utente.
8. Configura sudo con:

   * Massimo 3 tentativi di autenticazione.
   * Messaggio di errore personalizzato per i tentativi falliti.
   * Registrazione di tutti i comandi in `/var/log/sudo/`.
   * TTY e percorsi limitati.
9. Crea lo script `monitoring.sh` per visualizzare:

   * Architettura del sistema operativo e versione del kernel.
   * Numero di CPU fisiche e virtuali.
   * Utilizzo della RAM e percentuale.
   * Utilizzo del disco e percentuale.
   * Percentuale di carico della CPU.
   * Data e ora dell'ultimo riavvio.
   * Stato LVM.
   * Connessioni TCP attive.
   * Utenti loggati.
   * Indirizzo IP e MAC del server.
   * Numero di comandi eseguiti con sudo.

### Utilizzo

Esegui lo script di monitoraggio ogni 10 minuti usando `cron` o `watch`.

---
## 📚 Risorse

* Documentazione ufficiale di Debian e Rocky Linux
* Manuali di SSH, UFW, firewalld, LVM e sudo
* Tutorial di scripting Bash per `monitoring.sh`

---

## 💡 Note

* Non è consentito alcun ambiente grafico (X.org, Wayland, ecc.).
* Gli snapshot sono limitati; la difesa inizia senza snapshot.
* Devono essere inviati solo `README.md` e `signature.txt`.
* Il file signature.txt contiene l'SHA1 del disco della VM.
* Le funzionalità bonus (opzionali) includono la configurazione di WordPress o altri servizi dopo che le attività obbligatorie sono state completate perfettamente.

