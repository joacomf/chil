# CHIL - C++ hardware-in-the-loop testing 
[![Pipeline](https://github.com/joacomf/chil/actions/workflows/pipeline.yml/badge.svg?branch=master)](https://github.com/joacomf/chil/actions/workflows/pipeline.yml) [![PlatformIO Registry](https://badges.registry.platformio.org/packages/joacomf/library/Chil.svg)](https://registry.platformio.org/libraries/joacomf/Chil)

Framework para escribir pruebas utilizando un dispositivo físico como ejecutor.

## Tabla de contenido
- [Chil](#chil---c-hardware-in-the-loop-testing)
    - [Tabla de contenidos](#tabla-de-contenido)
    - [Motivación](#motivacin)
    - [Usos](#usos)
    - [Modo de uso](#modo-de-uso)
      - [Creación del proyecto](#creacin-del-proyecto)
      - [Creación del contexto de pruebas](#creacin-del-contexto-de-pruebas)
      - [Definición de escenarios](#definicin-de-escenarios)
    - [Contribución](#contribucin)
      - [Entorno](#entorno)
        - [IDE](#ide)
        - [Herramientas](#herramientas)
      - [Constucción](#construccin)

## Motivación

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

## Modo de uso
Se pueden encontrar algunos ejemplos de uso completos con proyectos de muestra en la [carpeta de ejemplos](./ejemplos)

### Creación del proyecto

### Creación del contexto de pruebas
Para poder comenzar a escribir casos de prueba/ejemplos/escenarios de comportamiento,
primero se debe configurar la herramienta para tener el contexto de ejecución listo

Para ello en el archivo `main.cpp` del proyecto de pruebas
```c++
#include <PlataformaESP.h>
#include <Chil.h>

PRUEBAS;

    NUEVO_CHIL_CON(PLATAFORMA_ESP);
    // Definir la entrada/salida del dispositivo
    
    // Aquí va la sección de 
    // escenarios detallada más adelante

    FIN_DE_PRUEBAS;

FIN;
```

### Definición de escenarios
Para definir los casos de pruebas existen dos macros que ayudan a definir los mismos.

La primer macro `ESCENARIO` permite definir el ejemplo concreto/comportamiento de uso del dispositivo.

Luego cada Escenario contiene multiples `PASO` en donde se define una acción concreta para llevar una parte de la representación de ese ejemplo.

Tomando el [ejemplo de los LEDs](./ejemplos/leds) podemos definir un escenario como el siguiente:
```
1. Al presionar por primera vez el botón enciende el led
    - Cuando presiono el botón
    - Espero que encienda
    - Verifico que el led se enciende
    - Suelto el botón
```

Utilizando las herramientas brindadas por Chil, ese escenario puede definirse:
```c++
    ESCENARIO(Al presionar por primera vez el boton enciende el led){
        PASO(Cuando presiono el boton, []() {
            PLATAFORMA->escribir(BOTON_ROJO, 1);
        });
        PASO(Y espero que encienda, []() {
            PLATAFORMA->demorar(25);
        });
        PASO(Verifico que el led se enciende, []() {
            verificar(PLATAFORMA->leer(LED_AZUL))->esIgualA(1);
            // Es similar a `return PLATAFORMA->leer(LED_AZUL) == 1;`
        });
        PASO(Suelto el boton, []() {
            PLATAFORMA->escribir(BOTON_ROJO, 0);
        });
    };
```
Otra manera de definir los escenarios puede ser referenciando a una función, esta aproximación es convieniente cuando se quiere separar la implementación de la definición de los escenarios para poder tener una lectura más clara de estos últimos. Utilizando el mismo ejemplo anterior:

```c++
    void presionoElBotonRojo() {
        PLATAFORMA->escribir(BOTON_ROJO, 1);
    }

    void esperoQueEncienda() {
        PLATAFORMA->demorar(25);
    }

    void verificoQueElLedEsteEncendido() {
        verificar(PLATAFORMA->leer(LED_AZUL))->esIgualA(1);
        // Es similar a tener un método boolean con `return PLATAFORMA->leer(LED_AZUL) == 1;`
    }

    void sueltoElBotonRojo() {
        PLATAFORMA->escribir(BOTON_ROJO, 0);
    }

    ESCENARIO(Al presionar por primera vez el boton enciende el led){
        PASO(Cuando presiono el boton, presionoElBotonRojo);
        PASO(Y espero que encienda, esperoQueEncienda);
        PASO(Verifico que el led se enciende, verificoQueElLedEsteEncendido);
        PASO(Suelto el botón, sueltoElBotonRojo);
    };
```

Como se puede observar en los ejemplos anteriores se hace uso de el método `verificar()` el cual pertenece una librería de verificaciones ofrecida por `Chil` se explicará con detalle en la sección [librería de verificación](#librera-de-verificacin).

## Librería de verificación
Para facilitar la verificación de valores obtenidos, se propuso una librería al estilo de AssertJ, la cual tiene una nómina limitada de métodos para comparar.

Tiene dos modos de comparación. Una es sobre un valor existente

Para su utilización se invoca el método `verificar(valor)` siendo `valor` el dato en cuestión y luego se puede llamar a cualquiera de los métodos de la siguiente lista:

- `esVerdadero()`: Corrobora si el valor es verdadero
- `esFalso()`: Corrobora si el valor es falso
- `esIgualA(Tipo valorEsperado)`: Corrobora si el valor es igual al esperado
- `esMayorA(Tipo valorConElCualComparar)`: Corrobora si el valor es mayor
- `esMenorA(Tipo valorConElCualComparar)`: Corrobora si el valor es menor
- `esMayorOIgualA(Tipo valorConElCualComparar)`: Corrobora si el valor es mayor o igual al indicado
- `esMenorOIgualA(Tipo valorConElCualComparar)`: Corrobora si el valor es menor o igual al indicado
- `entre(Tipo valorInferior, Tipo valorSuperior)`: Corrobora si el valor a verificar esta entre dos valores dados [incluidos]


## Contribución
### Entorno
#### IDE
Un IDE recomendado para el desarollo es [VSCode](https://code.visualstudio.com/). 
También puede utilizarse [CLion](https://www.jetbrains.com/es-es/clion/) (No libre).

Al importarlo utilizando la herramienta de [PlatformIO](https://platformio.org/), la misma se encargará de descargar las líbrerias necesarias.

#### Herramientas
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