#include <SimpleLog.h>
#include <macros.h>

int main() {
    VERBUM_INIT(FATAL);
    // FATAL
    VERBUM_FATAL("Esto es un mensaje de fatal");

    // WARNING
    VERBUM_WARNING("Esto es un mensaje de advertencia");

    // ERROR
    VERBUM_ERROR("Esto es un mensaje de error");

    // INFO
    VERBUM_INFO("Esto es un mensaje de información");

    // DEBUG
    int a = 25;
    int b = 25;
    int c = a+b;

    VERBUM_DEBUG("La suma de %d + %d = %d", a,b,c);
    
    return 0;
}
