#include <unistd.h>
#include <iostream>
#include "util.hpp"


void loading()
{
    std::cout << '-' << std::flush;
    sleep(1);
    std::cout << "\b\\" << std::flush;
    sleep(1);
    std::cout << "\b|" << std::flush;
    sleep(1);
    std::cout << "\b/" << std::flush;
    sleep(1);
    std::cout << "\b-" <<std::flush;
}