FROM python:3.9.0-slim

LABEL maintainer="Joaquin Moreno Fernandez <joaquinamf@gmail.com>"

RUN pip install -U platformio && \
    mkdir -p /workspace && \
    mkdir -p /.platformio && \
    chmod a+rwx /.platformio && \
    apt update && apt install -y git && apt-get clean autoclean && apt-get autoremove --yes && rm -rf /var/lib/{apt,dpkg,cache,log}/

USER 1001