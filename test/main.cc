#include <Logger.hpp>
#include <iostream>
#include <cstdio>

int main() {
    Logger log(std::cerr, DEBUG);
    log.log(DEBUG, "Que se yo, estoy re duro", __FILE__, __func__, __LINE__);
    return 0;
}