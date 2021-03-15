#include "Chil.cpp"
#include "gtest/gtest.h"
#include "mocks/MockFramework.h"

MockFramework *framework;

TEST(ChilTest, deberiaCrearseExitosamenteConElFrameworkIndicado) {
  framework = new MockFramework();
  Chil *chil = new Chil(framework);

  ASSERT_EQ(framework, chil->framework);
}