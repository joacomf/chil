#include <utilidades/exportador/ExportadorJSON.h>
#include "compartido-tests.h"

PlataformaMock *laPlataforma;
void dadoQueElFrameworkEstaFuncionando(){
    laPlataforma = new PlataformaMock();

    EXPECT_CALL(*laPlataforma, microsegundos())
            .WillOnce(Return(0L))
            .WillOnce(Return(100L));

    NUEVO_CHIL_CON(laPlataforma);
}

TEST(ExportadorJSON, exportaUnEscenarioConElUnicoPasoExitoso) {
    dadoQueElFrameworkEstaFuncionando();

    ESCENARIO(Deja de recibir comando en pin 1 para pasar comando al pin 12) {
        PASO(Recibe comando en el pin 1, []() {});
    };

    string escenariosJSON = ExportadorJSON::exportarEscenarios();

    ASSERT_EQ(escenariosJSON, "{\"resumen\":{\"completados\":1,\"exitosos\":1,\"fallidos\":0},\"escenarios\":[{\"nombre\":\"Deja de recibir comando en pin 1 para pasar comando al pin 12\",\"exitoso\":true,\"pasos\":[{\"nombre\":\"Recibe comando en el pin 1\",\"exitoso\":true,\"tiempo\":100,\"detalleDeError\":\"\"}]}]}");

    delete laPlataforma;
}