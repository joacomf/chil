#!/bin/sh
echo "Instalando Doxygen"
sudo apt-get install -y doxygen

echo 'Generando documentación con Doxygen'
set -e
doxygen ./documentacion/configuracion
cp ./documentacion/.nojekyll ./documentacion/html