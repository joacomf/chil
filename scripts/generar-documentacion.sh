#!/bin/sh
echo 'Configurando el proyecto'
set -e

echo 'Generando documentación con Doxygen'
doxygen ./configuracion/documentacion 2>&1 | tee doxygen.log

mkdir documentacion
cd documentacion


echo "" > .nojekyll

echo 'Generando documentación con Doxygen'
doxygen ../../configuracion/documentacion 2>&1 | tee doxygen.log
