#include "LevelZero.h"
#include "SSTableId.h"
#include "Util.h"
#include <filesystem>
#include <fstream>

SearchResult LevelZero::search(uint64_t key) const {
	for (uint64_t i = 1; i <= size; ++i) {
		SearchResult res = ssts[size - i].search(key);
		if (res.success)
			return res;
	}
	return false;
}

void LevelZero::add(const SkipList& men, uint64_t& no) {
	ssts.emplace_back(men, SSTableId(dir, no++),tablecache);
	++size;
	byteCnt += men.space();
}

void LevelZero::clear() {
	while (!ssts.empty()) {
		ssts.back().remove();
		ssts.pop_back();
	}
	size = 0;
	byteCnt = 0;
	save();
}

uint64_t LevelZero::space() const {
	return byteCnt;
}

void LevelZero::save() const {
	std::ofstream ofs(dir + "/index", std::ios::binary);
	ofs.write((char*)size,sizeof(uint64_t));
	ofs.write((char*)&byteCnt, sizeof(uint64_t));
	///
	///
}