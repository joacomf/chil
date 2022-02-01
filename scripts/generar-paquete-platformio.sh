#!/bin/bash

set -e

echo -e "\e[33mGenerando paquete\e[39m"
pio package pack .
echo -e "\xE2\x9C\x94 Listo"

echo -e "\e[33mListando directorio\e[39m"
ls -l

echo -e "\e[33mAutorizando platformio\e[39m"
pio account token -p "$1"
echo -e "\xE2\x9C\x94 Listo"

echo -e "\e[33mPublicando paquete\e[39m"
pio package publish
echo -e "\xE2\x9C\x94 Listo"

