#include <SimpleLog.h>

int main() {

    // FATAL
    SIMPLE_FATAL("Esto es un mensaje de fatal");

    // WARNING
    SIMPLE_WARNING("Esto es un mensaje de advertencia");

    // ERROR
    SIMPLE_ERROR("Esto es un mensaje de error");

    // INFO
    SIMPLE_INFO("Esto es un mensaje de información");

    // DEBUG
    int a = 25;
    int b = 25;
    int c = a+b;

    SIMPLE_DEBUG("La suma de %d + %d = %d", a,b,c);

    return 0;
}