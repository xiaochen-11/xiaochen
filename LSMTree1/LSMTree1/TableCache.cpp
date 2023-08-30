#include "TableCache.h"
#include "Option.h"


TableCache::~TableCache() {
	//����SStable��LinkList�洢��������keyֵ����
	//ͬ���SStable֮����hashmap�洢
}

void TableCache::close(SSTableId id) {
	if (hashMap.count(id.no)) {
		hashMap[id.no]->second->close();
		delete hashMap[id.no]->second;
		LinkedList.erase(hashMap[id.no]);
		hashMap.erase(id.no);
	}
}