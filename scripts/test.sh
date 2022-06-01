#!/bin/bash

set -e
BASEDIR=$(dirname "$0")

if [[ $1 == "-no-build" ]] || [[ $2 == "-no-build" ]]; then
    "$BASEDIR"/../tests/tests
else
    "$BASEDIR"/build.sh
    "$BASEDIR"/../tests/tests
fi

if [[ $1 == "-cobertura" ]] || [[ $2 == "-cobertura" ]]; then
    make gcov && make lcov
fi
