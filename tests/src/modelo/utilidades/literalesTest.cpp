#include "compartido-tests.h"

TEST(LiteralesTest, seGeneraUnLiteralAPartirdeUnConstChar) {
    const char* frase = "Hola mundo";
    string fraseATexto = literales::aTexto(frase);
    ASSERT_EQ(fraseATexto, "Hola mundo");
}

TEST(LiteralesTest, seGeneraUnLiteralAPartirdeUnString) {
    string frase = string("Hola mundo");
    string fraseATexto = literales::aTexto(frase);
    ASSERT_EQ(fraseATexto, "Hola mundo");
}