#!/bin/bash

set -e
BASEDIR=$(dirname "$0")

if [[ $1 == "-nb" ]]; then
  "$BASEDIR"/../tests/tests
else
  "$BASEDIR"/build.sh
  "$BASEDIR"/../tests/tests
fi