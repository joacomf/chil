#!/bin/sh
echo "Instalando Doxygen"
sudo apt-get update && sudo apt-get install -y doxygen doxygen-latex doxygen-doc doxygen-gui graphviz xapian-tools

echo 'Generando documentación con Doxygen'
set -e
doxygen ./documentacion/configuracion
cp ./documentacion/.nojekyll ./documentacion/html
mv ./documentacion/html ./documentacion/docs