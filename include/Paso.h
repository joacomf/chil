#ifndef CHIL_PASO_H
#define CHIL_PASO_H


class Paso {
  public:
      Paso(const char *nombre, void (*funcion)()) {
        this->nombre = nombre;
        this->_funcion = funcion;

        this->_funcion();
      }


private:
      const char *nombre;
      void (*_funcion)();
};

#endif
