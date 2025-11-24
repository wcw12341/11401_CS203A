/*
   ========================================
   hash_fn.c — implement your hash functions
   ========================================

   Description:
    This file contains the hash functions for integer and string keys.

   Development History:
    - 2025/11/11: Initial implementation
    - 2025/11/17: Refactored to use hash_fn.h

   Developer: Yu-Feng Huang <yfhuang@saturn.yzu.edu.tw>
 */

#include "hash_fn.h"

int myHashInt(int key, int m) {
    // 安全檢查：避免除以 0
    if (m <= 0) {
        return 0;
    }

    // 基本除法法 (Division Method)
    int index = key % m;

    // C 語言中，負數取餘數可能是負的 (例如 -5 % 3 = -2)
    // 我們必須將其調整為正數索引
    if (index < 0) {
        index += m;
    }

    return index;
}

int myHashString(const char* str, int m) {
    // 安全檢查
    if (str == NULL || m <= 0) {
        return 0;
    }

    // 使用 unsigned long 避免溢位變成負數
    // 5381 是 DJB2 演算法經典的起始種子 (Magic Number)
    unsigned long hash = 5381;
    int c;

    // 遍歷字串中的每個字元
    // *str++ 會取出當前字元，然後將指標移到下一個
    while ((c = *str++)) {
        // hash * 33 + c
        // (hash << 5) + hash 等同於 hash * 33
        hash = ((hash << 5) + hash) + c;
    }

    // 最後取餘數映射到表格大小
    return (int)(hash % m);
}
