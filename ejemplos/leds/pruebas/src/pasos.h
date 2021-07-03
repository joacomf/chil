#ifndef PRUEBAS_PASOS_H
#define PRUEBAS_PASOS_H

#include <Chil.h>

#define BOTON_ROJO 4
#define LED_AZUL 2

bool presionoElBoton();
bool sueltoElBoton();
bool elLedEstaEncendido();
bool elLedEstaApagado();
bool espero25Milis();
void configurarIO();

#endif //PRUEBAS_PASOS_H
