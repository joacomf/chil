#include "../src/PlataformaArduino.cpp"
#include <AUnit.h>

#include <utility>
#include "../../modelos/PuntoDeEntrada.cpp"

using namespace aunit;

PlataformaArduino *framework = new PlataformaArduino();
int led = 2;

void setup() {}

test(deberiaEncenderElLedIndicado) {
  framework->pinSalida(led);
  framework->escribir(led, HIGH);

  assertEqual(framework->leer(led), HIGH);
}

test(deberiaObtenerElTiempoEnMicrosegundos) {
  unsigned long cero = 0;

  unsigned long primeraMedicion = framework->microsegundos();
  unsigned long segundaMedicion = framework->microsegundos();

  assertMore(primeraMedicion, cero);
  framework->demorar(1);
  assertMoreOrEqual(segundaMedicion, primeraMedicion);
}

test(deberiaObtenerElTiempoUtilizandoMilisegundos) {
  unsigned long cero = 0;

  unsigned long primeraMedicion = framework->milisegundos();
  framework->demorar(10);
  unsigned long segundaMedicion = framework->milisegundos();

  assertMore(primeraMedicion, cero);
  assertMore(segundaMedicion, primeraMedicion);
}

test(deberiaDemorar100milisegundosEntreLasMediciones) {
  long tiempoDeDemora = 100;

  unsigned long primeraMedicion = framework->milisegundos();
  framework->demorar(tiempoDeDemora);
  unsigned long segundaMedicion = framework->milisegundos();

  unsigned long diferenciaDeTiempo = segundaMedicion - primeraMedicion;

  assertMoreOrEqual(diferenciaDeTiempo, (unsigned long) tiempoDeDemora);
}

test(deberiaImprimirPorConsola) {
  framework->consola("Verificacion manual: Deberia imprimir este texto por consola");
}

test(WiFi, deberiaEstarEncendidaLaRedWiFiAPLuegoDeCrearla) {
  framework->crearRedWiFi("hola", "mundo12345");
  assertTrue(framework->estaAPEncendido());
  framework->apagarWiFi();
}

test(WiFi, aDeberiaEstarApagadoLaRedWiFIAPSiNuncaSeEncendio) {
  framework->apagarWiFi();
  framework->demorar(400);

  assertFalse(framework->estaAPEncendido());
}

static String dispositivoBaseUrl = "http://" + IPAddress(192, 168, 4, 1).toString();

class Respuesta {
public:
    int codigo;
    String contenido;
    Respuesta(int codigo, String contenido) {
        this->codigo = codigo;
        this->contenido = std::move(contenido);
    }
};

class ServidorWebTest: public TestOnce {
protected:
    void setup() override {
        TestOnce::setup();
        framework->crearRedWiFi("servidor", "http12345");
        framework->crearServidorWeb();
        framework->demorar(100);
    }

    void teardown() override {
        framework->apagarWiFi();
        framework->eliminarServidorWeb();
        TestOnce::teardown();
    }

    static Respuesta *alHacerPeticionGET(const char* camino) {
        HTTPClient cliente;
        cliente.begin(dispositivoBaseUrl + camino);

        int codigoDeRespuesta = cliente.GET();
        String contenido = cliente.getString();
        cliente.end();

        return new Respuesta(codigoDeRespuesta, contenido);
    }

    static Respuesta *alHacerPeticionPOST(const char *camino) {
        HTTPClient cliente;
        cliente.begin(dispositivoBaseUrl + camino);

        int codigoDeRespuesta = cliente.POST("");
        cliente.end();

        return new Respuesta(codigoDeRespuesta, "");
    }
};

test(aDeberiaNoTenerServidorWebCreadoPorDefault) {
    assertFalse(framework->estaServidorCorriendo());
}

testF(ServidorWebTest, aDeberiaCrearUnServidorWeb) {
    assertTrue(framework->estaServidorCorriendo());
}

testF(ServidorWebTest, aDeberiaEliminarServidorWebLuegoDeEncenderlo) {
    framework->eliminarServidorWeb();

    assertFalse(framework->estaServidorCorriendo());
}


testF(ServidorWebTest, deberiaCrearUnPuntoDeEntradaDePingAlCrearElServidorWeb) {
  Respuesta* respuesta = alHacerPeticionGET("/chil-ping");

  assertEqual(200, respuesta->codigo);
  assertEqual("chil-pong", respuesta->contenido);
}

testF(ServidorWebTest, deberiaAgregarPuntoDeEntradaAlServidorCreado) {
  auto* puntoDeEntrada = new PuntoDeEntrada("/numeros");
  puntoDeEntrada->configurarRespuesta("numeros", "text/plain");

  framework->configurarPuntoDeEntrada(puntoDeEntrada);

  Respuesta* respuesta = alHacerPeticionGET("/numeros");

  assertEqual(200, respuesta->codigo);
  assertEqual("numeros", respuesta->contenido);
}

testF(ServidorWebTest, deberiaAgregarPuntoDeEntradaParaMetodoPostAlServidorCreado) {
    auto* puntoDeEntrada = new PuntoDeEntrada("/ping", POST);

    framework->configurarPuntoDeEntrada(puntoDeEntrada);

    Respuesta* respuesta = alHacerPeticionPOST("/ping");

    assertEqual(200, respuesta->codigo);
}

void loop() {
  TestRunner::run();
}