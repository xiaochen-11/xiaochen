#pragma once
#include "location.h"
#include "SkipList.h"
#include "Entry.h"
#include"SearchResult.h"
#include "SSTableId.h"
#include "TableCache.h"
#include <string>
#include<vector>
#include<cstdint>
#include<cstddef>

class SSTable {
private:
	SSTableId id;
	uint64_t entryCnt;
	uint64_t blockCnt;
	std::vector<uint64_t> keys;
	std::vector<uint64_t> offsets;
	TableCache* tablecache;
	Location locate(uint64_t pos) const;
	uint64_t indexSpace() const;
	uint64_t blockSpace() const;
public:
	explicit SSTable(const SSTableId& id, TableCache* tablecache);
	SearchResult search(uint64_t key) const;
	//SSTable�洢���ݵ���ز���



	std::vector<Entry> load()const;
	void remove() const;
	uint64_t number() const;
	uint64_t lower() const;
	uint64_t upper() const;
	uint64_t space() const;
};