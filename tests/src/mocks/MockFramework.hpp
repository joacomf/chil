//
// Created by jmorenof on 12/3/21.
//
#ifndef CHIL_MOCKFRAMEWORK_HPP
#define CHIL_MOCKFRAMEWORK_HPP

#include "framework/Framework.h"
#include "gmock/gmock.h"

class MockFramework : public Framework{

  public:
    MOCK_METHOD(void, consola, (const char *nombre), (override));
};

#endif //CHIL_MOCKFRAMEWORK_HPP
