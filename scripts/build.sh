#!/bin/bash

set -e

BASEDIR=$(dirname "$0")



if [[ $1 == "-t" ]]; then
  cmake $BASEDIR/../ -DBUILD_TESTING:bool=true
else
  cmake $BASEDIR/../
fi


make -C $BASEDIR/../