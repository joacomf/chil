#include "AccionVerificable.h"
#include "modelo/verificacion/excepciones/AccionNoEjecutadaExcepcion.h"

/**
 * @brief
 * Constructor de AccionVerificable
 *
 * @details
 * Declara las acciones a realizar al crear un nuevo AccionVerificable.
 * La acción realizada es inicializar el campo AccionVerificable::accionAVerificar recibida por parámetro
 * para su ejecución en el sondeo
 *
 * @tparam bool (*laAccion)() - acción a verificar
 * @return [out][ValorVerificable<Tipo>*] objeto para realizar las comparaciones.
 */
AccionVerificable::AccionVerificable(bool (*laAccion)()) {
    this->accionAVerificar = laAccion;
}

/**
 * @brief
 * Configura el tiempo total del sondeo en milisegundos (ms)
 *
 * @details
 * Configura el tiempo total como tiempoLimite del sondeo en milisegundos (ms)
 * guardandolo en AccionVerificable::tiempoLimite
 *
 * @param int tiempoLimite en milisegundos
 * @return [out] AccionVerificable* - referencia al mismo objeto
 */
AccionVerificable* AccionVerificable::durante(int milisegundos) {
    this->tiempoLimite = milisegundos;
    return this;
}

/**
 * @brief
 * Configura el intervalo entre verificación y verificación del sondeo en milisegundos (ms)
 *
 * @details
 * Configura el intervalo entre verificación y verificación del sondeo en milisegundos (ms)
 * guardandolo en AccionVerificable::intervaloEnMilisegundos
 *
 * @param int intervalo en milisegundos
 * @return [out] AccionVerificable* - referencia al mismo objeto
 */
AccionVerificable* AccionVerificable::conIntervaloDe(int elIntervaloEnMilisegundos) {
    this->intervaloEnMilisegundos = elIntervaloEnMilisegundos;
    return this;
}

/**
 * @brief
 * Corrobora si la acción dada se cumple dentro de un periodo dado en forma de sondeo con intervalos
 * (por defaul de 1ms + el tiempo que tarde la acción en ejecutarse)
 *
 * @details
 * Corrobora si el retorno de la función a verificar es verdadero durante un tiempo dado
 * por la AccionVerificable::tiempoLimite. La verificación se realiza en forma de sondeo,
 * por defecto el tiempo entre cada verificación es de 1ms, la cantidad de verificaciones va a estar
 * condicionado al tiempo que tarde la acción en ejecutarse.
 * Ej:
 * Si la duración se configura en 200ms, el intervalo en 1ms y la acción demora 19ms en ejecutarse,
 * la verificación se realizará un máximo de 10 veces.
 *
 * Para obtener el tiempo se utiliza Chil::milisegundos() por ende debe estar inicializado para poder usar
 * este método.
 *
 * Si la acción no se corrobora se lanza AccionNoEjecutadaExcepcion
 *
 * @throw AccionNoEjecutadaExcepcion
 */
void AccionVerificable::seHayaEjecutado() {
    unsigned long tiempoInicial = PLATAFORMA->milisegundos();

    while(PLATAFORMA->milisegundos() - tiempoInicial < this->tiempoLimite){
        if(this->accionAVerificar()) {
            return;
        }
        PLATAFORMA->demorar(this->intervaloEnMilisegundos);
    }

    throw AccionNoEjecutadaExcepcion(this->tiempoLimite, this->intervaloEnMilisegundos);
}
