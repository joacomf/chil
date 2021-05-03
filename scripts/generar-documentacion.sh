#!/bin/sh
echo 'Generando documentación con Doxygen'
set -e
doxygen ./documentacion/configuracion
cp documentacion/.nojekyll documentacion/html