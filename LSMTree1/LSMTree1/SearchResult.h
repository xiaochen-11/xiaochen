#pragma once
//查询找到对于的key数值
#include "Location.h"
#include <string>

struct SearchResult {
    bool success;
    Location location;
    std::string value;
    SearchResult(bool success);
    SearchResult(bool success, Location location);
};
