//
// Created by jmorenof on 12/3/21.
//
#ifndef CHIL_MOCKFRAMEWORK_HPP
#define CHIL_MOCKFRAMEWORK_HPP

#include "plataforma/Plataforma.h"
#include "gmock/gmock.h"

class MockFramework : public Plataforma{

  public:
    MOCK_METHOD(void, consola, (const char *nombre), (override));
    MOCK_METHOD(unsigned long, microsegundos, (), (override));
    MOCK_METHOD(unsigned long, milisegundos, (), (override));
    MOCK_METHOD(void, escribir, (int pin, int valor), (override));
    MOCK_METHOD(int, leer, (int pin), (override));
    MOCK_METHOD(void, demorar, (int milisegundos), (override));
    MOCK_METHOD(void, pinSalida, (int pin), (override));
    MOCK_METHOD(bool, crearRedWiFi, (const char *nombre, const char *clave), (override));
    MOCK_METHOD(bool, estaAPEncendido, (), (override));
    MOCK_METHOD(bool, apagarWiFi, (), (override));
};

#endif //CHIL_MOCKFRAMEWORK_HPP
