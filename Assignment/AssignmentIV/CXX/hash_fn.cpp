/*
   ========================================
   hash_fn.cpp — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.hpp

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */
#include "hash_fn.hpp"

int myHashInt(int key, int m) {
    // TODO: replace with your own design
    if (m <= 0) return 0;
    
    // C++ 中負數取餘數的結果可能是負數，但雜湊索引必須是非負數。
    int index = key % m;
    if (index < 0) {
        index += m;
    }
    return index;  // basic division method
}

int myHashString(const std::string& str, int m) {
    // 1. 處理邊界情況 (空字串)
    if (m <= 0 || str.empty()) {
        return 0;
    }

    // 使用 unsigned long 確保在運算過程中不會因為溢位而變成負數
    unsigned long hash_val = 5381; // 選擇一個質數作為起始種子 (seed)
    
    // 遍歷字串中的每個字元
    for (char c : str) {
        // DJB2 算法的核心：hash = hash * 33 + c
        // 透過位移 (<< 5) 加上 hash 相當於 hash * 33，這是常見的優化技巧
        hash_val = (hash_val << 5) + hash_val + c;
    }

    // 2. 最終計算索引：取餘數
    return static_cast<int>(hash_val % m);
}
