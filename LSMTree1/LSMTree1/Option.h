#pragma once
#include<cstdint>

namespace Option {
   //extern const bool + 各种数据操作（压缩,块检查，块大小，跳表大小）
    extern const bool COMPRESSION;
    extern const bool COMPACTION;
    extern const bool BLOCK_CACHE;
    extern const bool TABLE_CACHE;
    extern const uint64_t SST_SPACE;
    extern const uint64_t BLOCK_SPACE;
    extern const uint64_t BLOCK_CACHE_SPACE;
    extern const uint64_t TABLE_CACHE_SIZE;
    extern const uint64_t NZ_NUM;
    extern const uint64_t Z_SPACE;
    extern const uint64_t NZ_SPACES[];
    extern const char* const Z_NAME;
    extern const char* const NZ_NAMES[];
}