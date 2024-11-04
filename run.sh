#!/bin/bash
# Compila el archivo actual y lo ejecuta en la terminal principal

# Cambia al directorio del archivo .cpp
cd "$(dirname "$1")"

# Compila el archivo .cpp
g++ -std=c++17 "$1" -o a.out

# Ejecuta el programa
./a.out
