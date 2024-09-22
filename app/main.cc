#include <iostream>
#include "config.h"
int main(int argc, char const *argv[])
{
    std::cout << "This application name is: " << __config::app_name << std::endl;
    return 0;
}
