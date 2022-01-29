# Chil CLI

Herramienta de cliente para poder correr CHIL y generar el reporte automáticamente

## Instalación
Para instalar se puede ejecutar el comando:
``` bash
wget -O /tmp/chil https://raw.githubusercontent.com/joacomf/chil/master/herramientas/chil && chmod +x /tmp/chil && sudo /tmp/chil instalar
```

## Uso
Una vez instalado se puede inicializar la herramienta en el directorio que se desee

Para ello es necesario ejecutar
``` bash
chil iniciar
```

Este comando crea el archivo `.chil` en el directorio donde se ejecutó, con el siguiente contenido
```
[comando]
# Aca va el comando que sube y ejecuta el programa
```

En la línea siguiente a `[comando]` es donde se debe especificar el comando que subirá las pruebas al dispositivo

Por ejemplo, si se utiliza la herramienta [platformio](https://docs.platformio.org/en/latest/core/index.html) y el dispositivo es un ESP32 el archivo se verá de la siguiente manera:
```
[comando]
pio run -e esp32dev
```

Una vez configurado el archivo ya se puede correr el comando 
```
chil correr
```

Este comando ejecutará la instrucción definida y al terminar la ejecución de todas las pruebas cuando dispositivo imprima el reporte en formato JSON se tomará ese contenido y se generará un carpeta `/reporte` el archivo `reporte.html` con el resultado con un formato amigable para el usuario final. 

Adicionalmente, se dejará el resultado en formato json en `reporte/reporte.json`

## TL;DR 
Instalar con las instrucciones en [Instalación](#instalación) y luego:

``` bash
# En la carpeta del proyecto de pruebas
chil iniciar
# Completar comando en archivo .chil generado
chil correr
# Se abre el reporte o abrirlo manualmente en reporte/reporte.html
```

