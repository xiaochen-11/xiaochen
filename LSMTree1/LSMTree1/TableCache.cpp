#include "TableCache.h"
#include "Option.h"


TableCache::~TableCache() {
	//单个SStable用LinkList存储，表内依key值排序
	//同层的SStable之间用hashmap存储
}

void TableCache::close(SSTableId id) {
	if (hashMap.count(id.no)) {
		hashMap[id.no]->second->close();
		delete hashMap[id.no]->second;
		LinkedList.erase(hashMap[id.no]);
		hashMap.erase(id.no);
	}
}