#!/bin/bash

set -e

BASEDIR=$(dirname "$0")

cmake $BASEDIR/../
make -C $BASEDIR/../
