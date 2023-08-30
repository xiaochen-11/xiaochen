#pragma once
#include "Entry.h"
#include<vector>

namespace Util {
	std::vector<Entry> compact(const std::vector<std::vector<Entry>>& input);
}