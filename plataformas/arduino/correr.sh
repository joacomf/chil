#!/bin/bash
pio update && \
pio platform install espressif32 && \
pio lib update && \
sed '/TestRunner summary/q' <(exec platformio test -e esp32dev) && kill -9 $!