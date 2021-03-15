#!/bin/bash

set -e
BASEDIR=$(dirname "$0")

if [[ $1 == "-b" ]]; then
  $BASEDIR/build.sh
fi

$BASEDIR/../tests/tests