#!/bin/bash
set -e

git clone -b gh-pages git@github.com:joacomf/chil.git

cp -r docs chil
cd chil

#git config --global push.default simple
#git config user.name "Github Actions"
#git config user.email "github_actions@github.com"

if [ -d "html" ] && [ -f "html/index.html" ]; then
    echo 'Subiendo contenido a Github Pages'
    #git add --all
    #git commit -m "Actualiza la documentación en Github Pages"

    # git push > /dev/null 2>&1
else
    echo '' >&2
    echo 'Advertencia: No hay documentación generada!' >&2
    echo 'Advertencia: No se va a subir a Github Pages!' >&2
    exit 1
fi