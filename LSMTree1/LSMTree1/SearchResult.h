#pragma once
//��ѯ�ҵ����ڵ�key��ֵ
#include "Location.h"
#include <string>

struct SearchResult {
    bool success;
    Location location;
    std::string value;
    SearchResult(bool success);
    SearchResult(bool success, Location location);
};
