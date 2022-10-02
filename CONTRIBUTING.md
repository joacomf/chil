# Contribución
## Entorno
### IDE
Un IDE recomendado para el desarollo es [VSCode](https://code.visualstudio.com/).
También puede utilizarse [CLion](https://www.jetbrains.com/es-es/clion/) (No libre).

Al importarlo utilizando la herramienta de [PlatformIO](https://platformio.org/), la misma se encargará de descargar las líbrerias necesarias.

### Herramientas
El proyecto fue desarrollado en un ambiente con sistema operativo con base linux.
Para compilar y ejecutar las pruebas del proyecto, se necesita tener las siguientes librerías:
- cmake
- build-essentials

Para ello en un entorno con base Debian (Ubuntu, LinuxMint, etc):
```sh
$ sudo apt install cmake build-essentials
```

### Construcción
Para construir el proyecto, se podrá ejecutar el script
```sh
./scripts/build.sh
```
El mismo se encarga de limpiar el entorno y ejecutar los pasos necesarios para que la construcción sea exitosa.
Este script se encargará de instalar las librerías necesarias para ejecutar las pruebas de:
* [GTEST](https://github.com/google/googletest) - GoogleTest, librería de pruebas para C++ de Google

Para correr los tests es necesario ejecutar el script
```sh
./scripts/test.sh
```

