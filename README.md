# CHIL - C++ hardware-in-the-loop testing [![CMake](https://github.com/joacomf/chil/actions/workflows/pipeline.yml/badge.svg?branch=master)](https://github.com/joacomf/chil/actions/workflows/cmake.yml)

Framework para escribir pruebas utilizando un dispositivo físico como ejecutor.

La motivación original detrás de todo el proyecto fue la necesidad de crear una herramienta que sea habilitante para realizar prácticas con pruebas automatizadas (TDD, BDD, Integración Continua) al mundo de microcontroladores que está creciendo. 

Desde hace varios años, el mercado de microcontroladores fue mutando y por ende emergieron nuevas generaciones de procesadores con mayor espacio y mayor capacidad de cómputo que permite poner software de tamaño considerable (hasta MBs) lo que genera un crecimiento en la complejidad del mismo. 

Antes se programaban dispositivos con una cantidad limitada de condiciones lo que permitía verificar rápidamente de manera manual si cumplía con el funcionamiento adecuado. 

## Usos

Varios usos pueden ser interpretados de esta herramienta. Algunos ejemplos:
1. Usarlo como herramienta para guiar el desarrollo. Se puede usar en la práctica de BDD/ATDD para definir el comportamiento del producto y a partir realizar el desarrollo para que cumpla con esas especificaciones/comportamiento.
2. Se puede utilizar como herramienta para probar el desarrollo luego de haberlo realizado, de manera de dejar un arnés de seguridad para el código escrito
3. Otro uso puede ser armar una red de contención previo a una refactorización de código heredado. A partir de cómo se debería comportar el dispositivo, se escriben las pruebas y una vez que las mismas otorguen feedback adecuado se puede proceder a refactorizar el código.
4. Un uso menos común pero igual de válido es para explorar un producto a partir de lo que uno piensa que debería hacer, un ejemplo de este caso es la aplicación de ingeniería inversa si es que no se tiene el código del dispositivo aún o si el mismo es difícil de entender.
5. Cualquier otro propósito que ayude al procesos de construir algún producto

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

## Modo de uso

Al momento de escribir pruebas tenemos disponible la macro `ESCENARIO` y la macro `PASO` para que las pruebas queden
definidas de manera más clara. Por lo tanto podremos escribir:

```c++
Plataforma arduino = new PlataformaArduino();
Chil *chil = new Chil(arduino);

ESCENARIO(chil, "Primer escenario con un paso", [](Chil *chil){
    PASO(chil, "Imprime por consola el saludo de bienvenida", []() {
        arduino->consola("Hola mundo!");
        return true;
    });
});
```

Al ejecutarse los test saldrá por consola un reporte como el siguiente:

```
Escenario: Primer escenario con un paso
  [OK] Imprime por consola el saludo de bienvenida - ejecuto en 49 useg
```

