#include <utility>
#include "HighLevelHashTable.h"

namespace cs223 {
    HighLevelHashTable::HighLevelHashTable(UniversalHashFamily& uhf, int size)
            : HashTable(uhf, size) {
        data = new LowLevelHashTable* [size];
        int lowLevelSize = size * size;
        int lowLevelSizeBits = getSizeBits(lowLevelSize);
        lowLevelSize = 1 << lowLevelSizeBits;
        for (int i = 0; i < size; i++) {
            data[i] = new LowLevelHashTable(
                    UniversalHashFamily(lowLevelSizeBits, sizeof(int)*8),
                    lowLevelSize);
        }
    }

    HighLevelHashTable::~HighLevelHashTable() {
        for (size_t i = 0; i < size; ++i) {
            delete data[i];
        }

        delete[] data;
    }

    size_t HighLevelHashTable::getSizeBits(int size) {
        size_t sizeBits = 0;
        if ((size - 1) & size) { // not power of 2?
            sizeBits = 1;
        }
        while (size >>= 1) {
            sizeBits += 1;
        }
        return sizeBits;
    }

    bool HighLevelHashTable::insertKey(int key) {
        int index = hasher->hash(key);
        return data[index]->insertKey(key);
    }

    bool HighLevelHashTable::exists(int key) {
        int index = hasher->hash(key);
        return data[index]->exists(key);
    }

    void HighLevelHashTable::deleteKey(int key) {
        int index = hasher->hash(key);
        data[index]->deleteKey(key);
    }

}
