#include "SkipList.h"
#include "Option.h"
#include <cstring>

SkipList::SkipList() :dist(0, 1) {
	init();
}

SkipList::~SkipList() {
	clear();
	delete head;
	delete tail;
}

void SkipList::clear() {
	for (Code* code = head; code != nullptr;) {
		Code* next = code->nexts[0];
		delete code;
		code = next;
	}
}

bool SkipList::del(uint64_t key) {
	Code* code = find(key);
	if (code == head || code->key != key)
		return false;
	size_t height = code->height;
	for (size_t lvl = 0; lvl < height; ++lvl) {
		code->prevs[lvl]->nexts[lvl] = code->nexts[lvl];
		code->nexts[lvl]->prevs[lvl] = code -> prevs[lvl];
	}
	totalBytes-=code->value.size();
	delete code;
	return true;
}
std::string SkipList::get(uint64_t key) const {
	Code* code = find(key);
	return code != head && code->key == key ? code->value : "";
}