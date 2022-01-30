#!/bin/bash

set -e

BASEDIR=$(dirname "$0")
CARPETA="$BASEDIR/../"

# Si recibe el flag -c hace una limpieza antes
if [[ $1 == "-c" ]] || [[ $2 == "-c" ]]; then
  cmake --build "$CARPETA" --target clean
fi

# Si recibe el flag -t incluye el modulo de pruebas, sino simplemente hace el build
if [[ $1 == "-t" ]] || [[ $2 == "-t" ]]; then
  cmake "$CARPETA" -DBUILD_TESTING:bool=true
else
  cmake "$CARPETA"
fi

make -C "$CARPETA"