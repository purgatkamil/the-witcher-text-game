#pragma once

#include <string>
#include <iostream>

struct SpecialAbility
{
    std::string name;
    std::string description;

    SpecialAbility(const std::string& n = "",
                   const std::string& desc = "")
      : name(n), description(desc) 
    {}

    void useAbility(const std::string& userName) const
    {
        std::cout << userName << " uses special ability: " 
                  << name << "!\n"
                  << "Description: " << description << std::endl;
    }
};
