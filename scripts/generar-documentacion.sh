#!/bin/sh
sudo apt-get update && sudo apt-get install -y doxygen
echo "Instalando Doxygen"

echo 'Generando documentación con Doxygen'
set -e
doxygen ./documentacion/configuracion
cp ./documentacion/.nojekyll ./documentacion/html
mv ./documentacion/html ./documentacion/docs