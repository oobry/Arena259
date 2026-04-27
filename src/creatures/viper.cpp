#include "viper.h"

Creature makeViper()
{
    std::string n = "Viper";
    int h = 80;
    int d = 21;
    int r = 1;
    return Creature(n, h, d, r);
}
