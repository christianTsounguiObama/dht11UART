# Interface UART du DHT11 avec l’ATmega2560 (C Bare-Metal)

Un projet en langage C bare-metal pour interfacer un **capteur de température et d’humidité DHT11** avec un **ATmega2560 (Arduino Mega)** et envoyer les mesures via **UART**.

## Structure du projet
dht11_ws/ ├── include/ # Fichiers d'en-tête (headers) 
		  │ ├── dht11.h 
	      │ ├── uart.h 
		  │ └── gpio.h 
          ├── drivers/ # Fichiers source pour les pilotes bas-niveau 
          │ ├── dht11/dht11.c 
	      │ ├── uart/uart.c
		  │ └── gpio/gpio.c
		  ├── main/ # Logique principale de l’application 
          │ └── main.c 
		  ├── build/ # Fichiers compilés (ignorés par Git) 
		  ├── Makefile # Système de compilation 
		  └── .gitignore
## Fonctionnalités

- Lecture de la température et de l’humidité à partir du capteur DHT11
- Transmission des données via UART (9600 bauds)
- Code entièrement registres (sans bibliothèques Arduino)
- Structure modulaire des pilotes

## Prérequis

- **Matériel** : Arduino Mega 2560, capteur DHT11
- **Outils** :
  - `avr-gcc`
  - `avrdude`
- **Système** : Linux (testé sous Ubuntu 20.04+)

## Démarrage rapide

### 1. Cloner le dépôt

```bash
git clone https://github.com/christianTsounguiObama/dht11UART.git
cd dht11UART/dht11_ws
```

### 2. Compiler le projet
```bash
make
```

### 3. Flasher le fichier binaire
Assurez-vous que votre carte est connectée via USB et ajustez PORT dans le Makefile si nécessaire.
```bash
make flash
```

### 4. Lire les données sur le port série
Utilisez un outil comme screen :
```bash
screen /dev/ttyUSB0 9600
```

## Licence
Ce projet est open source et disponible sous la Licence MIT.

### Contribuer
Les contributions sont les bienvenues. Si vous trouvez des problèmes, n’hésitez pas à ouvrir une issue ou à proposer des améliorations.

### Remerciements
Ce projet fait partie de mon initiative pour te montrer comment construire des systèmes embarqués à partir de zéro au travers de projets 
dont le niveau de difficulté augmente progressivement.





