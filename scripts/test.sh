#!/bin/bash

set -e
BASEDIR=$(dirname "$0")

if [[ $1 == "-nb" ]]; then
  $BASEDIR/../tests/tests --gtest_output=xml:reporte/xunit.xml
else
  $BASEDIR/build.sh
  $BASEDIR/../tests/tests --gtest_output=xml:reporte/xunit.xml
fi