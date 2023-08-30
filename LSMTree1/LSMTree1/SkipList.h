#pragma once
#include"Entry.h"
#include<random>
#include<cstdint>
#include<utility>
#include<cstddef>
#include<string>


class SkipList {
public:
	explicit SkipList();
	~SkipList();
	class Iterator;
	//跳表的数据存入、输出、删除、更新函数声明
	std::string get(uint64_t key)const;
	void put(uint64_t key, const std::string& value);
	bool del(uint64_t key);
	//接口函数定义
	Iterator iterator() const;
	size_t size();
	bool empty()const;
	void clear();
	uint64_t space() const;
private:
	struct  Code;
	Code* head, * tail;
	size_t totalBytes;
	std::default_random_engine engine;
	std::uniform_int_distribution<int> dist;
	void init();
	Code* find(uint64_t key) const;
	void enlargeHeight(size_t height);

};
struct SkipList::Code {
	uint64_t key;
	std::string value;
	Code** prevs;
	Code** nexts;
	size_t height;
};

class SkipList::Iterator {
public:
	Entry next();
	bool hasnext() const;
private:
	Code* code;
	Iterator(Code* code);
	friend SkipList;
};