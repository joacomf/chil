#ifndef CHIL_LITERALES_H
#define CHIL_LITERALES_H

#include <string>

using std::string;

namespace literales {
    template<typename T>
    string toString(const T &t) {
        return std::to_string(t);
    }

    string toString(const char* t);

    string toString(const string& t);
}



#endif //CHIL_LITERALES_H
