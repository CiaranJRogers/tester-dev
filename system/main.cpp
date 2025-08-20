

#include "pico/stdlib.h"
#include "log.hpp"
#include "engine.hpp"

static Engine engine;

int main()
{

    log_open();

    LOG_INFO("Hello world\n");


    engine.run();



    return 0;
}