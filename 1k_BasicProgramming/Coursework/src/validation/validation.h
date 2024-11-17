#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>
#include <vector>
#include <iostream>
#include <functional>

bool custom_stoi(const std::string &str, int &out);

int get_validated_int(
    const std::string& invalidMessage="", 
    std::function<bool(int)> isValid  = [](int) { return true; }
);

#endif