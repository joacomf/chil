template<typename Tipo>
ValorVerificable<Tipo>::ValorVerificable(Tipo elValorAVerificar) {
    this->valorAVerificar = elValorAVerificar;
    this->estrategia = new EstrategiaDirectaConValores<Tipo>();
}

template <typename Tipo>
void ValorVerificable<Tipo>::esIgualA(Tipo elValorEsperado) {
    this->valorEsperado = elValorEsperado;
    this->estrategia->verificar(this);
}

template <typename Tipo>
Tipo ValorVerificable<Tipo>::obtenerValorEsperado() {
    return this->valorEsperado;
}

template <typename Tipo>
Tipo ValorVerificable<Tipo>::obtenerValorAVerificar() {
    return this->valorAVerificar;
}