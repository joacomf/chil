#!/bin/sh
echo 'Generando documentación con Doxygen'
set -e
sudo apt-get install -y doxygen
doxygen ./configuracion/documentacion
