#!/bin/bash

set -e
BASEDIR=$(dirname "$0")

if [[ $1 == "-no-build" ]] || [[ $2 == "-no-build" ]] || [[ $3 == "-no-build" ]]; then
    "$BASEDIR"/../tests/tests
else
    "$BASEDIR"/build.sh
    "$BASEDIR"/../tests/tests
fi

if [[ $1 == "-cobertura" ]] || [[ $2 == "-cobertura" ]] || [[ $3 == "-cobertura" ]]; then
    make gcov && make lcov
fi

if [[ $1 == "-reporte" ]] || [[ $2 == "-reporte" ]] || [[ $3 == "-reporte" ]]; then
    make reporte
fi
