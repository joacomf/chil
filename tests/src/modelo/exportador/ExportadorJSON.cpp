#include <utilidades/exportador/ExportadorJSON.h>
#include "compartido-tests.h"

PlataformaMock *laPlataforma;
void dadoQueSePuedeEjecutar2PasosConChil(){
    laPlataforma = new PlataformaMock();

    EXPECT_CALL(*laPlataforma, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(100L));

    NUEVO_CHIL_CON(laPlataforma);
}

void dadoQueSePuedeEjecutar4PasosConChil(){
    laPlataforma = new PlataformaMock();

    EXPECT_CALL(*laPlataforma, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(100L))
            .WillOnce(Return(101L))
            .WillOnce(Return(140L));

    NUEVO_CHIL_CON(laPlataforma);
}

TEST(ExportadorJSON, exportaUnEscenarioConElUnicoPasoExitoso) {
    dadoQueSePuedeEjecutar2PasosConChil();

    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(Recibe comando en el pin 1, []() {});
    };

    string escenariosJSON = ExportadorJSON::exportarEscenarios();

    ASSERT_EQ(escenariosJSON, "{\"resumen\":{\"completados\":1,\"exitosos\":1,\"fallidos\":0},\"escenarios\":[{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":true,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"}]}]}");

    delete laPlataforma;
}

TEST(ExportadorJSON, exportaUnEscenarioConElUnPasoExitosoYUnPasoFallido) {
    dadoQueSePuedeEjecutar4PasosConChil();

    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(Recibe comando en el pin 1, []() {});
        PASO(No recibe comando en el pin 1, []() { verificar(false)->esVerdadero(); });
    };

    string escenariosJSON = ExportadorJSON::exportarEscenarios();

    ASSERT_EQ(escenariosJSON, "{\"resumen\":{\"completados\":1,\"exitosos\":0,\"fallidos\":1},\"escenarios\":[{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":false,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"},{\"nombre\":\"No recibe comando en el pin 1\",\"exitoso\":false,\"tiempo\":39,\"detalleDeError\":\"Se esperaba que el valor 0 sea igual a 1 pero no lo fue\"}]}]}");

    delete laPlataforma;
}