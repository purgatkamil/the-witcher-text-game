#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP

#include <string>
#include "../types.hpp"

class Descriptions {
public:
    static DescriptionsMap descriptions;

    static void initialize();
    static std::string getDescription(Locations_e locationId);
};

#endif