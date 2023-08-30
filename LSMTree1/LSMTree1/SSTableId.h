#pragma once
#include <string>
#include<cstdint>

struct SSTableId {
	std::string dir;
	uint64_t no;
	SSTableId() = default;
	SSTableId(const std::string& dir, uint64_t no);
	std::string name() const;
};