#include "compartido-tests.h"

PlataformaMock *laPlataforma;

void dadoQueSePuedeEjecutar2PasosConChil();
void dadoQueSePuedeEjecutar4PasosConChil();

TEST(ExportadorJSON, exportaUnEscenarioConElUnicoPasoExitoso) {
    dadoQueSePuedeEjecutar2PasosConChil();

    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(Recibe comando en el pin 1, []() {});
    };

    string escenariosJSON = ExportadorJSON::generar();

    ASSERT_EQ(escenariosJSON, "{\"resumen\":{\"completados\":1,\"exitosos\":1,\"fallidos\":0},\"escenarios\":[{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":true,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"}]}]}");

    delete laPlataforma;
}

TEST(ExportadorJSON, exportaUnEscenarioConElUnPasoExitosoYUnPasoFallido) {
    dadoQueSePuedeEjecutar4PasosConChil();

    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(Recibe comando en el pin 1, []() {});
        PASO(No recibe comando en el pin 1, []() { verificar(false)->esVerdadero(); });
    };

    string escenariosJSON = ExportadorJSON::generar();

    ASSERT_EQ(escenariosJSON, "{\"resumen\":{\"completados\":1,\"exitosos\":0,\"fallidos\":1},\"escenarios\":[{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":false,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"},{\"nombre\":\"No recibe comando en el pin 1\",\"exitoso\":false,\"tiempo\":39,\"detalleDeError\":\"Se esperaba que el valor 0 sea igual a 1 pero no lo fue\"}]}]}");

    delete laPlataforma;
}

TEST(ExportadorJSON, exportaUnEscenarioDosEscenariosUnoFallidoYOtroExitoso) {
    dadoQueSePuedeEjecutar4PasosConChil();

    ESCENARIO(Recibe comando en pin 1 para pasar comando al pin 333) {
        PASO(Recibe comando en el pin 1, []() {});
    }
    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(No recibe comando en el pin 1, []() { verificar(false)->esVerdadero(); });
    };

    string escenariosJSON = ExportadorJSON::generar();

    ASSERT_EQ(escenariosJSON, "{\"resumen\":{\"completados\":2,\"exitosos\":1,\"fallidos\":1},\"escenarios\":[{\"nombre\":\"Recibe comando en pin 1 para pasar comando al pin 333\",\"exitoso\":true,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"}]},{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":false,\"pasos\":[{\"nombre\":\"No recibe comando en el pin 1\",\"exitoso\":false,\"tiempo\":39,\"detalleDeError\":\"Se esperaba que el valor 0 sea igual a 1 pero no lo fue\"}]}]}");

    delete laPlataforma;
}

TEST(ExportadorJSON, exportaUnEscenarioDosEscenariosUnoFallidoYOtroExitosoUtilizandoElMacro) {
    dadoQueSePuedeEjecutar4PasosConChil();

    EXPECT_CALL(*laPlataforma, consola(StrEq("COMIENZO_JSON"))).Times(1);
    EXPECT_CALL(*laPlataforma, consola(StrEq("{\"resumen\":{\"completados\":2,\"exitosos\":1,\"fallidos\":1},\"escenarios\":[{\"nombre\":\"Recibe comando en pin 1 para pasar comando al pin 333\",\"exitoso\":true,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"}]},{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":false,\"pasos\":[{\"nombre\":\"No recibe comando en el pin 1\",\"exitoso\":false,\"tiempo\":39,\"detalleDeError\":\"Se esperaba que el valor 0 sea igual a 1 pero no lo fue\"}]}]}"))).Times(1);
    EXPECT_CALL(*laPlataforma, consola(StrEq("FIN_JSON"))).Times(1);


    ESCENARIO(Recibe comando en pin 1 para pasar comando al pin 333) {
        PASO(Recibe comando en el pin 1, []() {});
    }
    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(No recibe comando en el pin 1, []() { verificar(false)->esVerdadero(); });
    };

    EXPORTAR_JSON;

    delete laPlataforma;
}


void dadoQueSePuedeEjecutar2PasosConChil(){
    laPlataforma = new PlataformaMock();
    EXPECT_CALL(*laPlataforma, consola(_)).Times(1);
    EXPECT_CALL(*laPlataforma, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(100L));

    NUEVO_CHIL_CON(laPlataforma);
}

void dadoQueSePuedeEjecutar4PasosConChil(){
    laPlataforma = new PlataformaMock();

    EXPECT_CALL(*laPlataforma, consola(_)).Times(1);
    EXPECT_CALL(*laPlataforma, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(100L))
            .WillOnce(Return(101L))
            .WillOnce(Return(140L));

    NUEVO_CHIL_CON(laPlataforma);
}