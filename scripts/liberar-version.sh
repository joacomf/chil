BASEDIR=$(dirname "$0")
TIPO_VERSION="$1"

echo -e "\e[33mAumentando versión...\e[39m"
"$BASEDIR"/versionar.sh "$TIPO_VERSION"
echo -e "\xE2\x9C\x94 Listo"

VERSION=$(cat "$BASEDIR/../version")

echo -e "\e[33mEstado de git\e[39m"
git status

echo -e  "\e[33mConfigurando usuario Pipeline\e[39m"
git config user.name "CD Pipeline"
git config user.email "<>"
echo -e "\xE2\x9C\x94 Listo"

echo -e "\e[33mGenerando tag con version ${VERSION}\e[39m"
git add version
git commit -m "Generando version ${VERSION}"
git tag -m "${VERSION}" "${VERSION}"
git push
git push --tags
echo -e "\xE2\x9C\x94 Subido"
