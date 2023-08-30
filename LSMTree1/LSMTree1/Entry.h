#pragma once
#include<cstdint>
#include<string>
struct Entry {
	uint64_t key;
	std::string value;
	Entry(uint64_t key, const std::string& value);
};