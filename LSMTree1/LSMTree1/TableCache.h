#include "SSTableId.h"
#include <fstream>
#include <list>
#include <unordered_map>
#include <utility>
#include <cstdint>

class TableCache {
public:
	~TableCache();
	std::ifstream* open(SSTableId id);
	void close(SSTableId id);
private:
	std::list<std::pair<uint64_t, std::ifstream*>> LinkedList;
	std::unordered_map<uint64_t, std::list<std::pair<uint64_t, std::ifstream*>>::iterator> hashMap;
};