#include"SSTable.h"
#include "Util.h"
#include "Option.h"
#include<fstream>
#include<filesystem>

SSTable::SSTable(const SSTableId& id, TableCache* tablecache)
	:id(id), tablecache(tablecache) {
	std::ifstream ifs(id.name(), std::ios::binary);
	ifs.read((char*)&entryCnt, sizeof(uint64_t));
	for (uint64_t i = 0; i <= entryCnt; ++i) {
		uint64_t key, offset;
		ifs.read((char*)&key, sizeof(uint64_t));
		ifs.read((char*)&offset, sizeof(uint64_t));
		keys.push_back(key);
		offsets.push_back(offset);
	}
	//每个SStable块存储
	ifs.close();
}

//SSTable 组织数据的相关操作






//二分法查找数据
SearchResult SSTable::search(uint64_t key) const {
	uint64_t left;
	uint64_t right = entryCnt;
	while (right >left ) {
		uint64_t mid = left + (right - left) / 2;
		if (keys[mid] < key)
			left = mid;
		else if (keys[mid] > key)
			right = mid;
		else
			return { true, locate(mid) };
	}
}

//SSTable加载entry数值
std::vector<Entry> SSTable::load() const {
	std::vector<Entry> entries;
		uint64_t  k = 0;
		uint64_t key;
		std::string value;
		///
		entries.emplace_back(key, value);
		return entries;
}

void SSTable::remove() const {
	if (Option::TABLE_CACHE)
		tablecache->close(id);
	 
}

uint64_t SSTable::number() const {
	return id.no;
}